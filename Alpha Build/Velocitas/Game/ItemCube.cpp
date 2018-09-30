#include "ItemCube.h"
#include "SpaceShip.h"
#include "Engine/Time.h"
CItemCubes::CItemCubes(int ItemType)
{
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();
	m_ItemType = ItemType;
	m_IsTaken = false;
	ResetTimer = 5.0f;
	if (ItemType == ITEM_NONE)
	{
		m_ItemType = rand() % ((int)ITEM_END -1) + 1;
	}

}

CItemCubes::~CItemCubes()
{
}

void CItemCubes::BeginPlay()
{
	__super::BeginPlay();
}

void CItemCubes::Update(float _tick)
{
	__super::Update(_tick);
	if (m_IsTaken)
	{
		ResetTimer -= CTime::GetInstance()->GetDeltaTime();
	}
	if (ResetTimer <= 0)
	{
		m_ItemType = rand() % ((int)ITEM_END - 1) + 1;
		m_IsTaken = false;
		SetActive(true);
		ResetTimer = 5.0f;
	}
}

CRigiBody2D * CItemCubes::Get2DBody()
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

void CItemCubes::OnCollisionEnter(CGameObject * CollidedObject)
{
	if (CollidedObject->m_tag == "Player" && !m_IsTaken)
	{
		if (CSpaceShip* ship = dynamic_cast<CSpaceShip*>(CollidedObject))
		{
			if (ship->CurrentItem == ITEM_NONE)
			{
				ship->CurrentItem = m_ItemType;
				SetActive(false);
				m_IsTaken = true;
			}
		}
	}
}

void CItemCubes::OnColliisionExit(CGameObject * CollidedObject)
{

}

