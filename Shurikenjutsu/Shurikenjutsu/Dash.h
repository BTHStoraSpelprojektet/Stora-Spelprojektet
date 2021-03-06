#ifndef DASH_H_
#define DASH_H_

#include "Ability.h"

class Dash : public Ability
{
public:
	Dash();
	Dash(const Dash&);
	~Dash();

	bool Initialize();
	bool Execute(float p_distance);

};
#endif // !DASH_H_