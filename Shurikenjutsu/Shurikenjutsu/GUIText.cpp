#include "GUIText.h"
#include "GUIManager.h"
#include "FW1FontWrapper.h"
#include "GraphicsEngine.h"
#include "Globals.h"
#include "ConsoleFunctions.h"

GUIText::GUIText(){}
GUIText::~GUIText(){}

bool GUIText::Initialize(std::string p_text, float p_size, float p_x, float p_y, UINT32 p_color)
{
	IDWriteFactory* wf = NULL;
	GraphicsEngine::GetInstance()->GetFontWrapper()->GetDWriteFactory(&wf);
	
	wf->CreateTextFormat(
		L"Calibri",
		NULL,
		DWRITE_FONT_WEIGHT_ULTRA_BOLD,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_EXTRA_EXPANDED,
		p_size,
		L"en-us",
		&m_format
		);
	wf->Release();

	SetText(p_text);
	SetSize(p_size);
	SetPosition(p_x, p_y);
	m_color = p_color;

	return true;
}

void GUIText::Render()
{
	GUIManager::GetInstance()->AddToRenderQueue(this);
}

void GUIText::Shutdown()
{
	if (m_format != nullptr)
	{
		m_format->Release();
		m_format = nullptr;
	}

	if (m_layouts.size() > 0)
	{
		m_layouts[0]->Release();		
	}
	m_layouts.clear();
}

void GUIText::SetText(std::string p_text)
{
	std::wstring wstring;
	for (unsigned int i = 0; i < p_text.length(); ++i)
	{
		wstring += wchar_t(p_text[i]);
	}

	const wchar_t* your_result = wstring.c_str();
	m_textLength = p_text.size();

	IDWriteFactory* wf = NULL;
	GraphicsEngine::GetInstance()->GetFontWrapper()->GetDWriteFactory(&wf);
	
	if (m_layouts.size() > 0)
	{
		m_layouts[0]->Release();
		m_layouts.clear();
	}

	IDWriteTextLayout* textLayout;

	wf->CreateTextLayout(your_result, m_textLength, m_format, 0.0f, 0.0f, &textLayout);
	textLayout->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
	textLayout->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	textLayout->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	m_layouts.push_back(textLayout);

	wf->Release();
}

void GUIText::SetPosition(float p_x, float p_y)
{
	m_posx = (p_x + (GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH* 0.5f)) * GLOBAL::GetInstance().MAX_SCREEN_WIDTH / GLOBAL::GetInstance().CURRENT_SCREEN_WIDTH;
	m_posy = (-p_y + (GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT* 0.5f)) * GLOBAL::GetInstance().MAX_SCREEN_HEIGHT / GLOBAL::GetInstance().CURRENT_SCREEN_HEIGHT;

}

void GUIText::SetSize(float p_size)
{
	DWRITE_TEXT_RANGE range;
	range.length = m_textLength;
	range.startPosition = 0;
	m_layouts[0]->SetFontSize(p_size, range);
}

void GUIText::SetColor(UINT32 p_color)
{
	m_color = p_color;
}

float GUIText::GetPositionX()
{
	return m_posx;
}

float GUIText::GetPositionY()
{
	return m_posy;
}

UINT32 GUIText::GetColor()
{
	return m_color;
}

IDWriteTextLayout* GUIText::GetLayout()
{
	return m_layouts[0];
}
