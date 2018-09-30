#pragma once

// Derive Include
#include "Engine\Scene.h"
#include "Engine\TextLabel.h"

class CSpaceShip;

class CGameOver : public CScene
{
public:

	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;
	CTextLabel* Gameover;
private:

};