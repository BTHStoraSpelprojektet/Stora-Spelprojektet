#ifndef NAGINATASTAB_H_
#define NAGINATASTAB_H_

#include "Ability.h"

class NaginataStab :
	public Ability
{
public:
	NaginataStab();
	~NaginataStab();

	bool Initialize();
	bool Execute(float p_distance);

};
#endif // !NAGINATASTAB_H_