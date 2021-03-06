#ifndef GUIELEMENT_H_
#define GUIELEMENT_H_

#include <DirectXMath.h>
#include <d3d11.h>

class GUIElement
{
public:
	GUIElement();
	~GUIElement();

	bool Initialize(DirectX::XMFLOAT3 p_position, float p_width, float p_height, ID3D11ShaderResourceView* p_texture);

	void QueueRender();

	DirectX::XMFLOAT4X4 GetWorldMatrix()const;

	DirectX::XMFLOAT2 GetSize()const;
	void SetSize(DirectX::XMFLOAT2 p_size);

	DirectX::XMFLOAT3 GetPosition()const;
	void SetPosition(DirectX::XMFLOAT3 p_position);

	ID3D11ShaderResourceView* GetTexture()const;
	void SetTexture(ID3D11ShaderResourceView* p_texture);

	void SetOpacity(float p_opacity);
	float GetOpacity();

	// For cursor
	void Render();

private:
	DirectX::XMFLOAT2 m_size;
	DirectX::XMFLOAT3 m_position;
	ID3D11ShaderResourceView* m_texture;
	float m_opacity;
};

#endif