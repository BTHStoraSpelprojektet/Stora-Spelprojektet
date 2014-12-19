#include "SmokeBombManager.h"


bool SmokeBombManager::Initialize(RakNet::RakPeerInterface *p_serverPeer)
{

	m_serverPeer = p_serverPeer;

	return true;
}
void SmokeBombManager::Shutdown()
{

}
void SmokeBombManager::Update(double p_deltaTime)
{
	for (unsigned int i = 0; i < m_smokeBombs.size(); i++)
	{
		m_smokeBombs[i].lifeTime -= (float)p_deltaTime;

		if (m_smokeBombs[i].lifeTime <= 0)
		{
			BroadcastEmptySmokeBombs(m_smokeBombs[i].smokeBombId);

			m_smokeBombs.erase(m_smokeBombs.begin() + i);
			i--;
		}
	}
}
void SmokeBombManager::AddSmokeBomb(float p_posX, float p_posZ)
{
	SmokeBombNet temp;
	temp.x = p_posX;
	temp.smokeBombId = GetSmokeBombUniqueId();
	temp.z = p_posZ;
	temp.lifeTime = SMOKEBOMB_DURATION;
	m_smokeBombs.push_back(temp);
	RakNet::BitStream wBitStream;
	wBitStream.Write((RakNet::MessageID)ID_SMOKEBOMB_THROW);
	wBitStream.Write(temp.smokeBombId);
	wBitStream.Write(p_posX);
	wBitStream.Write(p_posZ);
	wBitStream.Write(temp.lifeTime);


	m_serverPeer->Send(&wBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
unsigned int SmokeBombManager::GetSmokeBombUniqueId()
{
	unsigned int ID = 0;
	bool found = true;

	do
	{
		ID = (unsigned int)(rand() % 10000);
		found = false;

		for (unsigned int i = 0; i < m_smokeBombs.size(); i++)
		{
			if (m_smokeBombs[i].smokeBombId == ID)
			{
				found = true;
				break;
			}
		}

	} while (found);

	return ID;
}
void SmokeBombManager::BroadcastEmptySmokeBombs(unsigned int p_id)
{
	RakNet::BitStream bitStream;

	bitStream.Write((RakNet::MessageID)ID_SMOKEBOMB_REMOVE);
	bitStream.Write(p_id);

	m_serverPeer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_RAKNET_GUID, true);
}
std::vector<SmokeBombNet> SmokeBombManager::GetSmokeBombs()
{
	return m_smokeBombs;
}