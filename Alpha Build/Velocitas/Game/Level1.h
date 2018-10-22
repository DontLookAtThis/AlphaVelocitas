#pragma once

// Derive Include
#include "Engine/Scene.h"

// Forward Declare
class CSpaceShip;
class CRaceCourse;
class CDeathSensor;

class CLevel1 : public CScene
{
public:

	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;
	virtual void ResetScene() override;

	void CreatePowerUp(Transform Transform);
	void LoadAllGravWell();
	void LoadAllPowerUps();
	void LoadAllBlocks();
	void LoadAllPlayers();
	void LoadUserInterface();
	void Reset();
	void CheckWin();
	void CheckCurrentGadget();
	void CreateBlocks(int iBlockID, std::string Name, std::string SpriteName, Transform Transform, std::string Tag = "Block");

	//For the players
	glm::vec3 SpawnLocation1 = { -5.0f, 9.5f, 0.0f };
	glm::vec3 SpawnLocation2 = { -5.0f, 8.2f, 0.0f };
	glm::vec3 SpawnLocation3 = { -5.0f, 6.8f, 0.0f };
	glm::vec3 SpawnLocation4 = { -5.0f, 5.5f, 0.0f };

	bool IsGameWon = false;

	CRaceCourse* m_raceCourse;
	std::vector<CSpaceShip*> m_vPlayers;
	CSpaceShip* Winner;
	CSpaceShip* Ship;
	std::vector<CDeathSensor*> m_deathSensors;

private:
	CGameObject* Player1;
	CGameObject* Player2;
	CGameObject* Player3;
	CGameObject* Player4;

	CTextLabel* Player1Score;
	CTextLabel* Player2Score;
	CTextLabel* Player3Score;
	CTextLabel* Player4Score;

	CTextLabel* Player1Gadget;
	CTextLabel* Player2Gadget;
	CTextLabel* Player3Gadget;
	CTextLabel* Player4Gadget;

	std::string Gadget;

};