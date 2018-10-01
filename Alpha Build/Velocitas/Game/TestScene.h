#pragma once

// Derive Include
#include "Engine/Scene.h"

// Forward Declare
class CSpaceShip;
class CRaceCourse;

class CTestScene : public CScene
{
public:

	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;

	void CreateBlocks();
	void CreatePigs();
	void CreateBirdies();
	void CreatePlayers();

	void LoadAllBlocks();
	void LoadAllPlayers();
	void LoadUserInterface();
	void Reset();
	void CheckWin();
	void SetScores();
	void CreateBlocks(int iBlockID, std::string Name, std::string SpriteName, Transform Transform, std::string Tag = "Block");

	//For the players
	glm::vec3 SpawnLocation1 = { 12.0f, 0.0f, 0.0f };
	glm::vec3 SpawnLocation2 = { 13.0f, 0.0f, 0.0f };
	glm::vec3 SpawnLocation3 = { 14.0f, 0.0f, 0.0f };
	glm::vec3 SpawnLocation4 = { 15.0f, 0.0f, 0.0f };

	bool IsGameWon = false;

	CRaceCourse* m_raceCourse;
	std::vector<CSpaceShip*> m_vPlayers;
	
private:
	CGameObject* Player1;
	CGameObject* Player2;
	CGameObject* Player3;
	CGameObject* Player4;

	CTextLabel * Player1Score;
	CTextLabel * Player2Score;
	CTextLabel * Player3Score;
	CTextLabel * Player4Score;

};