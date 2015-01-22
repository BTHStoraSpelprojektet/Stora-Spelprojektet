#ifndef OBJECT
#define OBJECT

#define WIN32_LEAN_AND_MEAN
#include <DirectXMath.h>
#include "..\CommonLibs\ModelLibrary.h"
#include "DebugDraw.h"

class Model;

class Object
{
public:
	Object();
	~Object();
	virtual bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos);
	virtual bool Initialize(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_rotation, DirectX::XMFLOAT3 p_scale);
	virtual void Shutdown();
	virtual void Render();
	virtual void RenderDepth();
	virtual void RenderDepthInstanced();
	virtual void RenderInstanced();

	virtual DirectX::XMFLOAT3 GetPosition() const;
	virtual void SetPosition(DirectX::XMFLOAT3 p_pos);

	DirectX::XMFLOAT3 GetScale() const;
	void SetScale(DirectX::XMFLOAT3 p_scale);

	DirectX::XMFLOAT3 GetRotation() const;
	void SetRotation(DirectX::XMFLOAT3 p_rotation);

	Model* GetModel();

	DirectX::XMFLOAT4X4 GetWorldMatrix();

	std::vector<OBB> GetBoundingBoxes();
	Sphere GetFrustumSphere();

	void CreateInstanceBuffer(int p_numberOfInstances, std::vector<DirectX::XMFLOAT4X4> p_positions);

	int GetInstanceIndex() const;
	void SetInstanceIndex(int p_instanceIndex);
protected:
	void TransformBoundingBoxes();
	void TransformShadowPoints();

	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_scale;
	DirectX::XMFLOAT3 m_rotation;
	Model* m_model;

	std::vector<OBB> m_boundingBoxes;
	int m_InstanceIndex;
};
#endif