#include "ParticleRenderer.h"
#include "ParticleEmitter.h"
#include "GraphicsEngine.h"
#include "Object.h"

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
	for (unsigned int i = 0; i < m_renderQueue.size(); i++)
	{
		if (m_renderQueue[i] != nullptr)
		{
			m_renderQueue[i]->Shutdown();
			delete m_renderQueue[i];
			m_renderQueue[i] = nullptr;
		}
	}
	m_renderQueue.clear();
	delete m_instance;
	m_instance = nullptr;
}

void ParticleRenderer::QueueRender(ParticleEmitter* p_particleEmitter)
{
	m_renderQueue.push_back(p_particleEmitter);
}

void ParticleRenderer::QueueRender(Object* p_object)
{
	m_renderQueueObjects.push_back(p_object);
}

void ParticleRenderer::Render()
{
	for (unsigned int i = 0; i < m_renderQueueObjects.size(); i++)
	{
		m_renderQueueObjects[i]->RenderForward();
	}
	
	for (unsigned int i = 0; i < m_renderQueue.size(); i++)
	{
		GraphicsEngine::GetInstance()->RenderParticles(m_renderQueue[i]->GetVertexBuffer(), m_renderQueue[i]->GetVertices(), m_renderQueue[i]->GetWorldMatrix(), m_renderQueue[i]->GetParticleTexture());
	}

	m_renderQueue.clear();
	m_renderQueueObjects.clear();
}