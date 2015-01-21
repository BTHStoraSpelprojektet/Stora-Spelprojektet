#ifndef GUIMANAGER_H_
#define GUIMANAGER_H_

#include "GraphicsEngine.h"
#include "GUIElement.h"
#include "GUIText.h"

class GUIText;
class GUIElement;
class GUIManager
{
public:
	GUIManager(const GUIManager&) = delete;
	GUIManager& operator=(const GUIManager&) = delete;

	static GUIManager* GetInstance();

	void Shutdown();

	void Render();
	void AddToRenderQueue(GUIElement* p_element);
	void AddToRenderQueue(GUIText* p_text);

private:
	static GUIManager* m_instance;
	GUIManager();
	~GUIManager();

	std::vector<GUIElement*> m_elements;
	std::vector<GUIText*> m_texts;
};

#endif

