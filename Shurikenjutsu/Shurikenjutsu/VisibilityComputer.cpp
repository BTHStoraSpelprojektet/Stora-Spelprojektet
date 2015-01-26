#include "VisibilityComputer.h"
#include "InputManager.h"

VisibilityComputer& VisibilityComputer::GetInstance()
{
	static VisibilityComputer instance;

	return instance;
}

bool VisibilityComputer::Initialize()
{
	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
	m_mesh = nullptr;
	m_vertices = 0;

	return true;
}

void VisibilityComputer::Shutdown()
{
	if (m_mesh)
	{
		m_mesh->Release();
		m_mesh = 0;
	}
}

void VisibilityComputer::UpdateVisibilityPolygon(Point p_viewerPosition, Point p_picked)
{
	Point center = p_viewerPosition;

	// TODO, all the shit here.

	m_dot.Shutdown();

	std::vector<Intersection> intersects;

	for (unsigned int i = 0; i < ShadowShapes::GetInstance().GetStaticLines().size(); i++)
	{
		Intersection intersection = GetIntertersectionPoint(Line(p_viewerPosition, Point(p_picked.x, p_picked.y)), ShadowShapes::GetInstance().GetStaticLines()[i]);
		if (intersection.intersection == true)
		{
			intersects.push_back(intersection);
		}
	}

	float T = 10000.0f;
	int index = -1;

	for (unsigned int i = 0; i < intersects.size(); i++)
	{
		if (intersects[i].T1 < T)
		{
			T = intersects[i].T1;
			index = i;
		}
	}

	if (index >= 0)
	{
		m_dot.Initialize(DirectX::XMFLOAT3(intersects[index].point.x, 0.2f, intersects[index].point.y), 21, DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f));
	}
	
	DebugDraw::GetInstance().RenderSingleLine(DirectX::XMFLOAT3(p_viewerPosition.x, 0.2f, p_viewerPosition.y), DirectX::XMFLOAT3(p_picked.x, 0.2f, p_picked.y), DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
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

void VisibilityComputer::CalculateReversedVisibilityPolygon()
{
	// TODO, reverse the polygon? how?
}

void VisibilityComputer::RenderVisibilityPolygon()
{
	m_dot.Render();
}

void VisibilityComputer::RenderReversedVisibilityPolygon()
{
	// TODO, render reversed.
}

bool VisibilityComputer::IsPointVisible(Point p_point)
{
	bool isVisible = true;

	return isVisible;
}