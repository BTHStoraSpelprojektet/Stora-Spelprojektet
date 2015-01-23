#include "ShadowShapes.h"

ShadowShapes& ShadowShapes::GetInstance()
{
	static ShadowShapes instance;

	return instance;
}

bool ShadowShapes::Initialize()
{

}

void ShadowShapes::Shutdown()
{

}

void ShadowShapes::AddStaticLine(Line p_line)
{

}

void ShadowShapes::AddStaticShape(std::vector<Line> p_shape)
{

}

int ShadowShapes::AddDynamicLine(Line p_line)
{

}

int ShadowShapes::AddDynamicShape(std::vector<Line> p_shape)
{

}

void ShadowShapes::RemoveDynamicLine(int p_atIndex)
{

}

void ShadowShapes::RemoveDynamicShape(int p_atIndex, int p_numberOfLines)
{

}

std::vector<Line> ShadowShapes::GetStaticLines()
{

}

std::vector<Line> ShadowShapes::GetDynamicLines()
{

}

void ShadowShapes::DebugRender()
{

}