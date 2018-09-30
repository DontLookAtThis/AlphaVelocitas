
// This Include
#include "CheckPoint.h"

// Engine Include
#include "Engine/SceneMgr.h"
#include "Engine/Scene.h"
#include "Engine/RigidBody2D.h"
#include "Engine/SpriteRender.h"

CCheckPoint::CCheckPoint()
{
	m_spriteRender = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();

	//m_spriteRender->SetSprite()

	b2World* world = CSceneMgr::GetInstance()->GetRunningScene()->GetWorld();
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

void CCheckPoint::AddPlayer(CGameObject* _player)
{
	m_playerVec.push_back(_player);
}

void CCheckPoint::RemovePlayer(CGameObject* _player)
{
	for (auto iter = m_playerVec.begin(); iter != m_playerVec.end(); ++iter)
	{
		if (*iter == _player)
		{
			m_playerVec.erase(iter);
			return;
		}
	}
}

std::vector<CGameObject*> CCheckPoint::GetPlayerVec() const
{
	return m_playerVec;
}
