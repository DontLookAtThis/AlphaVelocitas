#pragma once

//Derive Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigiBody2D;

class CDropBox : public CGameObject
{
public:
	CDropBox(CGameObject* User );
	~CDropBox();
	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	CRigiBody2D* Get2DBody();
	CSpriteRender* m_spriteRenderer;

	virtual void OnCollisionEnter(CGameObject * CollidedObject) override;
	virtual void OnColliisionExit(CGameObject * CollidedObject) override;
private:
	CRigiBody2D * m_RigidBody;
	CGameObject* m_User;
	b2Vec2 m_DeployDir;
	bool bHit;
};