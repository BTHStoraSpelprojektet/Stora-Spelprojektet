#ifndef PLAYERSERVER_H_
#define PLAYERSERVER_H_

#include "..\CommonLibs\ServerMessages.h"
#include "..\CommonLibs\Level.h"
#include "..\CommonLibs\ModelLibrary.h"
#include <d3d11.h>
#include "..\CommonLibs\CommonStructures.h"

class Player
{
public:
	Player();
	~Player();

	bool Initialize(std::string p_modelName, RakNet::RakNetGUID p_guid, int p_team, DirectX::XMFLOAT3 p_position, DirectX::XMFLOAT3 p_direction);
	void Shutdown();
	
	void Update(double p_deltaTime);
	void Move(DirectX::XMFLOAT3 p_position);
	void Rotate(DirectX::XMFLOAT3 p_rotation);
	void Respawn(DirectX::XMFLOAT3 p_position);
	std::vector<Box> GetBoundingBoxes();
private:
	std::vector<Box> m_boundingBoxes;
	DirectX::XMFLOAT3 m_position;
	DirectX::XMFLOAT3 m_direction;
	RakNet::RakNetGUID m_guid;
	int m_team;
	float m_gcd;
};

#endif