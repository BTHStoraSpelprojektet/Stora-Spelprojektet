#ifndef OBJECT
#define OBJECT

#define WIN32_LEAN_AND_MEAN
#include "Model.h"
#include <DirectXMath.h>
#include "Network.h"
#include "..\CommonLibs\ModelLibrary.h"
#include "AnimationControl.h"
#include <DirectXCollision.h>
#include "DebugDraw.h"

class Object
{
public:
	Object();
	~Object();
	virtual bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos);
	virtual bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_rotation, DirectX::XMFLOAT3 p_scale);
	virtual void Shutdown();
	virtual void Render(SHADERTYPE p_shader);
	void RenderDebugBoxes();

	virtual DirectX::XMFLOAT3 GetPosition() const;
	virtual void SetPosition(DirectX::XMFLOAT3 p_pos);

	DirectX::XMFLOAT3 GetScale() const;
	void SetScale(DirectX::XMFLOAT3 p_scale);

	DirectX::XMFLOAT3 GetRotation() const;
	void SetRotation(DirectX::XMFLOAT3 p_rotation);

	Model* GetModel();

	// Calculates and then returns the world matrix
	DirectX::XMFLOAT4X4 GetWorldMatrix();

	std::vector<OBB> GetBoundingBoxes();
	std::vector<DirectX::XMFLOAT3> GetShadowPoints();

protected:
	//void SetModel(const char* p_filepath);
	void TransformBoundingBoxes();
	void TransformShadowPoints();

	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_scale;
	DirectX::XMFLOAT3 m_rotation;
	Model* m_model;

	std::vector<OBB> m_boundingBoxes;
	std::vector<DebugShape3D> m_debugBoxes;
	std::vector<DirectX::XMFLOAT3> m_shadowPoints;
};

#endif OBJECT