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


	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	void MovementChecks();
	void SetIsController(bool _bIsController);
	CRigiBody2D* Get2DBody();
	CSpriteRender* m_spriteRenderer;
	CSpriteRender* m_GravityWell;
	int iScore = 0;
private:
	void Movement(float _tick);
	void Movement(bool bLeft, bool bRight, bool bUp, bool bDown);
	void MouseMovement(float MouseX, float MouseY);
	void RotateVecotr(b2Vec2& Vector, float fDeg);
	void UseItem();
	CRigiBody2D* m_rigidBody;
	b2Vec2 m_FacingDirection;

	float fMovementSpeed;
	bool bUpPressed;
	bool bDownPressed;
	bool bLeftPressed;
	bool bRightPressed;
	bool bFirePressed;
	int m_iPlayerID;
	float m_fCurrentRotation;
	//TIMERS
	float m_fInputReEnabletime;
	float m_fGravityWellDuration;


};

