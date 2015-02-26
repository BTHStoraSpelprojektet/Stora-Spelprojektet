#ifndef SUDDENDEATH_H_
#define SUDDENDEATH_H_

#include <vector>
#include "Structures.h"

class GUIElement;
class GUIText;
class ParticleEmitter;

class SuddenDeathState
{
public:
	SuddenDeathState();
	~SuddenDeathState();
	void Initialize(std::vector<Box> p_walls);
	void Update();
	void Shutdown();
	void Render();


private:

	GUIText* m_title;
	ParticleEmitter* m_gasParticle[4];
	std::vector<Box> m_walls;
};

#endif