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
	void Reset();
	void AddScore();
	void CheckWin();
	void CreateBlocks(int iBlockID, std::string Name, std::string SpriteName, Transform Transform, std::string Tag = "Block");
	
	glm::vec3 SpawnLocation1 = { 12.0f, 0.0f, 0.0f };
	glm::vec3 SpawnLocation2 = { 13.0f, 0.0f, 0.0f };
	glm::vec3 SpawnLocation3 = { 14.0f, 0.0f, 0.0f };
	glm::vec3 SpawnLocation4 = { 15.0f, 0.0f, 0.0f };

	bool IsGameWon = false;

	CRaceCourse* m_raceCourse;
	std::vector<CSpaceShip*> m_vPlayers;
	

private:
	int iScore;

};