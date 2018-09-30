#pragma once

// Inherited Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigiBody2D;

class CCheckPoint : public CGameObject
{

public:
	
	CCheckPoint();
	virtual ~CCheckPoint();

	virtual void BeginPlay();
	virtual void Update(float _tick);


	void AddPlayer(CGameObject* _player);
	void RemovePlayer(CGameObject* _player);
	std::vector<CGameObject*> GetPlayerVec() const;

private:

	/** Compoenent */
	CSpriteRender* m_spriteRender;
	CRigiBody2D* m_rigidBody;

	
	std::vector<CGameObject*> m_playerVec;



};
