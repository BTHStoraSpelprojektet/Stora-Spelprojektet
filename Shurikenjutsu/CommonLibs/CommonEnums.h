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
	ABILITIES_NAGAINATASTAB,
	ABILITIES_VOLLEY
};

enum PLAYSOUND
{
	PLAYSOUND_BACKGROUND_SOUND,
	PLAYSOUND_KUNAI_THROW_SOUND,
	PLAYSOUND_KUNAI_HIT_OBJECTS_SOUND,
	PLAYSOUND_KUNAI_HIT_SOUND,
	PLAYSOUND_AIR_CUT_SOUND,
	PLAYSOUND_WHIP_AIR_SOUND,
	PLAYSOUND_WHIP_ROTATE_SOUND,
	PLAYSOUND_WHIP_HIT_SOUND,
	PLAYSOUND_KATANA_HIT_SOUND,
	PLAYSOUND_DASH_STEPS_SOUND,
	PLAYSOUND_SHURIKEN_THROW_SOUND,
	PLAYSOUND_SHURIKEN_HIT_SOUND,
	PLAYSOUND_SHURIKEN_HIT_OBJECTS_SOUND,
	PLAYSOUND_MEGA_SHURIKEN_HIT_SOUND,
	PLAYSOUND_MEGA_SHURIKEN_HIT_OBJECTS_SOUND,
	PLAYSOUND_SMOKE_BOMB_SOUND,
	PLAYSOUND_NAGINATA_AIR_SOUND,
	PLAYSOUND_NAGINATA_STAB_SOUND,
	PLAYSOUND_NAGINATA_HIT_SOUND,
	PLAYSOUND_VOLLEY_THROW_SOUND,
	PLAYSOUND_VOLLEY_HIT_SOUND,
	PLAYSOUND_BUBLE_SOUND,
	PLAYSOUND_FIRE_SOUND,
	PLAYSOUND_WIND_SOUND,
	PLAYSOUND_BIRD_SOUND,
	PLAYSOUND_STEPS_LEAVES_SOUND,
	PLAYSOUND_MALE_DEATH_SOUND,
	PLAYSOUND_FEMALE_DEATH_SOUND,
	PLAYSOUND_MALE_HURT_SOUND,
	PLAYSOUND_FEMALE_HURT_SOUND,
	PLAYSOUND_COUNTDOWN_BEEP_SOUND,
	PLAYSOUND_COUNTDOWN_GONG_SOUND,
	PLAYSOUND_RUNE_SHIELD_SOUND,
	PLAYSOUND_RUNE_SHIELD_SPAWN_SOUND,
	PLAYSOUND_RUNE_SHIELD_PICKUP_SOUND,
	PLAYSOUND_RUNE_HEAL_SOUND,
	PLAYSOUND_RUNE_HEAL_SPAWN_SOUND,
	PLAYSOUND_RUNE_HEAL_PICKUP_SOUND,
	PLAYSOUND_RUNE_INVISIBLE_SOUND,
	PLAYSOUND_RUNE_INVISIBLE_SPAWN_SOUND,
	PLAYSOUND_RUNE_INVISIBLE_PICKUP_SOUND,
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
	EmitterType_BrazierFire,
	EmitterType_Fireflies,
	EmitterType_FireSpark,
	EmitterType_TorchFire,
	EmitterType_Smoke,
	EmitterType_LeafTree,
	EmitterType_LeafSakura,
	EmitterType_LeafAcerPalmatum,
	EmitterType_WorldMist,
	EmitterType_WorldDust
};

enum POINTOFINTERESTTYPE{
	POINTOFINTERESTTYPE_HEAL,
	POINTOFINTERESTTYPE_INVISIBLE,
	POINTOFINTERESTTYPE_SHIELD
};

#endif // !COMMONENUMS_H_