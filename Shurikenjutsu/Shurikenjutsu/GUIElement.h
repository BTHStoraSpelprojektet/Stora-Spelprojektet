#ifndef GUIELEMENT_H_
#define GUIELEMENT_H_

#include <DirectXMath.h>
#include "GUIManager.h"
#include "DirectX.h"
#include "TextureLibrary.h"

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

private:
	DirectX::XMFLOAT2 m_size;
	DirectX::XMFLOAT3 m_position;
	ID3D11Resource* m_texture;
	ID3D11ShaderResourceView* m_textureView;
};

#endif