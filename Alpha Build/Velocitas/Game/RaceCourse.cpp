
// Game Class Include
#include "GameClasses.h"
#include "TestScene.h"

// Engine Include
#include "Engine/Debug.h"
#include "Engine/Input.h"

CRaceCourse::CRaceCourse()
{
	m_name = "RaceCourse";
	m_tag = "RaceCourse";
}

CRaceCourse::~CRaceCourse()
{
	// Clean all the object in the vector
	m_vCheckPoints.clear();
}

void CRaceCourse::BeginPlay()
{
	__super::BeginPlay();
	
	// Get the first check point of the race course
	CCheckPoint* firstCheckPoint = nullptr;
	if (!m_vCheckPoints.empty())
	{
		firstCheckPoint = m_vCheckPoints.front();
		m_pursuingCheckPoint = firstCheckPoint;
	}
	else CDebug::Log("This race course does not have any check points to work with.");

	// If the check point found
	if (firstCheckPoint)
	{
		// Try to find all the player in the scene
		std::vector<CGameObject*> playerVec = m_Scene->FindObjectWithTagAll("Player");

		// If there are players in the scene
		if (!playerVec.empty())
		{
			for (auto player : playerVec)
			{
				firstCheckPoint->AddPlayer(player);
			}
		}
		else CDebug::Log("There is no player in the scene");

		RefreshPlacement(m_pursuingCheckPoint);
	}
}

void CRaceCourse::Update(float _tick)
{
	__super::Update(_tick);
	
	RefreshPlacement(m_pursuingCheckPoint);

	if (CInput::GetInstance()->g_cKeyState[(unsigned char)'o'] == INPUT_FIRST_PRESS)
	{
		CDebug::Log("Pause");
	}
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
				nextCheckPoint = *iter++;
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

void CRaceCourse::AddCheckPoint(CCheckPoint* _checkPoint)
{
	_checkPoint->SetRaceCourse(this);
	m_vCheckPoints.push_back(_checkPoint);
}

void CRaceCourse::RefreshPlacement(CCheckPoint* _checkPoint)
{
	float cloestDistance = 10000000.0f;

	for (auto player : m_pursuingCheckPoint->GetPlayerVec())
	{
		float distance = glm::distance(player->m_transform.position, m_pursuingCheckPoint->m_transform.position);

		if (distance < cloestDistance)
		{
			cloestDistance = distance;
			m_firstPlayer = player;
		}
	}



	// Clean up the queue
// 	while (!m_qPlacement.empty())
// 	{
// 		m_qPlacement.pop();
// 	}
// 
// 	TryAppendPlacement(pursuingCheckPoint);
}

void CRaceCourse::TryAppendPlacement(CCheckPoint* _checkPoint)
{
	std::vector<CGameObject*> playerVec = _checkPoint->GetPlayerVec();
	if (!playerVec.empty())
	{

	}
	else
	{
		return;
	}
}

CCheckPoint* CRaceCourse::GetPreviousCheckPoint(CCheckPoint* _currCheckPoint) const
{
	CCheckPoint* resultCheckPoint = nullptr;

	// Get the iterator of the pursuing project
	std::vector<CCheckPoint*>::const_iterator purseIter;
	for (auto iter = m_vCheckPoints.begin(); iter != m_vCheckPoints.end(); ++iter)
	{
		if (*iter == _currCheckPoint)
		{
			purseIter = iter;
		}
	}

	if (purseIter == m_vCheckPoints.begin())
	{
		resultCheckPoint = m_vCheckPoints.back();
	}
	else
	{
		resultCheckPoint = *(purseIter--);
	}

	return resultCheckPoint;
}

CCheckPoint* CRaceCourse::GetNextCheckPoint(CCheckPoint* _currCheckPoint) const
{
	CCheckPoint* resultCheckPoint = nullptr;

	for (auto iter = m_vCheckPoints.begin(); iter != m_vCheckPoints.end(); ++iter)
	{
		if (*iter == _currCheckPoint)
		{
			if (++iter != m_vCheckPoints.end())
			{
				// To the next check point
				resultCheckPoint = *iter++;
			}
			else
			{
				// Go back to the first one
				resultCheckPoint = *(m_vCheckPoints.begin());
			}
			break;
		}
	}


	// Get the iterator of the pursuing project
// 	std::vector<CCheckPoint*>::const_iterator purseIter;
// 	for (auto iter = m_vCheckPoints.begin(); iter != m_vCheckPoints.end(); ++iter)
// 	{
// 		if (*iter == _currCheckPoint)
// 		{
// 			purseIter = iter;
// 		}
// 	}
// 
// 	if (*purseIter == m_vCheckPoints.back())
// 	{
// 		resultCheckPoint = m_vCheckPoints.front();
// 	}
// 	else
// 	{
// 		resultCheckPoint = *(purseIter++);
// 	}

	return resultCheckPoint;
}

CGameObject* CRaceCourse::GetFirstPlayer() const
{
	return m_firstPlayer;
}

void CRaceCourse::SetPursuingCheckPoint(CCheckPoint* _checkPoint)
{
	m_pursuingCheckPoint = _checkPoint;
}

CCheckPoint* CRaceCourse::GetPursuingCheckPoint() const
{
	return m_pursuingCheckPoint;
}
