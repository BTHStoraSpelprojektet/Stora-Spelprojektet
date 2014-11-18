#include "Buffer.h"

ID3D11Buffer* Buffer::CreateBuffer(BUFFERTYPE P_type, ID3D11Device* p_device, std::vector<Vertex> p_mesh)
{
	ID3D11Buffer* buffer = NULL;

	switch (P_type)
	{
		case (BUFFERTYPE_VERTEX) :
		{
			// Setup vertex buffer description.
			D3D11_BUFFER_DESC vertexBuffer;
			vertexBuffer.Usage = D3D11_USAGE_DEFAULT;
			vertexBuffer.ByteWidth = sizeof(Vertex) * p_mesh.size();
			vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBuffer.CPUAccessFlags = 0;
			vertexBuffer.MiscFlags = 0;
			vertexBuffer.StructureByteStride = 0;

			// Setup vertex buffer data.
			D3D11_SUBRESOURCE_DATA vertexData;
			vertexData.pSysMem = p_mesh.data();
			vertexData.SysMemPitch = 0;
			vertexData.SysMemSlicePitch = 0;

			// Create the vertex buffer.
			p_device->CreateBuffer(&vertexBuffer, &vertexData, &buffer);

			break;
		}
		
		default:
		{
			ConsolePrintError("Invalid buffer type passed to CreateBuffer().");
			break;
		}
	}

	if (!buffer)
	{
		ConsolePrintError("Failed to create buffer.");
		return NULL;
	}

	return buffer;
}