#include "RailgunShot.h"
#include "ItemCube.h"
#include "SpaceShip.h"
#include "Engine/Time.h"
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRender.h"
#include "Engine/RigidBody2D.h"
#include "Engine/Input.h"
#include "Engine/Scene.h"

CRailgunShot::CRailgunShot(b2Vec2 _Direction, CGameObject* User)
{
	m_transform = User->m_transform;
	this->m_transform.scale = glm::vec3(0.2f, 0.2f, 0.2f);
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_spriteRenderer->SetSprite("Block");
	m_rigidBody = CreateComponent<CRigiBody2D>();
	m_v2Direction = _Direction;
	m_user = User;
	m_rigidBody->CreateSensorCube(User->m_Scene->GetWorld(), b2_dynamicBody, true, true, 1.0f, 0.0f);
	m_tag = "Bullet";
	bHit = false;
}

CRailgunShot::~CRailgunShot()
{

}

void CRailgunShot::BeginPlay()
{
	__super::BeginPlay();
	m_v2Direction *= 2.0f;
	Get2DBody()->GetBody()->ApplyLinearImpulseToCenter(m_v2Direction, true);
	
}

void CRailgunShot::Update(float _tick)
{
	__super::Update(_tick);
}

CRigiBody2D * CRailgunShot::Get2DBody()
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

void CRailgunShot::OnCollisionEnter(CGameObject * CollidedObject)
{
	if (bHit == false)
	{
		if (CollidedObject->m_tag == "Player" && m_user != CollidedObject)
		{
			if (CSpaceShip* ship = dynamic_cast<CSpaceShip*>(CollidedObject))
			{
				ship->bInputEnabled = false;
				bHit = true;
				this->SetActive(false);
			}
		}
		else if (m_user != CollidedObject && CollidedObject->m_tag == "Block")
		{
			//m_user->m_Scene->GetWorld()->DestroyBody(Get2DBody()->GetBody());
			this->SetActive(false);
			bHit = true;
		}
	}
}

void CRailgunShot::OnColliisionExit(CGameObject * CollidedObject)
{

}

