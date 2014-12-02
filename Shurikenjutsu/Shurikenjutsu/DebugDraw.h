#ifndef DEBUGDRAW
#define DEBUGDRAW

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Buffer.h"
#include "GraphicsEngine.h"

class DebugDraw
{
public:
	static DebugDraw& GetInstance();

	// 2D.
	void RenderLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint);
	void RenderRectangle(DirectX::XMFLOAT3 p_centrum, float p_width, float p_height);
	void RenderGenericShape(std::vector<DirectX::XMFLOAT3> p_shape);

	// 3D.

private:
	DebugDraw() {};
	DebugDraw(DebugDraw const&);
	void operator=(DebugDraw const&);
};
#endif