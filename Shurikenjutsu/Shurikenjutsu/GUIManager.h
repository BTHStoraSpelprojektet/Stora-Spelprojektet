#ifndef GUIMANAGER_H_
#define GUIMANAGER_H_

#include <vector>
#include "GraphicsEngine.h"
#include "GUIElement.h"
#include "GUIElementColor.h"

class GUIElement;
class GUIElementColor;
class GUIManager
{
public:
	GUIManager(const GUIManager&) = delete;
	GUIManager& operator=(const GUIManager&) = delete;

	static GUIManager* GetInstance();

	void Shutdown();

	void Render();
	void AddToRenderQueue(GUIElement* p_element);
	void AddToRenderQueueColor(GUIElementColor* p_element);

private:
	static GUIManager* m_instance;
	GUIManager();
	~GUIManager();

	std::vector<GUIElement*> m_elements;
	std::vector<GUIElementColor*> m_elementsColor;
};

#endif

