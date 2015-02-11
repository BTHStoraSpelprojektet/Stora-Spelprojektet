#include "ParticleRenderer.h"
#include "ParticleEmitter.h"
#include "GraphicsEngine.h"

ParticleRenderer* ParticleRenderer::m_instance;

ParticleRenderer::ParticleRenderer(){}
ParticleRenderer::~ParticleRenderer(){}

ParticleRenderer* ParticleRenderer::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ParticleRenderer();
	}

	return m_instance;
}

void ParticleRenderer::Shutdown()
{
	m_renderQueue.clear();
	delete m_instance;
	m_instance = nullptr;
}

void ParticleRenderer::QueueRender(ParticleEmitter* p_particleEmitter)
{
	m_renderQueue.push_back(p_particleEmitter);
}

void ParticleRenderer::Render()
{
	for (unsigned int i = 0; i < m_renderQueue.size(); i++)
	{
		GraphicsEngine::RenderParticles(m_renderQueue[i]->GetVertexBuffer(), m_renderQueue[i]->GetVertices(), m_renderQueue[i]->GetWorldMatrix(), m_renderQueue[i]->GetParticleTexture());
	}
	m_renderQueue.clear();
}