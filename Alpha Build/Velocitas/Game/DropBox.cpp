#include "DropBox.h"
#include "ItemCube.h"
#include "SpaceShip.h"
#include "Engine/Time.h"
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRender.h"
#include "Engine/RigidBody2D.h"
#include "Engine/Input.h"
#include "Engine/Scene.h"

CDropBox::CDropBox( CGameObject* User)
{
	m_transform = User->m_transform;
	this->m_transform.scale = glm::vec3(0.5f, 0.5f, 0.5f);
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_spriteRenderer->SetSprite("Box");
	m_RigidBody = CreateComponent<CRigiBody2D>();
	m_User = User;
	m_RigidBody->CreateBody(User->m_Scene->GetWorld(), b2_dynamicBody, true, true, 10.0f, 0.0f);
	m_tag = "DropBox";
	bHit = false;
}

CDropBox::~CDropBox()
{
}

void CDropBox::BeginPlay()
{
	__super::BeginPlay();

	
}

void CDropBox::Update(float _tick)
{
	__super::Update(_tick);
	
}

CRigiBody2D * CDropBox::Get2DBody()
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

void CDropBox::OnCollisionEnter(CGameObject * CollidedObject)
{
	//if (CollidedObject->m_tag == "Player" )
	//{
	///*	if (CSpaceShip* ship = dynamic_cast<CSpaceShip*>(CollidedObject))
	//	{
	//		ship->fMovementSpeed = ship->fMovementSpeed / 2.0f;
	//		bHit = true;
	//		this->SetActive(false);
	//	}*/
	//}
}

void CDropBox::OnColliisionExit(CGameObject * CollidedObject)
{
}
