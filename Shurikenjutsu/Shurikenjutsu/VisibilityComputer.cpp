#include "VisibilityComputer.h"
#include "InputManager.h"
#include "Globals.h"

#include "ConsoleFunctions.h"
#include <D3Dcompiler.h>
#include "TextureLibrary.h"

VisibilityComputer& VisibilityComputer::GetInstance()
{
	static VisibilityComputer instance;

	return instance;
}

bool VisibilityComputer::Initialize(ID3D11Device* p_device)
{
	m_lastPosition = Point(0.0f, 0.0f);

	m_intersections.clear();
	m_vertices.clear();

	DirectX::XMStoreFloat4x4(&m_polygonWorldMatrix, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_polygonViewMatrix, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_polygonProjectionMatrix, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_quadWorldMatrix, DirectX::XMMatrixIdentity());

	m_mesh = nullptr;
	m_quadMesh = nullptr;

	m_boundingBox = BoundingShape(Point(0.0f, 0.0f), Point(0.0f, 0.0f));

	// Set variables to initial values.
	ID3D10Blob*	vertexShader = 0;
	ID3D10Blob*	errorMessage = 0;

	// Compile the vertex shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/ShadowShapes/SSVertexShader.hlsl", NULL, NULL, "main", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/ShadowShapes/SSVertexShader.hlsl", NULL, NULL, "main", "vs_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile shadow shapes vertex shader from file.");
			return false;
		}

		else
		{
			m_VSVersion = "4.0";
		}
	}

	else
	{
		m_VSVersion = "5.0";
	}

	// Create the vertex shader.
	if (FAILED(p_device->CreateVertexShader(vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), NULL, &m_vertexShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create shadow shapes vertex shader.");
		return false;
	}

	// Configure vertex layout.
	D3D11_INPUT_ELEMENT_DESC layout[1];
	unsigned int size;

	layout[0].SemanticName = "POSITION";
	layout[0].SemanticIndex = 0;
	layout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	layout[0].InputSlot = 0;
	layout[0].AlignedByteOffset = 0;
	layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	layout[0].InstanceDataStepRate = 0;

	// Compute size of layout.
	size = sizeof(layout) / sizeof(layout[0]);

	// Create the vertex input layout.
	if (FAILED(p_device->CreateInputLayout(layout, size, vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), &m_layout)))
	{
		ConsolePrintErrorAndQuit("Failed to create shadow shapes vertex input layout.");
		return false;
	}

	ConsolePrintSuccess("Shadow shapes vertex shader compiled successfully.");
	ConsolePrintText("Shader version: VS " + m_VSVersion);

	// Release useless local shaders.
	vertexShader->Release();
	vertexShader = 0;

	// Set variables to initial values.
	ID3D10Blob*	pixelShader = 0;
	errorMessage = 0;

	// Compile the pixel shader.
	if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/ShadowShapes/SSPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
	{
		if (FAILED(D3DCompileFromFile(L"../Shurikenjutsu/Shaders/ShadowShapes/SSPixelShader.hlsl", NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, "main", "ps_4_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShader, &errorMessage)))
		{
			ConsolePrintErrorAndQuit("Failed to compile shadow shapes pixel shader from file.");
			return false;
		}

		else
		{
			m_PSVersion = "4.0";
		}
	}

	else
	{
		m_PSVersion = "5.0";
	}

	// Create the pixel shader.
	if (FAILED(p_device->CreatePixelShader(pixelShader->GetBufferPointer(), pixelShader->GetBufferSize(), NULL, &m_pixelShader)))
	{
		ConsolePrintErrorAndQuit("Failed to create shadow shapes pixel shader");
		return false;
	}

	ConsolePrintSuccess("Shadow shapes pixel shader compiled successfully.");
	ConsolePrintText("Shader version: PS " + m_PSVersion);

	// Release useless local variables.
	pixelShader->Release();
	pixelShader = 0;

	// Create the matrix buffer description.
	D3D11_BUFFER_DESC matrixBuffer;
	matrixBuffer.Usage = D3D11_USAGE_DYNAMIC;
	matrixBuffer.ByteWidth = sizeof(MatrixBuffer);
	matrixBuffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBuffer.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBuffer.MiscFlags = 0;
	matrixBuffer.StructureByteStride = 0;

	// Create the matrix buffer.
	if (FAILED(p_device->CreateBuffer(&matrixBuffer, NULL, &m_matrixBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to create shadow shapes matrix buffer.");
		return false;
	}

	UpdateMapBoundries(Point(-1.0f, 1.0f), Point(1.0f, -1.0f));
	m_renderTarget.Initialize(GraphicsEngine::GetInstance()->GetDevice(), GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT);
	m_minimapTarget.Initialize(GraphicsEngine::GetInstance()->GetDevice(), GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH, GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT);
	RebuildQuad(Point(-45.0f, 52.0f), Point(45.0f, -52.0f));

	ConsolePrintSuccess("Visibility computer initialized successfully.");
	ConsoleSkipLines(1);

	return true;
}

void VisibilityComputer::Shutdown()
{
	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}

	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	if (m_layout)
	{
		m_layout->Release();
		m_layout = 0;
	}

	if (m_mesh)
	{
		m_mesh->Release();
		m_mesh = 0;
	}

	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = 0;
	}

	if (m_texture)
	{
		m_texture->Release();
		m_texture = 0;
	}

	m_renderTarget.Shutdown();
	m_minimapTarget.Shutdown();
}

void VisibilityComputer::UpdateVisibilityPolygon(Point p_viewerPosition, ID3D11Device* p_device)
{
	m_lastPosition = p_viewerPosition;

	m_intersections.clear();
	std::vector<PolygonPoint> totalIntersections;

	std::vector<float> uniqueAngles = GetUniquePointAngles(p_viewerPosition);
	std::vector<Line> segments = ShadowShapes::GetInstance().GetStaticLines(m_boundingBox.m_topLeft, m_boundingBox.m_bottomRight);
	PolygonPoint polygonPoint = PolygonPoint();

	for (unsigned int i = 0; i < uniqueAngles.size(); i++)
	{
		// Get current angle.
		float angle = uniqueAngles[i];

		// Calculate the dx and dy from current angle.
		float dx = cos(angle);
		float dy = sin(angle);

		// Cast a ray in that angle.
		Line ray = Line(Point(p_viewerPosition.x, p_viewerPosition.y), Point(p_viewerPosition.x + dx, p_viewerPosition.y + dy));

		Intersection closestIntersection = Intersection();

		// Find the closest intersection in segments.
		for (unsigned int j = 0; j < segments.size(); j++)
		{
			Intersection intersection = GetIntertersectionPoint(ray, segments[j]);

			// Ignore if there is no collision.
			if (intersection.intersection)
			{
				// Sort to closest T1 value.
				if (!closestIntersection.intersection || intersection.T1 < closestIntersection.T1)
				{
					closestIntersection = intersection;
				}
			}
		}

		// Check to make sure the closest intersection even hit.
		if (closestIntersection.intersection)
		{
			// Point and angle.
			polygonPoint = PolygonPoint(angle, closestIntersection.point);

			// Add to list of intersects
			totalIntersections.push_back(polygonPoint);
		}
	}

	// Sort intersections by angle.
	QuickSortAngles(totalIntersections);

	// Add sorted intersections to list.
	for (unsigned int i = 0; i < totalIntersections.size(); i++)
	{
		m_intersections.push_back(totalIntersections[i].m_point);
	}

	// Calculate the polyogn.
	CalculateVisibilityPolygon(p_viewerPosition, p_device);

	// Reverse the polygon.
	CalculateReversedVisibilityPolygon(GraphicsEngine::GetInstance()->GetContext());
}

void VisibilityComputer::CalculateVisibilityPolygon(Point p_viewerPosition, ID3D11Device* p_device)
{
	m_vertices.clear();

	// All but the last polygon can be made by this loop.
	for (unsigned int i = 0; i < m_intersections.size() - 1; i++)
	{
		m_vertices.push_back(DirectX::XMFLOAT3(p_viewerPosition.x, 0.2f, p_viewerPosition.y));
		m_vertices.push_back(DirectX::XMFLOAT3(m_intersections[i].x, 0.2f, m_intersections[i].y));
		m_vertices.push_back(DirectX::XMFLOAT3(m_intersections[i + 1].x, 0.2f, m_intersections[i + 1].y));
	}

	// Last polygon is constructed from the last and the first list element.
	m_vertices.push_back(DirectX::XMFLOAT3(p_viewerPosition.x, 0.2f, p_viewerPosition.y));
	m_vertices.push_back(DirectX::XMFLOAT3(m_intersections[m_intersections.size() - 1].x, 0.2f, m_intersections[m_intersections.size() - 1].y));
	m_vertices.push_back(DirectX::XMFLOAT3(m_intersections[0].x, 0.2f, m_intersections[0].y));

	if (m_mesh)
	{ 
		m_mesh->Release();
		m_mesh = 0;
	}
		
	// Setup vertex buffer description.
	D3D11_BUFFER_DESC vertexBuffer;
	vertexBuffer.Usage = D3D11_USAGE_DEFAULT;
	vertexBuffer.ByteWidth = sizeof(DirectX::XMFLOAT3) * m_vertices.size();
	vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBuffer.CPUAccessFlags = 0;
	vertexBuffer.MiscFlags = 0;
	vertexBuffer.StructureByteStride = 0;

	// Setup vertex buffer data.
	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = m_vertices.data();
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	p_device->CreateBuffer(&vertexBuffer, &vertexData, &m_mesh);
}

void VisibilityComputer::CalculateReversedVisibilityPolygon(ID3D11DeviceContext* p_context)
{
	float color[4] = { 0.0f, 0.0f, 0.0f, 0.5f };
	m_minimapTarget.SetAsRenderTarget(p_context);
	m_minimapTarget.Clear(p_context, color);

	UpdatePolygonMatrices(p_context);

	// Set parameters and then render the unreversed polygon.
	unsigned int stride = sizeof(DirectX::XMFLOAT3);
	const unsigned int offset = 0;

	p_context->VSSetShader(m_vertexShader, NULL, 0);
	p_context->PSSetShader(m_pixelShader, NULL, 0);

	p_context->IASetVertexBuffers(0, 1, &m_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);

	p_context->Draw(m_vertices.size(), 0);

	GraphicsEngine::GetInstance()->ResetRenderTarget();

	color[3] = 0.5f;
	m_renderTarget.SetAsRenderTarget(p_context);
	m_renderTarget.Clear(p_context, color);

	p_context->IASetVertexBuffers(0, 1, &m_mesh, &stride, &offset);
	p_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	p_context->IASetInputLayout(m_layout);

	p_context->Draw(m_vertices.size(), 0);

	GraphicsEngine::GetInstance()->ResetRenderTarget();
}

Intersection VisibilityComputer::GetIntertersectionPoint(Line p_ray, Line p_segment)
{
	// Set point to false initially.
	Intersection point;
	point.intersection = false;
	point.point = Point(0.0f, 0.0f);
	point.T1 = 0.0f;

	// Compute the ray in parametric form.
	Point rayPoint = Point(p_ray.a.x, p_ray.a.y);
	Point rayDirection = Point(p_ray.b.x - p_ray.a.x, p_ray.b.y - p_ray.a.y);

	// Compute the segment in parametric form.
	Point segmentPoint = Point(p_segment.a.x, p_segment.a.y);
	Point segmentDirection = Point(p_segment.b.x - p_segment.a.x, p_segment.b.y - p_segment.a.y);

	// Calculate length of both lines.
	float rayLength = sqrt(rayDirection.x * rayDirection.x + rayDirection.y * rayDirection.y);
	float segmentLength = sqrt(segmentDirection.x * segmentDirection.x + segmentDirection.y * segmentDirection.y);

	// If the lines are parallel, there is no intersection.
	if (rayDirection.x / rayLength == segmentDirection.x / segmentLength && rayDirection.y / rayLength == segmentDirection.y / segmentLength)
	{
		// Unit vectors are the same and the lines are parallel, return false.
		return point;
	}

	// Solve T1 and T2.
	float T2 = (rayDirection.x * (segmentPoint.y - rayPoint.y) + rayDirection.y * (rayPoint.x - segmentPoint.x)) / (segmentDirection.x * rayDirection.y - segmentDirection.y * rayDirection.x);
	float T1 = (segmentPoint.x + segmentDirection.x * T2 - rayPoint.x) / rayDirection.x;

	// Make sure T1 and T2 < 0 and that T2 > 1. If not, the supposed intersection is not on the ray or segment.
	if (T1 < 0)
	{
		return point;
	}

	if (T2 < 0 || T2 > 1)
	{
		return point;
	}

	// Otherwise, we have an intersection!
	point.intersection = true;
	point.point = Point(rayPoint.x + rayDirection.x * T1, rayPoint.y + rayDirection.y * T1);
	point.T1 = T1;
	return point;
}

inline std::vector<float> VisibilityComputer::GetUniquePointAngles(Point p_viewerPoint)
{
	std::vector<float> angles;
	std::vector<Point> list = ShadowShapes::GetInstance().GetUniquePoints(m_boundingBox.m_topLeft, m_boundingBox.m_bottomRight);

	// Get the angles to all of the unique points.
	for (unsigned int i = 0; i < list.size(); i++)
	{
		Point uniquePoint = list[i];

		float angle = atan2(uniquePoint.y - p_viewerPoint.y, uniquePoint.x - p_viewerPoint.x);

		// Add the angle, plus two offset angles. This is to hit things next to corners.
		angles.push_back(angle - 0.00001f);
		angles.push_back(angle);
		angles.push_back(angle + 0.00001f);
	}

	return angles;
}

void VisibilityComputer::RenderVisibilityPolygon(ID3D11DeviceContext* p_context)
{
	GraphicsEngine::GetInstance()->TurnOnAlphaBlending();

	if (!m_texture)
	{
		m_texture = TextureLibrary::GetInstance()->GetTexture((std::string)"../Shurikenjutsu/2DTextures/shadowstuff.png");
	}

	// Render the quad to reverse project the polygon onto.
	GraphicsEngine::GetInstance()->RenderReversedShadows(m_quadMesh, 6, m_renderTarget.GetRenderTarget(), m_texture);

	GraphicsEngine::GetInstance()->TurnOffAlphaBlending();
}

void VisibilityComputer::UpdatePolygonMatrices(ID3D11DeviceContext* p_context)
{
	DirectX::XMFLOAT4X4 worldMatrix = m_polygonWorldMatrix;
	DirectX::XMFLOAT4X4 viewMatrix = m_polygonViewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix = m_polygonProjectionMatrix;

	// Transpose the matrices.
	DirectX::XMStoreFloat4x4(&worldMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&worldMatrix)));
	DirectX::XMStoreFloat4x4(&viewMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&viewMatrix)));
	DirectX::XMStoreFloat4x4(&projectionMatrix, DirectX::XMMatrixTranspose(DirectX::XMLoadFloat4x4(&projectionMatrix)));

	// Lock matrix buffer so that it can be written to.
	D3D11_MAPPED_SUBRESOURCE mappedBuffer;
	if (FAILED(p_context->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer)))
	{
		ConsolePrintErrorAndQuit("Failed to map shadow shapes matrix buffer.");
		return;
	}

	// Get pointer to the matrix buffer data.
	MatrixBuffer* matrixBuffer = (MatrixBuffer*)mappedBuffer.pData;

	// Set matrices in buffer.
	matrixBuffer->m_worldMatrix = DirectX::XMLoadFloat4x4(&worldMatrix);
	matrixBuffer->m_viewMatrix = DirectX::XMLoadFloat4x4(&viewMatrix);
	matrixBuffer->m_projectionMatrix = DirectX::XMLoadFloat4x4(&projectionMatrix);

	// Unlock the matrix buffer after it has been written to.
	p_context->Unmap(m_matrixBuffer, 0);

	// Set the matrix buffer.
	p_context->VSSetConstantBuffers(0, 1, &m_matrixBuffer);
}

bool VisibilityComputer::IsPointVisible(Point p_point)
{
	return IsPointInPolygon(p_point, m_intersections);
}

bool VisibilityComputer::IsPointInPolygon(Point p_point, std::vector<Point> p_polygon)
{
	int intersections = 0;

	// Generate a ray just going right.
	Line ray = Line(Point(p_point.x, p_point.y), Point(p_point.x + 1.0f, p_point.y));

	// Get number of total intersections with polygon segments.
	for (unsigned int i = 0; i < p_polygon.size(); i++)
	{
		// Line from this point to the next
		Point startPoint = p_polygon[i];
		Point endPoint = (i == p_polygon.size() - 1) ? p_polygon[0] : p_polygon[i + 1];

		Line segment = Line(Point(startPoint.x, startPoint.y), Point(endPoint.x, endPoint.y)); 

		if (GetIntertersectionPoint(ray, segment).intersection)
		{
			intersections++;
		}
	}

	// If and only if it is odd, the point is inside the visibility polygon.
	return (intersections % 2 == 1);
}

void VisibilityComputer::UpdateMapBoundries(Point p_topLeft, Point p_bottomRight)
{
	ShadowShapes::GetInstance().UpdateBoundries(p_topLeft, p_bottomRight);

	m_boundingBox.m_topLeft = p_topLeft;
	m_boundingBox.m_bottomRight = p_bottomRight;
}

void VisibilityComputer::QuickSortAngles(std::vector<PolygonPoint>& p_list)
{
	QuickSortAngles(p_list, 0, p_list.size() - 1);
}

void VisibilityComputer::QuickSortAngles(std::vector<PolygonPoint>& p_list, int p_left, int p_right)
{
	int i = p_left;
	int j = p_right;

	PolygonPoint pivot = p_list[(p_left + p_right) / 2];

	// Partition.
	while(i <= j) 
	{
		while (p_list[i].m_angle > pivot.m_angle)
		{
			i++;
		}

		while (p_list[j].m_angle < pivot.m_angle)
		{
			j--;
		}

		if (i <= j) 
		{
			std::swap(p_list[i], p_list[j]);

			i++;
			j--;
		}
	}

	// Recursion.
	if (p_left < j)
	{
		QuickSortAngles(p_list, p_left, j);
	}

	if (i < p_right)
	{
		QuickSortAngles(p_list, i, p_right);
	}
}

void VisibilityComputer::UpdateTextureSize(int p_width, int p_height)
{
	m_renderTarget.Shutdown();
	m_renderTarget.Initialize(GraphicsEngine::GetInstance()->GetDevice(), p_width, p_height);

	m_minimapTarget.Shutdown();
	m_minimapTarget.Initialize(GraphicsEngine::GetInstance()->GetDevice(), p_width, p_height);
}

void VisibilityComputer::RebuildQuad(Point p_topLeft, Point p_bottomRight)
{
	// Reset the mesh.
	if (m_quadMesh)
	{
		m_quadMesh->Release();
		m_quadMesh = 0;
	}

	// Top triangle.
	Vertex mesh[6];
	mesh[0] = Vertex(DirectX::XMFLOAT3(p_topLeft.x, 0.1f, p_topLeft.y), DirectX::XMFLOAT2(0.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
	mesh[1] = Vertex(DirectX::XMFLOAT3(p_bottomRight.x, 0.1f, p_topLeft.y), DirectX::XMFLOAT2(1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));
	mesh[2] = Vertex(DirectX::XMFLOAT3(p_topLeft.x, 0.1f, p_bottomRight.y), DirectX::XMFLOAT2(0.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));

	// Bottom triangle.
	mesh[3] = mesh[2];
	mesh[4] = mesh[1];
	mesh[5] = Vertex(DirectX::XMFLOAT3(p_bottomRight.x, 0.1f, p_bottomRight.y), DirectX::XMFLOAT2(1.0f, 1.0f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f));

	// Setup vertex buffer description.
	D3D11_BUFFER_DESC vertexBuffer;
	vertexBuffer.Usage = D3D11_USAGE_DEFAULT;
	vertexBuffer.ByteWidth = sizeof(Vertex) * 6;
	vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBuffer.CPUAccessFlags = 0;
	vertexBuffer.MiscFlags = 0;
	vertexBuffer.StructureByteStride = 0;

	// Setup vertex buffer data.
	D3D11_SUBRESOURCE_DATA vertexData;
	vertexData.pSysMem = mesh;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Create the vertex buffer.
	GraphicsEngine::GetInstance()->GetDevice()->CreateBuffer(&vertexBuffer, &vertexData, &m_quadMesh);
}

void VisibilityComputer::SetWorldPolygonMatrix(DirectX::XMFLOAT4X4 p_worldMatrix)
{
	m_polygonWorldMatrix = p_worldMatrix;
}

void VisibilityComputer::SetViewPolygonMatrix(DirectX::XMFLOAT4X4 p_viewMatrix)
{
	m_polygonViewMatrix = p_viewMatrix;
}

void VisibilityComputer::SetProjectionPolygonMatrix(DirectX::XMFLOAT4X4 p_projectionMatrix)
{
	m_polygonProjectionMatrix = p_projectionMatrix;
}

DirectX::XMFLOAT4X4 VisibilityComputer::GetWorldPolygonMatrix()
{
	return m_polygonWorldMatrix;
}

DirectX::XMFLOAT4X4 VisibilityComputer::GetViewPolygonMatrix()
{
	return m_polygonViewMatrix;
}

DirectX::XMFLOAT4X4 VisibilityComputer::GetProjectionPolygonMatrix()
{
	return m_polygonProjectionMatrix;
}

ID3D11ShaderResourceView* VisibilityComputer::GetRenderTarget()
{
	return m_renderTarget.GetRenderTarget();
}

ID3D11ShaderResourceView* VisibilityComputer::GetMinimapTarget()
{
	return m_minimapTarget.GetRenderTarget();
}

Point VisibilityComputer::GetLastPosition()
{
	return m_lastPosition;
}