#ifndef PLAYERMANAGER
#define PLAYERMANAGER

#define WIN32_LEAN_AND_MEAN
#include "Player.h"
#include "DebugDraw.h"
#include "AbilityBar.h"
#include "Frustum.h"
#include <vector>

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();
	bool Initialize();
	void Shutdown();
	void Update();
	void Render();
	DirectX::XMFLOAT3 GetPlayerPosition();
	DirectX::XMFLOAT3 GetPlayerDirection();
	void SetPlayerDirection(DirectX::XMFLOAT3 p_direction); 

	DirectX::XMFLOAT3 GetFacingDirection();
	void SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection);
	DirectX::XMFLOAT3 GetAttackDirection();
	void SetAttackDirection(DirectX::XMFLOAT3 p_attackDirection);

	DirectX::BoundingBox GetPlayerBoundingBox();

	void UpdateHealthbars(DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);

	void ResetCooldowns();

	void UpdateFrustum(Frustum* p_frustum);

private:
	void AddPlayer(const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void AddEnemy(RakNet::RakNetGUID p_guid, const char* p_filepath, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	
	bool IsGuidInEnemyList(RakNet::RakNetGUID p_guid);
	bool IsGuidInNetworkList(RakNet::RakNetGUID p_guid);

	Player m_player;

	AbilityBar m_playerAbilityBar;

	std::vector<Player> m_enemyList;

	Frustum m_frustum;

	float m_enemyUpdatePositionTimer;
};

#endif PLAYERMANAGER