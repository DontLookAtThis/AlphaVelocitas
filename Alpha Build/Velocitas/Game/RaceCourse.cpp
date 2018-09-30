
// Game Class Include
#include "GameClasses.h"

// Engine Include


CRaceCourse::CRaceCourse()
{

}

CRaceCourse::~CRaceCourse()
{

}

void CRaceCourse::NextCheckPoint(CGameObject* _player, CCheckPoint* _currCheckPoint)
{
	// Find the next check point in the course
	CCheckPoint* nextCheckPoint = nullptr;
	for (auto iter = m_vCheckPoints.begin(); iter != m_vCheckPoints.end(); ++iter)
	{
		if (*iter == _currCheckPoint)
		{
			if (++iter != m_vCheckPoints.end())
			{
				// To the next check point
				nextCheckPoint = *iter;
			}
			else 
			{
				// Go back to the first one
				nextCheckPoint = *(m_vCheckPoints.begin());
			}
			break;
		}
	}

	// Insert the player to the next check point to chase
	_currCheckPoint->RemovePlayer(_player);
	if (nextCheckPoint != nullptr)
	{
		nextCheckPoint->AddPlayer(_player);
	}
}
