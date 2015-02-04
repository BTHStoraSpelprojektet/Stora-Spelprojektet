#ifndef NAGINATASLASH_H_
#define NAGINATASLASH_H_

#include "Ability.h"

class NaginataSlash : public Ability
{
public:
	NaginataSlash();
	NaginataSlash(NaginataSlash&);
	~NaginataSlash();

	bool Initialize();
	bool Execute(float p_distance);

};
#endif // !NAGINATASLASH_H_
