#include "GrapplingHook.h"
#include "ItemCube.h"
#include "SpaceShip.h"
#include "Engine/Time.h"
#include "Engine/Scene.h"

CGrapplingHook::CGrapplingHook(b2Vec2 _Direction, CGameObject* User)
{
	m_transform = User->m_transform;
	this->m_transform.scale = glm::vec3(0.1f, 0.1f, 0.1f);
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_spriteRope = CreateComponent<CSpriteRender>();
	m_spriteRenderer->SetSprite("Block");
	m_spriteRope->SetSprite("WoodBlock");
	m_rigidBody = CreateComponent<CRigiBody2D>();
	m_v2Direction = _Direction;
	m_user = User;
	m_rigidBody->CreateSensorCube(User->m_Scene->GetWorld(), b2_dynamicBody, true, true, 1.0f, 0.0f);
	m_tag = "Bullet";
	bHit = false;
	m_fGrappleTimer = 1.0f;
}

CGrapplingHook::~CGrapplingHook()
{

}

void CGrapplingHook::BeginPlay()
{
	__super::BeginPlay();
	m_v2Direction *= 2.0f;
	Get2DBody()->GetBody()->ApplyLinearImpulseToCenter(m_v2Direction, true);

}

void CGrapplingHook::Update(float _tick)
{
	__super::Update(_tick);
	if (bHit)
	{
		CSpaceShip* ship = dynamic_cast<CSpaceShip*>(m_user);
		b2Vec2 PullDirection;
		PullDirection = b2Vec2((this->m_transform.position - ship->m_transform.position).x , (this->m_transform.position - ship->m_transform.position).y);
		PullDirection.Normalize();
		PullDirection *= 3.0f;
		ship->Get2DBody()->GetBody()->ApplyForceToCenter(PullDirection,true);
		m_fGrappleTimer -= CTime::GetInstance()->GetDeltaTime();

	}
	if (m_fGrappleTimer <= 0)
	{
		m_fGrappleTimer = 1.0f;
		this->SetActive(false);
		bHit = false;
	}
}

CRigiBody2D * CGrapplingHook::Get2DBody()
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

void CGrapplingHook::OnCollisionEnter(CGameObject * CollidedObject)
{
	if (bHit == false && this->IsActive())
	{
		if (CollidedObject->m_tag == "Block")
		{
			bHit = true;
			//this->SetActive(false);
			Get2DBody()->GetBody()->SetLinearVelocity(b2Vec2(0, 0));
		}
	}
}

void CGrapplingHook::OnColliisionExit(CGameObject * CollidedObject)
{

}