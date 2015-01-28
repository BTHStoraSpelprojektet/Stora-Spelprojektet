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
	GraphicsEngine::TurnOffDepthStencil();
	GraphicsEngine::TurnOnAlphaBlending();
	for (unsigned int i = 0; i < m_elements.size(); i++)
	{
		GraphicsEngine::RenderGUI(m_elements[i]->GetWorldMatrix(), m_elements[i]->GetTexture());
	}
	for (unsigned int i = 0; i < m_elementsColor.size(); i++)
	{
		GraphicsEngine::RenderGUIColor(m_elementsColor[i]->GetWorldMatrix(), m_elementsColor[i]->GetColor());
	}

	GraphicsEngine::TurnOffAlphaBlending();
	GraphicsEngine::TurnOnDepthStencil();
	m_elements.clear();
	m_elementsColor.clear();

	for (unsigned int i = 0; i < m_texts.size(); i++)
	{
		GraphicsEngine::RenderText(m_texts[i]->GetText(), m_texts[i]->GetSize(), m_texts[i]->GetPositionX(), m_texts[i]->GetPositionY(), m_texts[i]->GetColor());
	}
	m_texts.clear();

	if (m_texts2.size() < 0)
	{
		GraphicsEngine::RenderText2(m_texts2[0]->GetText(), m_texts2[0]->GetSize(), m_texts2[0]->GetPositionX(), m_texts2[0]->GetPositionY(), m_texts2[0]->GetColor(), FW1_STATEPREPARED);
		for (unsigned int i = 1; i < m_texts2.size() - 1; i++)
		{
			GraphicsEngine::RenderText2(m_texts2[i]->GetText(), m_texts2[i]->GetSize(), m_texts2[i]->GetPositionX(), m_texts2[i]->GetPositionY(), m_texts2[i]->GetColor(), FW1_IMMEDIATECALL);
		}
		GraphicsEngine::RenderText2(m_texts2[m_texts2.size() - 1]->GetText(), m_texts2[m_texts2.size() - 1]->GetSize(), m_texts2[m_texts2.size() - 1]->GetPositionX(), m_texts2[m_texts2.size() - 1]->GetPositionY(), m_texts2[m_texts2.size() - 1]->GetColor(), FW1_IMMEDIATECALL);
		m_texts2.clear();
	}
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

void GUIManager::AddToRenderQueue2(GUIText* p_text)
{
	m_texts2.push_back(p_text);
}

void GUIManager::Shutdown()
{
	m_elements.clear();
	delete m_instance;
	m_instance = nullptr;
}

