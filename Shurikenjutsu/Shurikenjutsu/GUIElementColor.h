#ifndef GUIELEMENTCOLOR_H_
#define GUIELEMENTCOLOR_H_

#include <DirectXMath.h>
#include "GUIManager.h"

class GUIElementColor
{
public:
	GUIElementColor();
	~GUIElementColor();

	bool Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, DirectX::XMFLOAT4 p_color);

	void QueueRender();

	DirectX::XMFLOAT4X4 GetWorldMatrix()const;

	DirectX::XMFLOAT4 GetColor()const;
	void SetColor(DirectX::XMFLOAT4 p_color);

	DirectX::XMFLOAT2 GetSize()const;
	void SetSize(DirectX::XMFLOAT2 p_size);

	DirectX::XMFLOAT3 GetPosition()const;
	void SetPosition(DirectX::XMFLOAT3 p_position);

private:
	DirectX::XMFLOAT2 m_size;
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT4 m_color;
};

#endif