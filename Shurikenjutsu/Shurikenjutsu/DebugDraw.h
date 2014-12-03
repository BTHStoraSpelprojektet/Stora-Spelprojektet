#ifndef DEBUGDRAW
#define DEBUGDRAW

#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>

#include "Buffer.h"
#include "GraphicsEngine.h"

#include "DebugBox.h"
#include "DebugLineList.h"
#include "DebugRectangle.h"
#include "DebugShape2D.h"
#include "DebugShape3D.h"
#include "DebugCircle.h"
#include "DebugDot.h"

class DebugDraw
{
public:
	static DebugDraw& GetInstance();

	// Basic.
	void RenderSingleLine(DirectX::XMFLOAT3 p_startPoint, DirectX::XMFLOAT3 p_endPoint, DirectX::XMFLOAT3 p_color);

private:
	DebugDraw() {};
	DebugDraw(DebugDraw const&);
	void operator=(DebugDraw const&);
};
#endif