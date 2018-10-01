#pragma once

// Inherited Include
#include "Engine/GameObject.h"

// Forward Declare
class CCheckPoint;
class CSpaceShip;

class CRaceCourse : public CGameObject
{

public:

	CRaceCourse();
	virtual ~CRaceCourse();

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;

	void NextCheckPoint(CGameObject* _player, CCheckPoint* _currCheckPoint);

	void AddCheckPoint(CCheckPoint* _checkPoint);

	void RefreshPlacement(CCheckPoint* _checkPoint);
	void TryAppendPlacement(CCheckPoint* _checkPoint);

	CCheckPoint* GetPreviousCheckPoint(CCheckPoint* _currCheckPoint) const;
	CCheckPoint* GetNextCheckPoint(CCheckPoint* _currCheckPoint) const;

	CGameObject* GetFirstPlayer() const;

	void SetPursuingCheckPoint(CCheckPoint* _checkPoint);
	CCheckPoint* GetPursuingCheckPoint() const;

private:

	// A race course contain all the check points in the course
	std::vector<CCheckPoint*> m_vCheckPoints;

	CGameObject* m_firstPlayer;
	std::queue<CSpaceShip*> m_qPlacement;

	CCheckPoint* m_pursuingCheckPoint;
};