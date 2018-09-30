#pragma once

// Inherited Include
#include "Engine/GameObject.h"

// Forward Declare
class CCheckPoint;

class CRaceCourse : public CGameObject
{

public:

	CRaceCourse();
	virtual ~CRaceCourse();

	void NextCheckPoint(CGameObject* _player, CCheckPoint* _currCheckPoint);


private:

	// A race course contain all the check points in the course
	std::vector<CCheckPoint*> m_vCheckPoints;


};