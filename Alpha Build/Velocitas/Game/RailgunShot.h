#pragma once

#include "Engine/Utility.h"
// Derive Include
#include "Engine/GameObject.h"
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRender.h"
#include "Engine/RigidBody2D.h"
#include "Engine/Input.h"
// Forward Declare
class CSpriteRender;
class CRigiBody2D;

class CRailgunShot : public CGameObject
{
public:
	CRailgunShot(b2Vec2 Direction, CGameObject* User);
	~CRailgunShot();
	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	CRigiBody2D* Get2DBody();
	CSpriteRender* m_spriteRenderer;

	virtual void OnCollisionEnter(CGameObject * CollidedObject) override;
	virtual void OnColliisionExit(CGameObject * CollidedObject) override;

private:
	CRigiBody2D * m_rigidBody;
	b2Vec2 m_v2Direction;
	CGameObject* m_user;
};