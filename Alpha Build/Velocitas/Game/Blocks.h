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

class CBlocks : public CGameObject
{
public:
	CBlocks(int iBlockID);
	~CBlocks();
	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	CRigiBody2D* Get2DBody();
	CSpriteRender* m_spriteRenderer;

private:
	CRigiBody2D * m_rigidBody;

	int m_iBlockID;
	
};



