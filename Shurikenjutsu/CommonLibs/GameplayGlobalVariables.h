#ifndef GAMEPLAYGLOBALVARIABLES_H_
#define GAMEPLAYGLOBALVARIABLES_H_

const float ALL_AROUND_GLOBAL_COOLDOWN = 0.4f;

const float TICK_RATE = 0.10f;


const float ROUND_TIME_LIMIT_MINUTS = 2.0f;
const float ROUND_TIME_LIMIT_SECONDS = 10.0f;
const float SUDDEN_DEATH_DAMAGE = 5.0f;

// Sphere for character
const float CHARACTER_ENEMY_BOUNDINGSPHERE = 1.0f;

///////////////////////////////////////////////////////////////////
//			NINJA 1
///////////////////////////////////////////////////////////////////

//_____________STATS______________________________
const float CHARACTER_KATANA_SHURIKEN_HEALTH = 100.0f;
const float CHARACTER_KATANA_SHURIKEN_SPEED = 10.0f;

//_____________ABILITIES__________________________
// Katana M1
const float KATANA_DAMAGE = 25.0f;
const float KATANA_RANGE = 2.0f;
const float KATANA_COOLDOWN = 0.5f;

//Shuriken M2
const float SHURIKEN_DAMAGE = 15.0f;
const float SHURIKEN_COOLDOWN = 2.0f;
const float SHURIKEN_DURATION = 3.0f;
const int SHURIKEN_MAX_STACK = 3;
const float SHURIKEN_ROTATION_SPEED = 15.70f;
const float SHURIKEN_SPEED = 40.0f;

//Dash Q
const float DASH_MAX_RANGE = 13.0f;
const float DASH_COOLDOWN = 7.0f;
const float DASH_DAMAGE = 0.0f;
const float DASH_SPEED = 8.0f;

// Megashuriken E
const float MEGASHURIKEN_COOLDOWN = 5.0f;
const float MEGASHURIKEN_DAMAGE = 30.0f;
const float MEGASHURIKEN_DURATION = 4.0f;
const float MEGASHURIKEN_SPEED = 25.0f;


///////////////////////////////////////////////////////////////////
//			NINJA 2
///////////////////////////////////////////////////////////////////

//_____________STATS______________________________
const float CHARACTER_TESSEN_HEALTH = 100.0f;
const float CHARACTER_TESSEN_SPEED = 11.0f;

//_____________ABILITIES__________________________
// Fan Melee M1
const float FANMELEE_DAMAGE = 25.0f;
const float FANMELEE_RANGE = 2.0f;
const float FANMELEE_COOLDOWN = 0.5f;

//Whip M2
const float WHIP_DAMAGE = 15.0f;
const float WHIP_COOLDOWN = 2.0f;
const float WHIP_RANGE = 9.0f;

// Fan Boomerang Q
const float FANBOOMERANG_DAMAGE = 75.0f;
const float FANBOOMERANG_COOLDOWN = 2.0f;
const float FANBOOMERANG_DURATION = 1.5f;
const float FANBOOMERANG_SPEED = 17.0f;

//Whip special attack E
const float WHIP_SP_DAMAGE = 25.0f;
const float WHIP_SP_COOLDOWN = 5.0f;
const float WHIP_SP_RANGE = 7.0f;


///////////////////////////////////////////////////////////////////
//			NINJA 3
///////////////////////////////////////////////////////////////////

//_____________STATS______________________________
const float CHARACTER_NAGINATA_HEALTH = 100.0f;
const float CHARACTER_NAGINATA_SPEED = 10.5f;

//_____________ABILITIES__________________________
// Naginata M1
const float NAGINATA_DAMAGE = 20.0f;
const float NAGINATA_RANGE = 2.0f;
const float NAGINATA_COOLDOWN = 0.5f;

// Kunai M2
const float KUNAI_DAMAGE = 10.0f;
const float KUNAI_COOLDOWN = 2.0f;
const float KUNAI_DURATION = 2.0f;
const int KUNAI_MAX_STACK = 4;
const float KUNAI_ROTATION_SPEED = 0.0f;
const float KUNAI_SPEED = 50.0f;

// Naginata stab Q
const float NAGINATASTAB_DAMAGE = 30.0f;
const float NAGINATASTAB_RANGE = 2.4f;
const float NAGINATASTAB_COOLDOWN = 4.0f;
const float NAGINATASTAB_GLOBAL_COOLDOWN = 1.5f;
const float NAGINATASTAB_DURATION = 1.5f;
	// Bounding Box
	const float NAGINATASTAB_BOXEXTENTX = 0.7f;
	const float NAGINATASTAB_BOXEXTENTY = 1.0f;
	const float NAGINATASTAB_BOXEXTENTZ = 2.0f;

// Volley E
const float VOLLEY_DAMAGE = 40.0f;
const float VOLLEY_COOLDOWN = 4.0f;
const float VOLLEY_RANGE = 15.0f;
const float VOLLEY_RADIUS = 0.5f;
const float VOLLEY_GRAVITY = 3.5f;
const float VOLLEY_HEIGHT = 15.0f;


///////////////////////////////////////////////////////////////////
//			TOOLS
///////////////////////////////////////////////////////////////////

//Smoke bomb
const float SMOKEBOMB_DURATION = 4.0f;
const float SMOKEBOMB_DAMAGE = 0.0f;
const float SMOKEBOMB_COOLDOWN = 6.0f;
const float SMOKEBOMB_SPEED = 30.0f;

const float SMOKEBOMB_RANGE = 15.0f;
const float SMOKEBOMB_POSITION_Y = 4.0f;
const float SMOKEBOMB_DIRECTION_X = 0.0f;
const float SMOKEBOMB_DIRECTION_Y = 1.0f;
const float SMOKEBOMB_DIRECTION_Z = 0.0f;
const float SMOKEBOMB_SIZE_X = 3.0f;
const float SMOKEBOMB_SIZE_Y = 3.0f;

// Spike Trap
const float SPIKE_DAMAGE = 3.0f;
const float SPIKE_COOLDOWN = 6.0f;
const float SPIKE_RANGE = 15.0f;
const float SPIKE_DURATION = 20.0f;
const float SPIKE_SPEED = 30.0f;
const float SPIKE_SIZE_X = 3.0f;
const float SPIKE_RADIUS = 1.3f;

// Sticky Trap
const float STICKY_TRAP_DAMAGE = 0.0f;
const float STICKY_TRAP_COOLDOWN = 6.0f;
const float STICKY_TRAP_RANGE = 15.0f;
const float STICKY_TRAP_DURATION = 20.0f;
const float STICKY_TRAP_SPEED = 30.0f;
const float STICKY_TRAP_SIZE_X = 3.0f;
const float STICKY_TRAP_RADIUS = 2.0f;
const float STICKY_TRAP_SLOW_PRECENTAGE = 0.5f;

// Flashbang.
const float FLASHBANG_HOLD_TIME = 3.0f;


///////////////////////////////////////////////////////////////////
//			WORLD PARTICLES
///////////////////////////////////////////////////////////////////

const float PARTICLE_FIRE_SIZE_X = 0.3f;
const float PARTICLE_FIRE_SIZE_Y = 0.3f;

const float PARTICLE_FIRE_TORCH_SIZE_X = 0.2f;
const float PARTICLE_FIRE_TORCH_SIZE_Y = 0.2f;

const float PARTICLE_FIRE_SPARK_SIZE_X = 0.02f;
const float PARTICLE_FIRE_SPARK_SIZE_Y = 0.02f;

const float PARTICLE_FIREFLIES_SIZE_X = 0.1f;
const float PARTICLE_FIREFLIES_SIZE_Y = 0.1f;

const float PARTICLE_PINKLEAF_SIZE_X = 0.14f;
const float PARTICLE_PINKLEAF_SIZE_Y = 0.14f;

const float PARTICLE_GREENLEAF_SIZE_X = 0.15f;
const float PARTICLE_GREENLEAF_SIZE_Y = 0.15f;

const float PARTICLE_WORLDMIST_SIZE_X = 14.15f;
const float PARTICLE_WORLDMIST_SIZE_Y = 14.15f;

const float PARTICLE_WORLDDUST_SIZE_X = 0.05f;
const float PARTICLE_WORLDDUST_SIZE_Y = 0.05f;


///////////////////////////////////////////////////////////////////
//			RUNES
///////////////////////////////////////////////////////////////////
const float LOTUS_HEALTICK = 10.0f;
const float SHIELD_TIMER = 30.0f;
const float INVIS_TIMER = 30.0f;

#endif