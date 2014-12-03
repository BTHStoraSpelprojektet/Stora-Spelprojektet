#ifndef PLAYERMANAGER
#define PLAYERMANAGER

#define WIN32_LEAN_AND_MEAN
#include "Player.h"
#include "DebugDraw.h"

#include <vector>

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();
	bool Initialize();
	void Shutdown();
	void Update(double p_deltaTime);
	void Render(SHADERTYPE p_shader);
	DirectX::XMFLOAT3 GetPlayerPosition();
	DirectX::XMFLOAT3 GetPlayerDirection();
	void SetPlayerDirection(DirectX::XMFLOAT3 p_direction); 

	DirectX::XMFLOAT3 GetFacingDirection();
	void SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection);
	DirectX::XMFLOAT3 GetAttackDirection();
	void SetAttackDirection(DirectX::XMFLOAT3 p_attackDirection);
private:
	void AddPlayer(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility);
	void AddEnemy(RakNet::RakNetGUID p_guid, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction,
		float p_speed, float p_damage, int p_spells, unsigned int p_health, float p_agility);
	
	bool IsGuidInEnemyList(RakNet::RakNetGUID p_guid);
	bool IsGuidInNetworkList(RakNet::RakNetGUID p_guid);

	Player m_player;
	std::vector<Player> m_enemyList;
	
};

#endif PLAYERMANAGER