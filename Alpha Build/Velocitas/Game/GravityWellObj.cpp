#include"GravityWellObj.h"
#include "ItemCube.h"
#include "SpaceShip.h"
#include "Engine/Time.h"
#include "Engine/Scene.h"
#include "Engine/GameObject.h"

CGravityWell::CGravityWell(float Strength)
{
	this->m_transform.scale = glm::vec3(0.2f, 0.2f, 0.2f);
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_spriteGravityWell = CreateComponent<CSpriteRender>();
	m_spriteRenderer->SetSprite("Block");
	m_spriteGravityWell->SetSprite("Gravity");
	m_spriteGravityWell->xMultiplier = (5.5f / 0.2f);
	m_spriteGravityWell->yMultiplier = (5.5f / 0.2f);
	m_rigidBody = CreateComponent<CRigiBody2D>();
	m_tag = "GravityWell";
	bHit = false;
	m_Strength = Strength;
}

CGravityWell::~CGravityWell()
{

}

void CGravityWell::BeginPlay()
{
	__super::BeginPlay();
	m_rigidBody->CreateGravityWell(m_Scene->GetWorld(), 5.0f, true, m_Strength);
}

void CGravityWell::Update(float _tick)
{
	__super::Update(_tick);

}

CRigiBody2D * CGravityWell::Get2DBody()
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

void CGravityWell::OnCollisionEnter(CGameObject * CollidedObject)
{

}

void CGravityWell::OnColliisionExit(CGameObject * CollidedObject)
{

}