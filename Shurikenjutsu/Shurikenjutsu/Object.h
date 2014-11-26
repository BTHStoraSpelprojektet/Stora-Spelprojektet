#ifndef OBJECT
#define OBJECT

#include "Model.h"
#include <DirectXMath.h>

class Object
{
public:
	Object();
	~Object();
	virtual bool Initialize(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos);
	virtual void Shutdown();
	DirectX::XMFLOAT3 GetPosition() const;
	void SetPosition(DirectX::XMFLOAT3 p_pos);

	DirectX::XMFLOAT3 GetScale() const;
	void SetScale(DirectX::XMFLOAT3 p_scale);

	DirectX::XMFLOAT3 GetRotation() const;
	void SetRotation(DirectX::XMFLOAT3 p_rotation);

	Model GetModel();
protected:
	//void SetModel(const char* p_filepath);

	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_scale;
	DirectX::XMFLOAT3 m_rotation;
	Model m_model;
};

#endif OBJECT