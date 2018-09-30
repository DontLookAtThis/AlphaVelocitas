#pragma once

// Inherited Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigiBody2D;
class CRaceCourse;

class CCheckPoint : public CGameObject
{

public:
	
	CCheckPoint();
	virtual ~CCheckPoint();

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	virtual void OnCollisionEnter(CGameObject* CollidedObject) override;

	void SetRaceCourse(CRaceCourse* _raceCourse);
	float GetDistanceToCheckPoint(CGameObject* _player);
	void PassCheckPoint(CGameObject* _player);
	void AddPlayer(CGameObject* _player);
	void RemovePlayer(CGameObject* _player);
	std::vector<CGameObject*> GetPlayerVec() const;

private:

	/** Compoenent */
	CSpriteRender* m_spriteRender;
	CRigiBody2D* m_rigidBody;

	// A vector of player who are chasing this check point
	std::vector<CGameObject*> m_pursuingPlayerVec;

	// The race course of the check point
	CRaceCourse* m_raceCourse;



};
