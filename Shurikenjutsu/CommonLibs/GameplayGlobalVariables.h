#ifndef GAMEPLAYGLOBALVARIABLES_H_
#define GAMEPLAYGLOBALVARIABLES_H_

const float ALL_AROUND_GLOBAL_COOLDOWN = 0.4f;


////////////////////////////////////////////////////////////////Ranged Attacks
//Shuriken
const float SHURIKEN_DAMAGE = 20.0f;
const float SHURIKEN_COOLDOWN = 2.0f;
const float SHURIKEN_DURATION = 3.0f;
const int SHURIKEN_MAX_STACK = 3;
const float SHURIKEN_ROTATION_SPEED = 15.70f;
const float SHURIKEN_SPEED = 40.0f;


////////////////////////////////////////////////////////////////Ranged Attacks
// Kunai
const float KUNAI_DAMAGE = 10.0f;
const float KUNAI_COOLDOWN = 2.0f;
const float KUNAI_DURATION = 2.0f;
const int KUNAI_MAX_STACK = 4;
const float KUNAI_ROTATION_SPEED = 10.0f;
const float KUNAI_SPEED = 50.0f;

////////////////////////////////////////////////////////////////Ranged Attacks
//Whip
const float WHIP_DAMAGE = 15.0f;
const float WHIP_COOLDOWN = 2.0f;
const float WHIP_RANGE = 15.0f;

//Whip special attack
const float WHIP_SP_DAMAGE = 25.0f;
const float WHIP_SP_COOLDOWN = 5.0f;
const float WHIP_SP_RANGE = 7.0f;


////////////////////////////////////////////////////////////////Ranged Attacks
////////////////////////////////////////////////////////////////Special Ranged Attacks
// Megashuriken
const float MEGASHURIKEN_COOLDOWN = 5.0f;
const float MEGASHURIKEN_DAMAGE = 40.0f;
const float MEGASHURIKEN_DURATION = 4.0f;
const float MEGASHURIKEN_SPEED = 25.0f;

// Fan Boomerang
const float FANBOOMERANG_DAMAGE = 25.0f;
const float FANBOOMERANG_COOLDOWN = 2.0f;
const float FANBOOMERANG_DURATION = 3.0f;
const float FANBOOMERANG_SPEED = 20.0f;

////////////////////////////////////////////////////////////////Special Ranged Attacks
////////////////////////////////////////////////////////////////Melee Attacks
// Katana
const float KATANA_DAMAGE = 40.0f;
const float KATANA_RANGE = 2.5f;
const float KATANA_COOLDOWN = 0.5f;

////////////////////////////////////////////////////////////////Melee Attacks
// Naginata
const float NAGINATA_DAMAGE = 30.0f;
const float NAGINATA_RANGE = 3.5f;
const float NAGINATA_COOLDOWN = 0.5f;

////////////////////////////////////////////////////////////////Special Melee Attacks
//Dash
const float DASH_MAX_RANGE = 10.0f;
const float DASH_COOLDOWN = 6.0f;
const float DASH_DAMAGE = 10.0f;
const float DASH_SPEED = 8.0f;

////////////////////////////////////////////////////////////////Special Melee Attacks
// Naginata stab
const float NAGINATASTAB_DAMAGE = 2.0f;
const float NAGINATASTAB_RANGE = 8.0f;
const float NAGINATASTAB_COOLDOWN = 1.0f;
	// Bounding Box
const float NAGINATASTAB_BOXEXTENTX = 0.75f;
const float NAGINATASTAB_BOXEXTENTY = 3.0f;
const float NAGINATASTAB_BOXEXTENTZ = 4.0f;


////////////////////////////////////////////////////////////////Tools
//Smoke bomb
const float SMOKEBOMB_DURATION = 3.0f;
const float SMOKEBOMB_DAMAGE = 0.0f;
const float SMOKEBOMB_COOLDOWN = 1.0f;
const float SMOKEBOMB_SPEED = 30.0f;

const float SMOKEBOMB_RANGE = 30.0f;
const float SMOKEBOMB_POSITION_Y = 4.0f;
const float SMOKEBOMB_DIRECTION_X = 0.0f;
const float SMOKEBOMB_DIRECTION_Y = 1.0f;
const float SMOKEBOMB_DIRECTION_Z = 0.0f;
const float SMOKEBOMB_SIZE_X = 3.0f;
const float SMOKEBOMB_SIZE_Y = 3.0f;

////////////////////////////////////////////////////////////////Tools
////////////////////////////////////////////////////////////////Special Abilities
//Spike Trap
const float SPIKE_DAMAGE = 3.0f;
const float SPIKE_COOLDOWN = 6.0f;
const float SPIKE_RANGE = 30.0f;
const float SPIKE_DURATION = 20.0f;
const float SPIKE_SPEED = 30.0f;
const float SPIKE_SIZE_X = 3.0f;
const float SPIKE_RADIUS = 1.5f;

//Spike Trap
const float STICKY_TRAP_DAMAGE = 0.0f;
const float STICKY_TRAP_COOLDOWN = 0.5f;/////////////////////////////////////////////////////
//const float STICKY_TRAP_COOLDOWN = 6.0f;
const float STICKY_TRAP_RANGE = 30.0f;
const float STICKY_TRAP_DURATION = 20.0f;
const float STICKY_TRAP_SPEED = 30.0f;
const float STICKY_TRAP_SIZE_X = 3.0f;
const float STICKY_TRAP_RADIUS = 1.5f;
const float STICKY_TRAP_SLOW_PRECENTAGE = 0.5f;

////////////////////////////////////////////////////////////////Special Abilities
////////////////////////////////////////////////////////////////Character Variables

const float CHARACTER_KATANA_SHURIKEN_HEALTH = 100.0f;
const float CHARACTER_KATANA_SHURIKEN_SPEED = 10.0f;

const float CHARACTER_TESSEN_HEALTH = 90.0f;
const float CHARACTER_TESSEN_SPEED = 12.0f;

const float CHARACTER_NAGINATA_HEALTH = 95.0f;
const float CHARACTER_NAGINATA_SPEED = 11.0f;

////////////////////////////////////////////////////////////////Character Variables
////////////////////////////////////////////////////////////////World Particles

const float PARTICLE_FIRE_SIZE_X = 0.2f;
const float PARTICLE_FIRE_SIZE_Y = 0.2f;

const float PARTICLE_PINKLEAF_SIZE_X = 0.14f;
const float PARTICLE_PINKLEAF_SIZE_Y = 0.14f;

const float PARTICLE_GREENLEAF_SIZE_X = 0.15f;
const float PARTICLE_GREENLEAF_SIZE_Y = 0.15f;

////////////////////////////////////////////////////////////////World Particles


/////////////////////////////////////////////////////////////// Bounding Boxes
// Sphere for character
const float CHARACTER_ENEMY_BOUNDINGSPHERE = 1.0f;

#endif