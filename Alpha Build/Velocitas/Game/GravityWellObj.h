#pragma once


#include "Engine/Utility.h"
// Derive Include
#include "Engine/GameObject.h"
#include "Engine/Component.h"
#include "Engine/SpriteRender.h"
#include "Engine/RigidBody2D.h"
// Forward Declare
class CSpriteRender;
class CRigiBody2D;

class CGravityWell : public CGameObject
{
public:
	CGravityWell();
	~CGravityWell();
	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	CRigiBody2D* Get2DBody();
	CSpriteRender* m_spriteRenderer;
	CSpriteRender* m_spriteGravityWell;
	virtual void OnCollisionEnter(CGameObject * CollidedObject) override;
	virtual void OnColliisionExit(CGameObject * CollidedObject) override;

private:
	CRigiBody2D * m_rigidBody;
	b2Vec2 m_v2Direction;
	bool bHit;
};