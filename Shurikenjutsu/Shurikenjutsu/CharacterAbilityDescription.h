#ifndef CHARACHTERABILITYDESCRIPTION_H_
#define CHARACHTERABILITYDESCRIPTION_H_
#include <vector>

class MenuItem;
class GUIText;
class ToolTipPopUp;
class CharacterAbilityDescription
{
public:
	CharacterAbilityDescription();
	~CharacterAbilityDescription();

	void Initialize(int p_ninjaIndex);
	void Update();
	void Shutdown();
	void Render();
private:
	ToolTipPopUp* m_FirstText;
	ToolTipPopUp* m_SecondText;
	ToolTipPopUp* m_ThirdText;
	ToolTipPopUp* m_FourthText;
	MenuItem* m_FirstPic;
	MenuItem* m_SecondPic;
	MenuItem* m_ThirdPic;
	MenuItem* m_FourthPic;
	MenuItem *m_abilityBarBG;
	std::vector<GUIText*> m_keyBinds;
};

#endif