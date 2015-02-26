#ifndef PlayingStateTest_H_
#define PlayingStateTest_H_

#include "GameState.h"
#include "DebugDraw.h"

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

class FFAGameState :
	public GameState
{
public:
	FFAGameState();
	~FFAGameState();

	virtual bool Initialize();
	virtual bool Initialize(std::string p_levelName);
	void Shutdown();
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

private:
	void BasicPicking();
	DirectX::XMFLOAT3 Pick(Point p_point);
	void FFAGameState::OnScreenResize();

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
	ScoreBoard* m_scoreBoard;

	const float twoPi = DirectX::XM_PI * 2.0f;

	bool m_updateFrustum;

	bool m_renderOutlining;

	float m_mouseX;
	float m_mouseY;

	Frustum *m_frustum;

	float m_quadWidth;
	float m_quadHeightTop;
	float m_quadHeightBottom;

	int m_spectateIndex;
	float m_spectateCountDown;
	bool m_inGameMenuIsActive;

	Sound* m_sound;

	bool m_scoreBoardIsActive;
};
#endif // !PlayingStateTest_H_