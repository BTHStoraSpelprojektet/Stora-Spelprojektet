#ifndef PARTICLERENDERER_H_
#define PARTICLERENDERER_H_
#include <vector>
class ParticleEmitter;
class ParticleRenderer
{
public:
	

	ParticleRenderer(const ParticleRenderer&) = delete;
	ParticleRenderer& operator=(const ParticleRenderer&) = delete;

	static ParticleRenderer* GetInstance();

	void Shutdown();

	void QueueRender(ParticleEmitter* p_particleEmitter);
	void Render();

private:
	static ParticleRenderer* m_instance;
	ParticleRenderer();
	~ParticleRenderer();

	std::vector<ParticleEmitter*> m_renderQueue;
};

#endif