#ifndef MEMORYCHECKER_H_
#define MEMORYCHECKER_H_
class MemoryChecker
{
public:
	MemoryChecker();
	~MemoryChecker();

	bool Initialize();
	void Shutdown();

	void Update();

	int GetVitrualMBUsed();
	int GetPhysicalMBUsed();
private :
	int m_virtualMBUsed;
	int m_physicalMBUsed;
};

#endif