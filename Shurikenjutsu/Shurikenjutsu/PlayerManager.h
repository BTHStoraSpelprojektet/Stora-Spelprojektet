#ifndef PLAYERMANAGER
#define PLAYERMANAGER

#include "Player.h"
#include <vector>

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();
	bool Initialize(ID3D11Device *p_device);
	void Shutdown();
	void Update(double p_deltaTime);
	void AddPlayer(ID3D11Device* p_device, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility);
	Model* GetModel(int p_index);
private:
	std::vector<Player*> m_playerList;
};

#endif PLAYERMANAGER