#pragma once

// Derive Include
#include "Engine\Scene.h"
#include "Engine\TextLabel.h"
#include "TestScene.h"
class CSpaceShip;
class CTestScene;

class CGameOver : public CScene
{
public:

	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;

	CTestScene* FinalWinner;
private:

};