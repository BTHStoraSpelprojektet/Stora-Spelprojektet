#ifndef PLAYERMANAGER
#define PLAYERMANAGER

#define WIN32_LEAN_AND_MEAN
#include "Player.h"
#include <vector>
#include <DirectXCollision.h>

class Frustum;
class AbilityBar;
class Minimap;
class Sound;

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();
	bool Initialize();
	void Shutdown();
	void Update(std::vector<StickyTrap*> p_stickyTrapList);
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
	Player* GetEnemyTeamMember(int p_index);
	int GetEnemyTeam(int p_index);
	
	DirectX::XMFLOAT3 GetTeamMemberPosSpectate(int &p_index, int p_team);
	bool GetPlayerIsAlive();
	int GetNrOfPlayersInTeam(int p_team);

	void PlayerManager::SetSound(Sound* p_sound);

private:
	void AddPlayer(int p_charNr, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	void AddEnemy(RakNet::RakNetGUID p_guid, int p_charNr, DirectX::XMFLOAT3 p_pos, DirectX::XMFLOAT3 p_direction);
	
	bool IsGuidInEnemyList(RakNet::RakNetGUID p_guid);
	bool IsGuidInNetworkList(RakNet::RakNetGUID p_guid);

	void CheckPlayersVisible();

	void AddEnemyToList(Player* p_enemy);
	void RemoveEnemyFromList(unsigned int p_index);
	

	Player* m_player;

	Player** m_enemyList;
	unsigned int m_enemyListSize;

	Frustum* m_frustum;

	Sound* m_sound;
};

#endif PLAYERMANAGER