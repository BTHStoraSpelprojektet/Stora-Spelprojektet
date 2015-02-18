#ifndef FLOATINGTEXT_H_
#define FLOATINGTEXT_H_

#include "GUIText.h"

class FloatingText
{
public:
	void Initialize();
	void Update();
	void Shutdown();
	void Render();
	void ResetTimer();
private:
	GUIText* m_receivedDamage;
	float m_timer;
};

#endif