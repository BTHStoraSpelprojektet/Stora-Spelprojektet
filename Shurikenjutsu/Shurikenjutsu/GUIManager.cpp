#include "GUIManager.h"
#include "GUIText.h"
#include "GUIElement.h"
#include "GraphicsEngine.h"
#include "FW1FontWrapper.h"

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
	for (unsigned int i = 0; i < m_elements.size(); i++)
	{
		GraphicsEngine::RenderGUI(m_elements[i]->GetWorldMatrix(), m_elements[i]->GetTexture(), m_elements[i]->GetOpacity());
	}

	if (m_texts.size() > 0)
	{
		for (unsigned int i = 0; i < m_texts.size(); i++)
		{
			GraphicsEngine::AnalyzeText(m_texts[i]->GetLayout(), m_texts[i]->GetPositionX(), m_texts[i]->GetPositionY(), m_texts[i]->GetColor(), 0);
		}

		GraphicsEngine::RenderTextGeometry(FW1_RESTORESTATE);

	}

	m_elements.clear();
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