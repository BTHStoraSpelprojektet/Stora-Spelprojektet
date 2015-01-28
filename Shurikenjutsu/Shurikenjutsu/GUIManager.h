#ifndef GUIMANAGER_H_
#define GUIMANAGER_H_

#include <D3D11.h>
#include <vector>

class GUIText;
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
	void AddToRenderQueue(GUIText* p_text);
	void AddToRenderQueue2(GUIText* p_text);

private:
	static GUIManager* m_instance;
	GUIManager();
	~GUIManager();

	std::vector<GUIElement*> m_elements;
	std::vector<GUIElementColor*> m_elementsColor;
	std::vector<GUIText*> m_texts;
	std::vector<GUIText*> m_texts2;
};

#endif

