#include "GUIManager.h"
#include "GUIText.h"
#include "GUIElementColor.h"
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
		GraphicsEngine::GetInstance()->RenderGUI(m_elements[i]->GetWorldMatrix(), m_elements[i]->GetTexture());
	}

	for (unsigned int i = 0; i < m_elementsColor.size(); i++)
	{
		GraphicsEngine::GetInstance()->RenderGUIColor(m_elementsColor[i]->GetWorldMatrix(), m_elementsColor[i]->GetColor());
	}

	if (m_texts.size() > 0)
	{
		for (unsigned int i = 0; i < m_texts.size(); i++)
		{
			GraphicsEngine::GetInstance()->AnalyzeText(m_texts[i]->GetLayout(), m_texts[i]->GetPositionX(), m_texts[i]->GetPositionY(), m_texts[i]->GetColor(), 0);
		}

		GraphicsEngine::GetInstance()->RenderTextGeometry(FW1_RESTORESTATE);

	}

	m_elements.clear();
	m_elementsColor.clear();
	m_texts.clear();
}

void GUIManager::AddToRenderQueue(GUIElement* p_element)
{
	m_elements.push_back(p_element);
}

void GUIManager::AddToRenderQueueColor(GUIElementColor* p_element)
{
	m_elementsColor.push_back(p_element);
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