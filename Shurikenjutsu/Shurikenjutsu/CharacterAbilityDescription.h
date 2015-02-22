#ifndef CHARACHTERABILITYDESCRIPTION_H_
#define CHARACHTERABILITYDESCRIPTION_H_

class GUIText;
class MenuItem;
class CharacterAbilityDescription
{
public:
	CharacterAbilityDescription();
	~CharacterAbilityDescription();

	void Initialize(int p_ninjaIndex);
	void Shutdown();
	void Render();
private:
	GUIText* m_FirstText;
	GUIText* m_SecondText;
	GUIText* m_ThirdText;
	GUIText* m_FourthText;
	MenuItem* m_FirstPic;
	MenuItem* m_SecondPic;
	MenuItem* m_ThirdPic;
	MenuItem* m_FourthPic;

};

#endif