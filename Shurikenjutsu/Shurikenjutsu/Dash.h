#ifndef DASH_H_
#define DASH_H_

#include "Ability.h"
#include <iostream>

class Dash : public Ability
{
public:
	Dash();
	~Dash();

	void Execute();
};
#endif // !DASH_H_