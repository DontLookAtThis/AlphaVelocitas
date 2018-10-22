
// This Include
#include "GameClasses.h"

// Engine Include
#include "Engine/SceneMgr.h"
#include "Engine/Scene.h"
#include "Engine/RigidBody2D.h"
#include "Engine/SpriteRender.h"
#include "Engine/Debug.h"
#include "Engine/Input.h"

CCheckPoint::CCheckPoint()
{
	//m_name = "CheckPoint";
	m_tag = "CheckPoint";

	m_spriteRender = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();
}

CCheckPoint::~CCheckPoint()
{}

void CCheckPoint::BeginPlay()
{
	__super::BeginPlay();
	
	b2World* world = m_Scene->GetWorld();
	m_rigidBody->CreateBody(world, b2_staticBody, false, true);
	m_rigidBody->GetBody()->GetFixtureList()->SetSensor(true);

	// Set the sprite to invisible
	m_spriteRender->SetActive(false);
}

void CCheckPoint::Update(float _tick)
{
	__super::Update(_tick);

	for (auto player : m_pursuingPlayerVec)
	{
		if (player->IsActive() == false)
		{
			RemovePlayer(player);
		}
	}
}

void CCheckPoint::OnCollisionEnter(CGameObject* CollidedObject)
{
	__super::OnCollisionEnter(CollidedObject);

	if (CSpaceShip* player = dynamic_cast<CSpaceShip*>(CollidedObject))
	{
		for (auto iter : m_pursuingPlayerVec)
		{
			if (iter == player)
			{
				CDebug::Log(player->m_name + " passed " + m_name);
				PassCheckPoint(player);
			}
		}

		// If this is the pursuing check point and a ship hits this, set the next check point as pursue check point
		if (m_raceCourse->GetPursuingCheckPoint() == this)
		{
			m_raceCourse->SetPursuingCheckPoint(
				m_raceCourse->GetNextCheckPoint(m_raceCourse->GetPursuingCheckPoint()));
		}
	}
}

void CCheckPoint::SetRaceCourse(CRaceCourse* _raceCourse)
{
	m_raceCourse = _raceCourse;
}

float CCheckPoint::GetDistanceToCheckPoint(CGameObject* _player)
{
	float distance = 0.0f;

	// Get the position of the player
	glm::vec3 playePosition = _player->m_transform.position;
	// Calculate the distance between
	distance = glm::distance(playePosition, this->m_transform.position);

	return distance;
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
	CDebug::Log(_player->m_name + " now pursuing " + m_name);
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

