#pragma once

// Derive Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigiBody2D;

class CSpaceShip : public CGameObject
{
public:
	CSpaceShip(int playerID);
	~CSpaceShip();
	bool bInputEnabled;
	bool bHasBeenFired;
	bool bIsLoaded;
	bool bIsHeld;	
	bool bControllerInput;
	int CurrentItem;
	float m_fCurrentRotation;

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	void MovementChecks();
	void SetIsController(bool _bIsController);
	CRigiBody2D* Get2DBody();

	// Check if the player still alive
	bool IsAlive() const;

	// Function for the player's placement in the RaceCourse
	void AddCheckPointPassed();
	void ResetCheckPointPassed();
	int GetCheckPointPassed() const;
	void Die();

	CSpriteRender* m_spriteRenderer;
	CSpriteRender* m_GravityWell;
	int iScore = 0;
	float fMovementSpeed;
private:
	void Movement(float _tick);
	void Movement(bool bLeft, bool bRight, bool bUp, bool bDown);
	void MouseMovement(float MouseX, float MouseY);
	void RotateVecotr(b2Vec2& Vector, float fDeg);
	void UseItem();
	CRigiBody2D* m_rigidBody;
	b2Vec2 m_FacingDirection;

	bool bUpPressed;
	bool bDownPressed;
	bool bLeftPressed;
	bool bRightPressed;
	bool bFirePressed;
	int m_iPlayerID;

	//TIMERS
	float m_fInputReEnabletime;
	float m_fGravityWellDuration;

	int m_checkPointPassed;
};

