#ifndef GUIMANAGER_H_
#define GUIMANAGER_H_

#include <vector>
#include "GraphicsEngine.h"
#include "GUIElement.h"

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

private:
	static GUIManager* m_instance;
	GUIManager();
	~GUIManager();

	std::vector<GUIElement*> m_elements;
};

#endif

