#ifndef PLAYINGSTATE
#define PLAYINGSTATE
#define WIN32_LEAN_AND_MEAN

#include <string>
#include <DirectXMath.h>
#include "GameState.h"

#include "..\CommonLibs\CommonStructures.h"

class PlayerManager;
class ObjectManager;
class Frustum;
class Camera;
class Minimap;
class TeamStatusBar;
class Countdown;
class InGameMenu;
class VictoryScreenMenu;
class DeathBoard;
class Sound;
class ScoreBoard;
class SuddenDeathState;
class GUIText;


class PlayingState : public GameState
{
public:
	PlayingState();
	~PlayingState();
	virtual bool Initialize();
	virtual bool Initialize(std::string p_levelName);
	void Shutdown();
	void ShutdownExit();
	GAMESTATESWITCH Update();
	void Render();
	void ToggleFullscreen(bool p_fullscreen);
	void MinimapUpdatePos(Minimap *p_minimap);

	void* operator new(size_t i);
	void operator delete(void* p);

	void OutliningRays();
	ObjectManager* GetObjectManager();

	DirectX::XMFLOAT2 GetMousePosition();

	void SetSound(Sound* p_sound);

	void EscapeIsPressed();

	void ResetValuesAtRoundRestart();

private:
	void BasicPicking();
	DirectX::XMFLOAT3 Pick(Point p_point);
	void OnScreenResize();
	void SSBoundryUpdate(DirectX::XMFLOAT3 p_player);
	void DecreaseTextOpacity(GUIText* p_text);
	void UpdatePOIEffects();

	DirectX::XMFLOAT3 NormalizeFloat3(DirectX::XMFLOAT3 p_f);

	PlayerManager* m_playerManager;
	ObjectManager* m_objectManager;
	Camera* m_camera;
	Minimap* m_minimap;
	TeamStatusBar* m_teamStatusBar;
	DirectionalLight m_directionalLight;
	Countdown* m_countdown;
	InGameMenu *m_inGameMenu;
	VictoryScreenMenu* m_victoryMenu;
	SuddenDeathState* m_suddenDeath;

	GUIText* m_startText;
	GUIText* m_poiText;
	GUIText* m_playerJoinedText;
	GUIText* m_spectateText;
	bool m_refreshSpectateText;

	void PlayerJoinedText();

	const float twoPi = DirectX::XM_PI * 2.0f;

	bool m_updateFrustum;

	bool m_renderOutlining;
	bool m_renderOutlingingEnemies[7];

	float m_mouseX;
	float m_mouseY;

	Frustum *m_frustum;

	float m_quadWidth;
	float m_quadHeightTop;
	float m_quadHeightBottom;

	int m_spectateIndex;

	//Tas bort?
	float m_spectateCountDown;
	bool m_inGameMenuIsActive;

	Sound* m_sound;

	bool m_scoreBoardIsActive;
	float m_spectateTimer;
};
#endif PLAYINGSTATE