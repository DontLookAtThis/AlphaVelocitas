
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

void CCheckPoint::AddPlayer(CGameObject* _player)
{
	m_playerVec.push_back(_player);
}

std::vector<CGameObject*> CCheckPoint::GetPlayerVec() const
{
	return m_playerVec;
}
