#include "VisibilityComputer.h"
#include "InputManager.h"

VisibilityComputer& VisibilityComputer::GetInstance()
{
	static VisibilityComputer instance;

	return instance;
}

bool VisibilityComputer::Initialize()
{
	m_intersections.clear();

	DirectX::XMStoreFloat4x4(&m_worldMatrix, DirectX::XMMatrixIdentity());
	m_mesh = nullptr;
	m_vertices = 0;

	m_boundingBox = BoundingShape(Point(0.0f, 0.0f), Point(0.0f, 0.0f));

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

void VisibilityComputer::UpdateVisibilityPolygon(Point p_viewerPosition)
{
	Point center = p_viewerPosition;

	if (p_viewerPosition.x > m_boundingBox.m_topLeft.x && p_viewerPosition.x < m_boundingBox.m_bottomRight.x && p_viewerPosition.y < m_boundingBox.m_topLeft.y && p_viewerPosition.y > m_boundingBox.m_bottomRight.y)
	{
		m_intersections.clear();

		std::vector<PolygonPoint> totalIntersections;
		std::vector<float> uniqueAngles = GetUniquePointAngles(p_viewerPosition);
		std::vector<Line> segments = ShadowShapes::GetInstance().GetStaticLines();
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

			// Find the closest intersection.
			Intersection closestIntersection = Intersection();
			for (unsigned int j = 0; j < segments.size(); j++)
			{
				Intersection intersection = GetIntertersectionPoint(ray, segments[j]);

				// Ignore if there is no collision.
				if (!intersection.intersection)
				{
					continue;
				}

				// Sort to closest T1 value.
				if (!closestIntersection.intersection || intersection.T1 < closestIntersection.T1)
				{
					closestIntersection = intersection;
				}
			}

			// Check to make sure the closest intersection even hit.
			if (!closestIntersection.intersection)
			{
				continue;
			}

			// Point and angle.
			polygonPoint = PolygonPoint(angle, closestIntersection.point);

			// Add to list of intersects
			totalIntersections.push_back(polygonPoint);
		}

		// Sort intersections by angle.
		// TODO, ^.

		// Add sorted intersections to list.
		for (unsigned int i = 0; i < totalIntersections.size(); i++)
		{
			m_intersections.push_back(totalIntersections[i].m_point);
		}

		// Calculate the polyogn.
		CalculateVisibilityPolygon();

		// Reverse the polygon.
		CalculateReversedVisibilityPolygon();
	}
}

void VisibilityComputer::CalculateVisibilityPolygon()
{
	// TODO, the polygon.
}

void VisibilityComputer::CalculateReversedVisibilityPolygon()
{
	// TODO, reverse the polygon? how?
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

	// Get the angles to all of the unique points.
	for (unsigned int i = 0; i < ShadowShapes::GetInstance().GetUniquePoints().size(); i++)
	{
		Point uniquePoint = ShadowShapes::GetInstance().GetUniquePoints()[i];

		float angle = atan2(uniquePoint.y - p_viewerPoint.y, uniquePoint.x - p_viewerPoint.x);

		// Add the angle, plus two offset angles. This is to hit things next to corners.
		angles.push_back(angle - 0.00001f);
		angles.push_back(angle);
		angles.push_back(angle + 0.00001f);
	}

	return angles;
}

void VisibilityComputer::RenderVisibilityPolygon()
{
	// TODO, render unreversed.
}

void VisibilityComputer::RenderReversedVisibilityPolygon()
{
	// TODO, render reversed.
}

bool VisibilityComputer::IsPointVisible(Point p_point)
{
	bool isVisible = true;

	// TODO, check if point is visible in any of the polygons in the list.

	return isVisible;
}

void VisibilityComputer::SetBoundryBox(Point p_topLeft, Point p_bottomRight)
{
	m_boundingBox.m_topLeft = p_topLeft;
	m_boundingBox.m_bottomRight = p_bottomRight;
}

std::vector<PolygonPoint> VisibilityComputer::QuickSortAngles(std::vector<PolygonPoint> p_list, int p_left, int p_right)
{
	int i = p_left;
	int j = p_right;

	PolygonPoint temp;
	PolygonPoint pivot = p_list[(p_left + p_right) / 2];

	// Partition.
	while(i <= j) 
	{
		while (p_list[i].m_angle < pivot.m_angle)
		{
			i++;
		}

		while (p_list[j].m_angle > pivot.m_angle)
		{
			j--;
		}

		if (i <= j) 
		{
			temp = p_list[i];
			p_list[i] = p_list[j];
			p_list[j] = temp;

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

	return p_list;
}