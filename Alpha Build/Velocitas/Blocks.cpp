#include "Blocks.h"

CBlocks::CBlocks(int iBlockID)
{
	m_spriteRenderer = CreateComponent<CSpriteRenderComponent>();
	m_rigidBody = CreateComponent<CRigiBody2DComponent>();
	m_iBlockID = iBlockID;
}

CBlocks::~CBlocks()
{
}

void CBlocks::InitializeObject()
{
	__super::InitializeObject();

	/** Set the sprite for the object */
	m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));
	m_spriteRenderer->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));
	/** Set RigidBody */

}

void CBlocks::Update(float _tick)
{
}
