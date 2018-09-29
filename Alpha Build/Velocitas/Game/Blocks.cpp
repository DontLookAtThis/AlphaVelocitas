#include "Blocks.h"

CBlocks::CBlocks(int iBlockID)
{
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();
	m_iBlockID = iBlockID;
}

CBlocks::~CBlocks()
{
}

void CBlocks::BeginPlay()
{
	__super::BeginPlay();

	/** Set the sprite for the object */
	//m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));
	//m_spriteRenderer->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));
	/** Set RigidBody */

}

void CBlocks::Update(float _tick)
{
	__super::Update(_tick);
	b2Body* myBody = Get2DBody()->GetBody();
	if (myBody)
	{
		this->m_transform.position = glm::vec3(myBody->GetPosition().x, myBody->GetPosition().y, 0.0f);
		this->m_transform.rotation.z = myBody->GetAngle() * 180.0f / b2_pi;
	}
}

CRigiBody2D * CBlocks::Get2DBody()
{
	if (GetComponent<CRigiBody2D>())
	{
		return GetComponent<CRigiBody2D>();
	}
	else
	{
		return nullptr;
	}
}
