#ifndef ENUMERATIONS
#define ENUMERATIONS

enum SHADERTYPE
{
	SHADERTYPE_SCENE,
	SHADERTYPE_INSTANCED,
	SHADERTYPE_ANIMATED,
	SHADERTYPE_UI,
	SHADERTYPE_DEPTH
};

enum BUFFERTYPE
{
	BUFFERTYPE_VERTEX,
	BUFFERTYPE_VERTEXANIMATED
};

enum PARTICLE_PATTERN
{
	PARTICLE_PATTERN_SMOKE,
	PARTICLE_PATTERN_FIRE,
	PARTICLE_PATTERN_FIRE_SPARK,
	PARTICLE_PATTERN_FIRE_TORCH,
	PARTICLE_PATTERN_GREEN_LEAVES,
	PARTICLE_PATTERN_PINK_LEAVES,
	PARTICLE_PATTERN_ACERPALMATUM_LEAVES,
	PARTICLE_PATTERN_POI_SPARKLE,
	PARTICLE_PATTERN_WORLD_DUST,
	PARTICLE_PATTERN_FIREFLIES,
	PARTICLE_PATTERN_BUBBLES,
	PARTICLE_PATTERN_BLOODHIT
};
#endif