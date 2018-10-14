#pragma once
#include "Engine/Scene.h"

// Forward Declare
class CSpaceShip;
class CRaceCourse;
class CDeathSensor;

class CConnectionMenu : public CScene
{
public:
	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;
	virtual void ResetScene() override;

private:

	bool Player1Connected;
	bool Player2Connected;
	bool Player3Connected;
	bool Player4Connected;

	int ReadyCount = 0;

	CGameObject* Player1;
	CGameObject* Player2;
	CGameObject* Player3;
	CGameObject* Player4;
};