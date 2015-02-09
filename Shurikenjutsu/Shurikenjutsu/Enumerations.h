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
	PARTICLE_PATTERN_GREEN_LEAVES,
	PARTICLE_PATTERN_PINK_LEAVES,
	PARTICLE_PATTERN_WORLD_MIST,
};
#endif