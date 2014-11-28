#ifndef PLAYERMANAGER
#define PLAYERMANAGER

#include "Player.h"
#include <vector>

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();
	bool Initialize();
	void Shutdown();
	void Update(double p_deltaTime);
	void Render();
	DirectX::XMFLOAT3 GetPlayerPosition();
private:
	void AddPlayer(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility);
	void AddEnemy(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility);

	Player m_player;
	std::vector<Player> m_enemyList;
	
};

#endif PLAYERMANAGER