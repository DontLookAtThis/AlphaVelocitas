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

class CGrapplingHook : public CGameObject
{
public:
	CGrapplingHook(b2Vec2 Direction, CGameObject* User);
	~CGrapplingHook();
	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	CRigiBody2D* Get2DBody();
	CSpriteRender* m_spriteRenderer;
	CSpriteRender* m_spriteRope;
	virtual void OnCollisionEnter(CGameObject * CollidedObject) override;
	virtual void OnColliisionExit(CGameObject * CollidedObject) override;

private:
	CRigiBody2D * m_rigidBody;
	b2Vec2 m_v2Direction;
	CGameObject* m_user;
	bool bHit;
	float m_fGrappleTimer;
};