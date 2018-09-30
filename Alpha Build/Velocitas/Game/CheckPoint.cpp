
// This Include
#include "GameClasses.h"

// Engine Include
#include "Engine/SceneMgr.h"
#include "Engine/Scene.h"
#include "Engine/RigidBody2D.h"
#include "Engine/SpriteRender.h"

CCheckPoint::CCheckPoint()
{
	m_name = "CheckPoint";
	m_tag = "CheckPoint";

	m_spriteRender = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();

	b2World* world = m_Scene->GetWorld();
	m_rigidBody->CreateBody(world, b2_staticBody, false, true);
	m_rigidBody->GetBody()->GetFixtureList()->SetSensor(true);
}

CCheckPoint::~CCheckPoint()
{}

void CCheckPoint::BeginPlay()
{
	__super::BeginPlay();
	

}

void CCheckPoint::Update(float _tick)
{
	__super::Update(_tick);
	


}

void CCheckPoint::OnCollisionEnter(CGameObject* CollidedObject)
{
	__super::OnCollisionEnter(CollidedObject);
	
	if (CSpaceShip* player = dynamic_cast<CSpaceShip*>(CollidedObject))
	{
		PassCheckPoint(player);
	}
}

float CCheckPoint::GetDistanceToCheckPoint(CGameObject* _player)
{
	//float distance;

	//Transform thistrans = this->m_transform;



	//return distance;
	return 0;
}

void CCheckPoint::PassCheckPoint(CGameObject* _player)
{
	m_raceCourse->NextCheckPoint(_player, this);
}

void CCheckPoint::AddPlayer(CGameObject* _player)
{
	// Check if the player is already been added
	for (auto iter = m_pursuingPlayerVec.begin(); iter != m_pursuingPlayerVec.end(); ++iter)
	{
		if (*iter == _player)
		{
			return;
		}
	}
	// Add the player into the vector
	m_pursuingPlayerVec.push_back(_player);
}

void CCheckPoint::RemovePlayer(CGameObject* _player)
{
	for (auto iter = m_pursuingPlayerVec.begin(); iter != m_pursuingPlayerVec.end(); ++iter)
	{
		if (*iter == _player)
		{
			m_pursuingPlayerVec.erase(iter);
			return;
		}
	}
}

std::vector<CGameObject*> CCheckPoint::GetPlayerVec() const
{
	return m_pursuingPlayerVec;
}

