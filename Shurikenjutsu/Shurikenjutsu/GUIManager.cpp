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
		GraphicsEngine::RenderGUIColor(m_elements[i]->GetWorldMatrix(), m_elements[i]->GetColor());
	}
	GraphicsEngine::TurnOffAlphaBlending();
	GraphicsEngine::TurnOnDepthStencil();
	m_elements.clear();

	for (unsigned int i = 0; i < m_texts.size(); i++)
	{
		GraphicsEngine::RenderText(m_texts[i]->GetText(),m_texts[i]->GetSize(), m_texts[i]->GetPositionX(), m_texts[i]->GetPositionY(), m_texts[i]->GetColor());
	}
	m_texts.clear();
}

void GUIManager::AddToRenderQueue(GUIElement* p_element)
{
	m_elements.push_back(p_element);
}

void GUIManager::AddToRenderQueue(GUIText* p_text)
{
	m_texts.push_back(p_text);
}

void GUIManager::Shutdown()
{
	m_elements.clear();
	delete m_instance;
	m_instance = nullptr;
}

