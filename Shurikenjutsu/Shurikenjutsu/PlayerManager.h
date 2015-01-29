#ifndef PLAYERMANAGER
#define PLAYERMANAGER

#define WIN32_LEAN_AND_MEAN
#include "Player.h"
#include <vector>
#include <DirectXCollision.h>

class Frustum;
class AbilityBar;
class Minimap;

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();
	bool Initialize();
	void Shutdown();
	void Update();
	void Render();
	void RenderDepth();
	void RenderOutliningPassOne();
	void RenderOutliningPassTwo();
	DirectX::XMFLOAT3 GetPlayerPosition();
	DirectX::XMFLOAT3 GetPlayerDirection();
	void SetPlayerDirection(DirectX::XMFLOAT3 p_direction); 

	DirectX::XMFLOAT3 GetFacingDirection();
	void SetFacingDirection(DirectX::XMFLOAT3 p_facingDirection);
	DirectX::XMFLOAT3 GetAttackDirection();
	void SetAttackDirection(DirectX::XMFLOAT3 p_attackDirection);

	OBB GetPlayerBoundingBox();
	Sphere GetPlayerSphere();

	void UpdateHealthbars(DirectX::XMFLOAT4X4 p_view, DirectX::XMFLOAT4X4 p_projection);

	void ResetCooldowns();

	void UpdateFrustum(Frustum* p_frustum);
	void MinimapUpdatePos(Minimap *p_minimap);
	bool IsPlayersVisible(int p_index);
	int GetPlayerTeam();
	int GetEnemyTeam(int p_index);

private:
	void AddPlayer(int p_charNr, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void AddEnemy(RakNet::RakNetGUID p_guid, int p_charNr, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	
	bool IsGuidInEnemyList(RakNet::RakNetGUID p_guid);
	bool IsGuidInNetworkList(RakNet::RakNetGUID p_guid);

	void CheckPlayersVisible();
	

	Player* m_player;

	std::vector<Player> m_enemyList;

	Frustum* m_frustum;
};

#endif PLAYERMANAGER