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

	bool bHasBeenFired;
	bool bIsLoaded;
	bool bIsHeld;

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	void MovementChecks();
	void SetIsController(bool _bIsController);
	CRigiBody2D* Get2DBody();
	CSpriteRender* m_spriteRenderer;
private:
	void Movement();
	void Movement(bool bLeft, bool bRight, bool bUp, bool bDown);
	void MouseMovement(float MouseX, float MouseY);
	void RotateVecotr(b2Vec2& Vector, float fDeg);
	CRigiBody2D* m_rigidBody;

	bool bUpPressed;
	bool bDownPressed;
	bool bLeftPressed;
	bool bRightPressed;
	int m_iPlayerID;
	bool bControllerInput;
	float m_fCurrentRotation;
};

