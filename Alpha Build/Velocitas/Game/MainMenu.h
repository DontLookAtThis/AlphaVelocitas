#pragma once
#include "Engine/Scene.h"

// Forward Declare
class CSpaceShip;
class CRaceCourse;
class CDeathSensor;

class CMainMenu : public CScene
{
public:
	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;
	virtual void ResetScene() override;



private:

	CGameObject* Button1;
	CGameObject* Button2;
	CGameObject* Button3;
	CTextLabel* Play;
	CTextLabel* Quit;
	CTextLabel* Velocitas;

	float m_mouseX;
	float m_mouseY;
};