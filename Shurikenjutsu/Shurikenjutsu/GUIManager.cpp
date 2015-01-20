#include "GUIManager.h"

GUIManager* GUIManager::m_instance;

GUIManager::GUIManager(){}
GUIManager::~GUIManager(){}

GUIManager* GUIManager::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new GUIManager();
	}

	return m_instance;
}

void GUIManager::Render()
{
	GraphicsEngine::TurnOffDepthStencil();
	GraphicsEngine::TurnOnAlphaBlending();
	for (unsigned int i = 0; i < m_elements.size(); i++)
	{
		GraphicsEngine::RenderGUI(m_elements[i]->GetWorldMatrix(), m_elements[i]->GetTexture());
	}
	GraphicsEngine::TurnOffAlphaBlending();
	GraphicsEngine::TurnOnDepthStencil();
	m_elements.clear();
}

void GUIManager::AddToRenderQueue(GUIElement* p_element)
{
	m_elements.push_back(p_element);
}

void GUIManager::AddToRenderQueueColor(GUIElementColor* p_element)
{
	m_elementsColor.push_back(p_element);
}

void GUIManager::Shutdown()
{
	m_elements.clear();
	delete m_instance;
	m_instance = nullptr;
}

