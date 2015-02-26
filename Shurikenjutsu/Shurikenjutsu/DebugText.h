#ifndef DEBUGTEXT_H_
#define DEBUGTEXT_H_
class DebugText
{
public:
	DebugText(const DebugText&) = delete;
	DebugText& operator=(const DebugText&) = delete;

	static DebugText* GetInstance();

	bool Initialize();
	void Shutdown();

	void Update();
	void Render();

private:
	DebugText();
	~DebugText();

	static DebugText* m_instance;
};

#endif