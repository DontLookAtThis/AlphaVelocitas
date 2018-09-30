
// This Include
#include "GameClasses.h"

// Engine Include
#include "Engine/SceneMgr.h"
#include "Engine/Scene.h"
#include "Engine/RigidBody2D.h"
#include "Engine/SpriteRender.h"
#include "Engine/Debug.h"

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
		for (auto iter : m_pursuingPlayerVec)
		{
			if (iter == player)
			{
				CDebug::Log(player->m_name + " passed " + m_name);
				PassCheckPoint(player);
			}
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

