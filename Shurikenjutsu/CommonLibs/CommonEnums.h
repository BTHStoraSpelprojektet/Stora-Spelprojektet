#ifndef COMMONENUMS_H_
#define	COMMONENUMS_H_

enum ABILITIES
{
	ABILITIES_SHURIKEN,
	ABILITIES_DASH,
	ABILITIES_MELEESWING,
	ABILITIES_MEGASHURIKEN,
	ABILITIES_SMOKEBOMB,
	ABILITIES_SPIKETRAP,
	ABILITIES_WHIP_PRIMARY,
	ABILITIES_WHIP_SECONDARY,
	ABILITIES_FANBOOMERANG,
	ABILITIES_NAGINATASLASH,
	ABILITIES_KUNAI,
	ABILITIES_STICKY_TRAP,
	ABILITIES_NAGAINATASTAB
};

enum AnimationState {
	Melee,
	Range,
	Special1,
	Special2,
	Tool,
	None,
	Death,
	Spawn
};

enum EmitterType{
	Fire,
	Smoke,
	LeafTree,
	LeafSakura,
	WorldMist
};

#endif // !COMMONENUMS_H_