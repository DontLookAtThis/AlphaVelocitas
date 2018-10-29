// This Include
#include "Level1.h"

// Inlcude the game classes
#include "Game/GameClasses.h"
#include "Engine/Camera.h"
#include "Engine/RigidBody2D.h"
#include "Engine/SpriteRender.h"
#include "Engine/AssetMgr.h"
#include "Blocks.h"
#include "RaceCourse.h"
#include "CheckPoint.h"
#include "DeathSensor.h"
#include "ContactListener.h"
#include "Engine/SceneMgr.h"
#include "Game/SpaceShip.h"
#include "Game/ItemCube.h"
#include "Game/DropBox.h"
#include "Engine/TextLabel.h"
#include "Game/GravityWellObj.h"
#include "Engine/Debug.h"
#include "Engine/Time.h"

//Includes
#include <memory>
#include "Engine/Sound.h"

void CLevel1::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */

	this->m_sceneName = "Level1";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();

	/** Create game objects in the scenes */
	//Creating Sound
	CSound::GetInstance()->Init();
	CSound::GetInstance()->AddSound();
	CSound::GetInstance()->SoundMgr->playSound(CSound::GetInstance()->bgMusic, 0, false, &CSound::GetInstance()->BgMusicChannel);
	CSound::GetInstance()->BgMusicChannel->setVolume(0.1f);

	//BACKGROUND----------------------------------------------------
	CGameObject* BackGround = new CBlocks(1);
	BackGround->SetWorld(this);
	BackGround->m_name = "BackGround";
	BackGround->m_tag = "BackGround";
	BackGround->m_transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
	BackGround->m_transform.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	this->m_vGameObj.push_back(BackGround);
	BackGround->GetComponent<CSpriteRender>()->SetSprite("Background");

	CGameObject* BackGround1 = new CBlocks(2);
	BackGround1->SetWorld(this);
	BackGround1->m_name = "BackGround1";
	BackGround1->m_tag = "BackGround1";
	BackGround1->m_transform.position = glm::vec3(0.0f, -22.0f, -1.0f);
	BackGround1->m_transform.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	this->m_vGameObj.push_back(BackGround1);
	BackGround1->GetComponent<CSpriteRender>()->SetSprite("Background");

	CGameObject* BackGround2 = new CBlocks(2);
	BackGround2->SetWorld(this);
	BackGround2->m_name = "BackGround1";
	BackGround2->m_tag = "BackGround1";
	BackGround2->m_transform.position = glm::vec3(-22.0f, -22.0f, -1.0f);
	BackGround2->m_transform.scale = glm::vec3(2.0f, 3.0f, 2.0f);
	this->m_vGameObj.push_back(BackGround2);
	BackGround2->GetComponent<CSpriteRender>()->SetSprite("Background");
	//--------------------------------------------------------------


	/** Configurate Race Course */
	{
		m_raceCourse = new CRaceCourse();
		m_raceCourse->SetWorld(this);
		m_vGameObj.push_back(m_raceCourse);

		CGameObject* checkPoint_1 = new CCheckPoint();
		checkPoint_1->SetWorld(this);
		m_vGameObj.push_back(checkPoint_1);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_1);
		checkPoint_1->m_name = "CheckPoint_1";
		checkPoint_1->m_transform.position = glm::vec3(7.0f, 7.5f, 0.0f);
		checkPoint_1->m_transform.scale = glm::vec3(1.0f, 4.0f, 0.0f);

		CGameObject* checkPoint_2 = new CCheckPoint();
		checkPoint_2->SetWorld(this);
		m_vGameObj.push_back(checkPoint_2);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_2);
		checkPoint_2->m_name = "CheckPoint_2";
		checkPoint_2->m_transform.position = glm::vec3(4.0f, -26.0f, 0.0f);
		checkPoint_2->m_transform.scale = glm::vec3(1.0f, 4.0f, 0.0f);

		CGameObject* checkPoint_3 = new CCheckPoint();
		checkPoint_3->SetWorld(this);
		m_vGameObj.push_back(checkPoint_3);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_3);
		checkPoint_3->m_name = "CheckPoint_3";
		checkPoint_3->m_transform.position = glm::vec3(-23.0f, -23.0f, 0.0f);
		checkPoint_3->m_transform.scale = glm::vec3(1.0f, 4.0f, 0.0f);

		CGameObject* checkPoint_4 = new CCheckPoint();
		checkPoint_4->SetWorld(this);
		m_vGameObj.push_back(checkPoint_4);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_4);
		checkPoint_4->m_name = "CheckPoint_4";
		checkPoint_4->m_transform.position = glm::vec3(-23.0f, 7.0f, 0.0f);
		checkPoint_4->m_transform.scale = glm::vec3(1.0f, 6.0f, 0.0f);

		CGameObject* checkPoint_5 = new CCheckPoint();
		checkPoint_5->SetWorld(this);
		m_vGameObj.push_back(checkPoint_5);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_5);
		checkPoint_5->m_name = "CheckPoint_5";
		checkPoint_5->m_transform.position = glm::vec3(-16.0f, -9.5f, 0.0f);
		checkPoint_5->m_transform.scale = glm::vec3(1.0f, 5.0f, 0.0f);

		CGameObject* checkPoint_6 = new CCheckPoint();
		checkPoint_6->SetWorld(this);
		m_vGameObj.push_back(checkPoint_6);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_6);
		checkPoint_6->m_name = "CheckPoint_6";
		checkPoint_6->m_transform.position = glm::vec3(-5.0f, 7.5f, 0.0f);
		checkPoint_6->m_transform.scale = glm::vec3(1.0f, 4.0f, 0.0f);
	}

	/** Configurate Death Sensor */
	{
		CDeathSensor* sensorLeft = new CDeathSensor(CAM_LEFT);
		sensorLeft->SetWorld(this);
		m_vGameObj.push_back(sensorLeft);
		m_deathSensors.push_back(sensorLeft);

		CDeathSensor* sensorRight = new CDeathSensor(CAM_RIGHT);
		sensorRight->SetWorld(this);
		m_vGameObj.push_back(sensorRight);
		m_deathSensors.push_back(sensorRight);

		CDeathSensor* sensorTop = new CDeathSensor(CAM_TOP);
		sensorTop->SetWorld(this);
		m_vGameObj.push_back(sensorTop);
		m_deathSensors.push_back(sensorTop);

		CDeathSensor* sensorBottom = new CDeathSensor(CAM_BOTTOM);
		sensorBottom->SetWorld(this);
		m_vGameObj.push_back(sensorBottom);
		m_deathSensors.push_back(sensorBottom);
	}

	LoadAllPlayers();
	LoadAllGravWell();
	LoadAllBlocks();
	LoadUserInterface();
	LoadAllPowerUps();
}

void CLevel1::BeginPlay()
{
	__super::BeginPlay();

	for (auto senser : m_deathSensors)
	{
		senser->SetShrinkPercentage(1.0f);
	}
}

void CLevel1::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	CheckCurrentGadget();

	// Make the camera to the first players position
	if (CGameObject* firstPlayer = m_raceCourse->GetFirstPlayer())
	{
		if (m_mainCamera->m_cameraPosition != firstPlayer->m_transform.position)
		{
			glm::vec2 playerPos = { firstPlayer->m_transform.position.x, firstPlayer->m_transform.position.y };
			glm::vec2 camPos = { m_mainCamera->m_cameraPosition.x, m_mainCamera->m_cameraPosition.y };
			glm::vec2 direction = playerPos - camPos;
			glm::vec2 moveAmount = direction * 0.1f;

			m_mainCamera->m_cameraPosition += glm::vec3(moveAmount, 0.0f);
		}
	}

	int aliveCount = 0;
	for (auto player : m_vPlayers)
	{
		if (player->IsAlive())
		{
			aliveCount++;
		}
	}
	if (aliveCount != 4)
	{
		float currentShrinkPercent = m_deathSensors[0]->GetShrinkPercentage();
		for (auto deathSensor : m_deathSensors)
		{
			if (deathSensor->GetShrinkPercentage() > 0.65f)
			{
				deathSensor->SetShrinkPercentage(currentShrinkPercent - ((1.0 / 90.0f) * 0.65f * CTime::GetInstance()->GetDeltaTime()));
			}
		}
	}

	// Check the win condition
	CheckWin();
}

void CLevel1::ResetScene()
{
	__super::ResetScene();

	m_vPlayers.clear();
	m_vPlayers.resize(0);

	m_deathSensors.clear();
	m_deathSensors.resize(0);

}

void CLevel1::CreatePowerUp(Transform Transform)
{
	CGameObject* ItemCube = new CItemCubes(ITEM_NONE);
	ItemCube->SetWorld(this);
	ItemCube->m_name = "ItemCube1";
	ItemCube->m_tag = "ItemCube";
	ItemCube->m_transform.position = Transform.position;
	ItemCube->m_transform.rotation = Transform.rotation;
	ItemCube->m_transform.scale = Transform.scale; //glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube);
	ItemCube->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);

}

void CLevel1::LoadAllGravWell()
{
	CGameObject* GravityWell1 = new CGravityWell(0.8f);
	GravityWell1->SetWorld(this);
	GravityWell1->m_name = "GravityWell1";
	GravityWell1->m_transform.position = glm::vec3(-16.0f, -5.5f, 0.0f);
	GravityWell1->m_transform.scale = glm::vec3(0.13f, 0.13f, 0.0f);
	Instantiate(GravityWell1);

	CGameObject* GravityWell2 = new CGravityWell(0.8f);
	GravityWell2->SetWorld(this);
	GravityWell2->m_name = "GravityWell1";
	GravityWell2->m_transform.position = glm::vec3(-12.0f, -18.0f, 0.0f);
	GravityWell2->m_transform.scale = glm::vec3(0.15f, 0.15f, 0.0f);
	Instantiate(GravityWell2);

	CGameObject* GravityWell3 = new CGravityWell(0.6f);
	GravityWell3->SetWorld(this);
	GravityWell3->m_name = "GravityWell1";
	GravityWell3->m_transform.position = glm::vec3(7.0f, -19.0f, 0.0f);
	GravityWell3->m_transform.scale = glm::vec3(0.14f, 0.14f, 0.0f);
	Instantiate(GravityWell3);
}

void CLevel1::LoadAllPowerUps()
{
	//start point
	CreatePowerUp({ {0.0f, 9.5f, 0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ {0.0f, 8.2f, 0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ {0.0f, 6.8f, 0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ {0.0f, 5.5f, 0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	//On second turn on th right
	CreatePowerUp({ {8.0f,-4.8f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ {6.5f,-4.8f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ {5.0f,-4.8f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ {3.5f,-4.8f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });

	//Bottem turn on the right
	CreatePowerUp({ { 3.0f,-28.5f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ { 3.0f,-27.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ { 3.0f,-25.5f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ { 3.0f,-24.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });

	//Straight on left
	CreatePowerUp({ { -28.8f,-15.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ { -27.3f,-15.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ { -25.8f,-15.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ { -24.3f,-15.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });

	//After hairpin
	CreatePowerUp({ {-21.5f,-4.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f}  });
	CreatePowerUp({ {-20.25f,-4.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f} });
	CreatePowerUp({ {-18.9f,-4.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f}  });
	CreatePowerUp({ {-17.5f,-4.0f,0.0f},{0.0f,0.0f,0.0f},{0.4f, 0.12f, 0.5f}  });

}

void CLevel1::LoadAllBlocks()
{
	//Outer------------------
	//Starting Lane
	CreateBlocks(1, "TopOuterLeft", "6Block", { {-2.0f,11.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "TopOuterRight", "11Block", { {5.5f,11.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });

	//First turn on the right
	CreateBlocks(1, "OuterRight1", "9Block", { {13.0f,7.5f,0.0f},{0.0f,0.0f,-55.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterRight2", "11Block", { {12.5f,-0.1f,0.0f},{0.0f,0.0f,55.0f},{0.5f,0.5f,0.5f} });

	//Second turn on the right
	CreateBlocks(1, "OuterRight3", "5Block", { {9.43f,-6.8f,0.0f},{0.0f,0.0f,90.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterRight5", "7Block", { {9.1f,-16.7f,0.0f},{0.0f,0.0f,45.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterRight4", "6Block", { {10.40f,-11.9f,0.0f},{0.0f,0.0f,110.0f},{0.5f,0.5f,0.5f} });

	//Third turn on the right 
	CreateBlocks(1, "OuterRight6", "8Block", { {8.1f,-22.4f,0.0f},{0.0f,0.0f,110.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterRight7", "8Block", { {6.5f,-28.0f,0.0f},{0.0f,0.0f,35.0f},{0.5f,0.5f,0.5f} });

	//Bottem turn on the right 
	CreateBlocks(1, "OuterRight8", "11Block", { {-1.5f,-28.4f,0.0f},{0.0f,0.0f,-20.0f},{0.5f,0.5f,0.5f} });

	//Bottem turn on the middle
	CreateBlocks(1, "OuterRight9", "5Block", { {-9.0f,-25.68f,0.0f},{0.0f,0.0f,-20.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterMiddle10", "10Block", { {-15.7f,-26.5f,0.0f},{0.0f,0.0f,20.0f},{0.5f,0.5f,0.5f} });

	//HairPin
	CreateBlocks(1, "OuterLeft15", "10Block", { {-26.7f,8.6f,0.0f},{0.0f,0.0f,45.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterLeft16", "10Block", { {-19.5f,8.6f,0.0f},{0.0f,0.0f,-45.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterLeft16", "1Block", { {-23.1f,12.2f,0.0f},{0.0f,0.0f,-45.0f},{0.5f,0.5f,0.5f} });

	//Bottem turn on the left
	CreateBlocks(1, "OuterLeft11", "11Block", { {-25.1f,-26.35f,0.0f},{0.0f,0.0f,-20.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterLeft12", "11Block", { {-30.1f,-19.45f,0.0f},{0.0f,0.0f,90.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterLeft13", "11Block", { {-30.1f,-8.45f,0.0f},{0.0f,0.0f,90.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterLeft14", "10Block", { {-30.1f,0.45f,0.0f},{0.0f,0.0f,90.0f},{0.5f,0.5f,0.5f} });

	//Straight after hairpin
	CreateBlocks(1, "OuterLeft15", "11Block", { {-16.1f,-0.12f,0.0f},{0.0f,0.0f,90.0f},{0.5f,0.5f,0.5f} });

	//turn in middle
	CreateBlocks(1, "OuterMid16", "6Block", { {-21.0f,-12.0f,0.0f},{0.0f,0.0f,-45.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterMid17", "6Block", { {-16.2f,-14.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterMid18", "11Block", { {-11.3f,-9.2f,0.0f},{0.0f,0.0f,65.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "OuterMid19", "9Block", { {-7.05f,-0.1f,0.0f},{0.0f,0.0f,65.0f},{0.52f,0.5f,0.5f} });
	CreateBlocks(1, "OuterMid20", "1Block", { {-5.0f,4.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "TopEnd21", "4Block", { {-7.0f,11.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });


	//Inner-----------------
	//Starting Lane
	CreateBlocks(1, "TopInnerLeft", "11Block", { {0.5f,4.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "TopInnerRight", "8Block", { {3.5f,4.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });

	//First turn on the right
	CreateBlocks(1, "InnerRight1", "9Block", { {4.55f,-0.8f,0.0f},{0.0f,0.0f,55.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "InnerRight2", "1Block", { {7.0f,3.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "InnerRight3", "9Block", { {3.6f,-8.2f,0.0f},{0.0f,0.0f,110.0f},{0.5f,0.5f,0.5f} });

	//Second turn on the right
	CreateBlocks(1, "InnerRight4", "6Block", { {3.2f,-14.1f,0.0f},{0.0f,0.0f,45.0f},{0.5f,0.5f,0.5f} });

	//Third turn on the right 
	CreateBlocks(1, "InnerRight4", "7Block", { {2.4f,-19.0f,0.0f},{0.0f,0.0f,110.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "InnerRight4", "4Block", { {2.1f,-22.6f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });

	//Bottem turn on the right 
	CreateBlocks(1, "InnerRight8", "11Block", { {-4.8f,-20.77f,0.0f},{0.0f,0.0f,-20.0f},{0.5f,0.5f,0.5f} });

	//Bottem turn on the middle 
	CreateBlocks(1, "InnerRight9", "3Block", { {-11.35f,-18.39f,0.0f},{0.0f,0.0f,-20.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "InnerMiddle10", "8Block", { {-16.1f,-19.25f,0.0f},{0.0f,0.0f,20.0f},{0.5f,0.5f,0.5f} });

	//Bottem turn on the left 
	CreateBlocks(1, "InnerLeft11", "4Block", { {-21.35f,-19.95f,0.0f},{0.0f,0.0f,-20.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "InnerLeft12", "11Block", { {-23.0f,-14.2f,0.0f},{0.0f,0.0f,90.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "InnerLeft13", "11Block", { {-23.0f,-3.2f,0.0f},{0.0f,0.0f,90.0f},{0.5f,0.5f,0.5f} });

	//turn in middle
	CreateBlocks(1, "InnerMid14", "11Block", { {-13.8f,-0.5f,0.0f},{0.0f,0.0f,65.0f},{0.5f,0.5f,0.5f} });
	CreateBlocks(1, "InnerMid14", "8Block", { {-10.1f,7.5f,0.0f},{0.0f,0.0f,65.0f},{0.5f,0.5f,0.5f} });

	//------------
}

void CLevel1::LoadAllPlayers()
{
	if (CSceneMgr::GetInstance()->P1)
	{
		Player1 = new CSpaceShip(1);
		Player1->SetWorld(this);
		Player1->m_name = "Player1";
		Player1->m_tag = "Player";
		Player1->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
		Player1->m_transform.position = m_spawnLocation1;
		this->m_vGameObj.push_back(Player1);
		this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player1));
		Player1->GetComponent<CSpriteRender>()->SetSprite("Player1");
		dynamic_cast<CSpaceShip*>(Player1)->m_GravityWell->SetSprite("Gravity");
		CRigiBody2D* player1RB = Player1->GetComponent<CRigiBody2D>();
		player1RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
		player1RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
		player1RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
		player1RB->m_bHasGravityWell = false;
		dynamic_cast<CSpaceShip*>(Player1)->m_fCurrentRotation = 270.0f;
	}
	if (CSceneMgr::GetInstance()->P2)
	{
		Player2 = new CSpaceShip(2);
		Player2->SetWorld(this);
		Player2->m_name = "Player2";
		Player2->m_tag = "Player";
		Player2->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
		Player2->m_transform.position = m_spawnLocation2;
		this->m_vGameObj.push_back(Player2);
		this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player2));
		Player2->GetComponent<CSpriteRender>()->SetSprite("Player2");
		dynamic_cast<CSpaceShip*>(Player2)->m_GravityWell->SetSprite("Gravity");
		CRigiBody2D* player2RB = Player2->GetComponent<CRigiBody2D>();
		player2RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
		player2RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
		player2RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
		player2RB->m_bHasGravityWell = false;
		dynamic_cast<CSpaceShip*>(Player2)->m_fCurrentRotation = 270.0f;
	}
	if (CSceneMgr::GetInstance()->P3)
	{
		Player3 = new CSpaceShip(3);
		Player3->SetWorld(this);
		Player3->m_name = "Player3";
		Player3->m_tag = "Player";
		Player3->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
		Player3->m_transform.position = m_spawnLocation3;
		this->m_vGameObj.push_back(Player3);
		this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player3));
		Player3->GetComponent<CSpriteRender>()->SetSprite("Player3");
		dynamic_cast<CSpaceShip*>(Player3)->m_GravityWell->SetSprite("Gravity");
		CRigiBody2D* player3RB = Player3->GetComponent<CRigiBody2D>();
		player3RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
		player3RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
		player3RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
		player3RB->m_bHasGravityWell = false;
		dynamic_cast<CSpaceShip*>(Player3)->m_fCurrentRotation = 270.0f;
	}
	if (CSceneMgr::GetInstance()->P4)
	{

		Player4 = new CSpaceShip(4);
		Player4->SetWorld(this);
		Player4->m_name = "Player4";
		Player4->m_tag = "Player";
		Player4->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
		Player4->m_transform.position = m_spawnLocation4;
		this->m_vGameObj.push_back(Player4);
		this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player4));
		Player4->GetComponent<CSpriteRender>()->SetSprite("Player4");
		dynamic_cast<CSpaceShip*>(Player4)->m_GravityWell->SetSprite("Gravity");
		CRigiBody2D* player4RB = Player4->GetComponent<CRigiBody2D>();
		player4RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
		player4RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
		player4RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
		player4RB->m_bHasGravityWell = false;
		dynamic_cast<CSpaceShip*>(Player4)->m_fCurrentRotation = 270.0f;
	}
}

void CLevel1::LoadUserInterface()
{
	// Player names
	CTextLabel* Player1UI = new CTextLabel("Taurus");
	Player1UI->SetText("Player 1");
	Player1UI->SetPosition(glm::vec2(0, util::SCR_HEIGHT - 35.0f));
	Player1UI->SetScale(0.7f);
	Player1UI->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player1UI);

	CTextLabel* Player2UI = new CTextLabel("Taurus");
	Player2UI->SetText("Player 2");
	Player2UI->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, util::SCR_HEIGHT - 35.0f));
	Player2UI->SetScale(0.7f);
	Player2UI->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player2UI);

	CTextLabel* Player3UI = new CTextLabel("Taurus");
	Player3UI->SetText("Player 3");
	Player3UI->SetPosition(glm::vec2(0, 60.0f));
	Player3UI->SetScale(0.7f);
	Player3UI->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player3UI);

	CTextLabel* Player4UI = new CTextLabel("Taurus");
	Player4UI->SetText("Player 4");
	Player4UI->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, 60.0f));
	Player4UI->SetScale(0.7f);
	Player4UI->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player4UI);

	//Player 1 score:
	Player1Score = new CTextLabel("SpaceFont");
	Player1Score->SetText("Score: " + ToString(CSceneMgr::GetInstance()->m_playerOneScore));
	Player1Score->SetPosition(glm::vec2(0, util::SCR_HEIGHT - 65.0f));
	Player1Score->SetScale(0.4f);
	Player1Score->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player1Score);

	//Player 2 Score:
	Player2Score = new CTextLabel("SpaceFont");
	Player2Score->SetText("Score: " + ToString(CSceneMgr::GetInstance()->m_playerTwoScore));
	Player2Score->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, util::SCR_HEIGHT - 65.0f));
	Player2Score->SetScale(0.4f);
	Player2Score->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player2Score);

	//Player 3 Score:
	Player3Score = new CTextLabel("SpaceFont");
	Player3Score->SetText("Score: " + ToString(CSceneMgr::GetInstance()->m_playerThreeScore));
	Player3Score->SetPosition(glm::vec2(0.0f, 30.0f));
	Player3Score->SetScale(0.4f);
	Player3Score->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player3Score);

	//Player 4 Score:
	Player4Score = new CTextLabel("SpaceFont");
	Player4Score->SetText("Score: " + ToString(CSceneMgr::GetInstance()->m_playerFourScore));
	Player4Score->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, 30.0f));
	Player4Score->SetScale(0.4f);
	Player4Score->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player4Score);

	//Player 1 Current Gadget:
	Player1Gadget = new CTextLabel("SpaceFont");
	Player1Gadget->SetText("Gadget: ");
	Player1Gadget->SetPosition(glm::vec2(0, util::SCR_HEIGHT - 90.0f));
	Player1Gadget->SetScale(0.35f);
	Player1Gadget->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player1Gadget);

	//Player 2 Current Gadget:
	Player2Gadget = new CTextLabel("SpaceFont");
	Player2Gadget->SetText("Gadget: ");
	Player2Gadget->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, util::SCR_HEIGHT - 90.0f));
	Player2Gadget->SetScale(0.35f);
	Player2Gadget->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player2Gadget);

	//Player 3 Current Gadget:
	Player3Gadget = new CTextLabel("SpaceFont");
	Player3Gadget->SetText("Gadget: ");
	Player3Gadget->SetPosition(glm::vec2(0.0f, 5.0f));
	Player3Gadget->SetScale(0.35f);
	Player3Gadget->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player3Gadget);

	//Player 4 Current Gadget:
	Player4Gadget = new CTextLabel("SpaceFont");
	Player4Gadget->SetText("Gadget: ");
	Player4Gadget->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, 5.0f));
	Player4Gadget->SetScale(0.35f);
	Player4Gadget->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player4Gadget);
}

void CLevel1::Reset()
{
	if (m_vPlayers.empty())
	{
		LoadAllPlayers();
		dynamic_cast<CSpaceShip*>(Player1)->iScore = 0;
		dynamic_cast<CSpaceShip*>(Player2)->iScore = 0;
		dynamic_cast<CSpaceShip*>(Player3)->iScore = 0;
		dynamic_cast<CSpaceShip*>(Player4)->iScore = 0;

	}
}

void CLevel1::CheckWin()
{
	int aliveCount = 0;
	for (auto player : m_vPlayers)
	{
		if (player->IsAlive())
		{
			Winner = player;
			aliveCount++;
		}
	}
	if (aliveCount == 1)
	{
		Winner->iScore++;
		CDebug::Log(Winner->m_name + " has Won");
	}
	else Winner = nullptr;

	// If there is a winner
	if (Winner)
	{
		if (Winner->m_name == "Player1")
		{
			CSceneMgr::GetInstance()->m_playerOneScore++;
		}
		else if (Winner->m_name == "Player2")
		{
			CSceneMgr::GetInstance()->m_playerTwoScore++;
		}
		else if (Winner->m_name == "Player3")
		{
			CSceneMgr::GetInstance()->m_playerThreeScore++;
		}
		else if (Winner->m_name == "Player4")
		{
			CSceneMgr::GetInstance()->m_playerFourScore++;
		}


		if (Winner->iScore >= 3)
		{
			CSceneMgr::GetInstance()->LoadScene("GameOver Scene");
			return;
		}


		// Load to the next
		CSceneMgr::GetInstance()->LoadScene("Level1");
	}


	/// Legacy Code
	/*
	if (m_vPlayers.size() == 1)
	{
		IsGameWon = true;
		Winner = m_vPlayers.at(0);
		std::cout << Winner->m_name << " Has Won!" << std::endl;

		if (Winner == Player1)
		{
			Winner->iScore++;
			Player1Score->SetText("Score: " + std::to_string(dynamic_cast<CSpaceShip*>(Player1)->iScore));
			Reset();
		}
		else if (Winner == Player2)
		{
			Winner->iScore++;
			Player2Score->SetText("Score: " + std::to_string(dynamic_cast<CSpaceShip*>(Player2)->iScore));
			Reset();
		}
		else if (Winner == Player3)
		{
			Winner->iScore++;
			Player3Score->SetText("Score: " + std::to_string(dynamic_cast<CSpaceShip*>(Player3)->iScore));
			Reset();
		}
		else if (Winner == Player4)
		{
			Winner->iScore++;
			Player4Score->SetText("Score: " + std::to_string(dynamic_cast<CSpaceShip*>(Player4)->iScore));
			Reset();
		}


		//std::cout << Winner->iScore << std::endl;
	}*/
}

void CLevel1::CheckCurrentGadget()
{
	if (CSceneMgr::GetInstance()->P1)
	{
		if (dynamic_cast<CSpaceShip*>(Player1)->CurrentItem != ItemState::ITEM_NONE)
		{
			if (dynamic_cast<CSpaceShip*>(Player1)->CurrentItem == ItemState::ITEM_GRAPPLINGHOOK)
			{
				Gadget = "Hook";
			}
			else if (dynamic_cast<CSpaceShip*>(Player1)->CurrentItem == ItemState::ITEM_GRAVITYWELL)
			{
				Gadget = "Grav Well";
			}
			else if (dynamic_cast<CSpaceShip*>(Player1)->CurrentItem == ItemState::ITEM_RAILGUN)
			{
				Gadget = "Rail Gun";
			}
			else if (dynamic_cast<CSpaceShip*>(Player1)->CurrentItem == ItemState::ITEM_DROPBOX)
			{
				Gadget = "Drop Box";
			}

			Player1Gadget->SetText("Gadget: " + Gadget);
		}
		else
		{
			Player1Gadget->SetText("Gadget: ");
		}
	}
	if (CSceneMgr::GetInstance()->P2)
	{
		if (dynamic_cast<CSpaceShip*>(Player2)->CurrentItem != ItemState::ITEM_NONE)
		{
			if (dynamic_cast<CSpaceShip*>(Player2)->CurrentItem == ItemState::ITEM_GRAPPLINGHOOK)
			{
				Gadget = "Hook";
			}
			else if (dynamic_cast<CSpaceShip*>(Player2)->CurrentItem == ItemState::ITEM_GRAVITYWELL)
			{
				Gadget = "Grav Well";
			}
			else if (dynamic_cast<CSpaceShip*>(Player2)->CurrentItem == ItemState::ITEM_RAILGUN)
			{
				Gadget = "Rail Gun";
			}
			else if (dynamic_cast<CSpaceShip*>(Player2)->CurrentItem == ItemState::ITEM_DROPBOX)
			{
				Gadget = "Drop Box";
			}

			Player2Gadget->SetText("Gadget: " + Gadget);
		}
		else
		{
			Player2Gadget->SetText("Gadget: ");
		}

	}
	if (CSceneMgr::GetInstance()->P3)
	{
		if (dynamic_cast<CSpaceShip*>(Player3)->CurrentItem != ItemState::ITEM_NONE)
		{
			if (dynamic_cast<CSpaceShip*>(Player3)->CurrentItem == ItemState::ITEM_GRAPPLINGHOOK)
			{
				Gadget = "Hook";
			}
			else if (dynamic_cast<CSpaceShip*>(Player3)->CurrentItem == ItemState::ITEM_GRAVITYWELL)
			{
				Gadget = "Grav Well";
			}
			else if (dynamic_cast<CSpaceShip*>(Player3)->CurrentItem == ItemState::ITEM_RAILGUN)
			{
				Gadget = "Rail Gun";
			}
			else if (dynamic_cast<CSpaceShip*>(Player3)->CurrentItem == ItemState::ITEM_DROPBOX)
			{
				Gadget = "Drop Box";
			}

			Player3Gadget->SetText("Gadget: " + Gadget);
		}
		else
		{
			Player3Gadget->SetText("Gadget: ");
		}

	}
	if (CSceneMgr::GetInstance()->P4)
	{
		if (dynamic_cast<CSpaceShip*>(Player4)->CurrentItem != ItemState::ITEM_NONE)
		{
			if (dynamic_cast<CSpaceShip*>(Player4)->CurrentItem == ItemState::ITEM_GRAPPLINGHOOK)
			{
				Gadget = "Hook";
			}
			else if (dynamic_cast<CSpaceShip*>(Player4)->CurrentItem == ItemState::ITEM_GRAVITYWELL)
			{
				Gadget = "Grav Well";
			}
			else if (dynamic_cast<CSpaceShip*>(Player4)->CurrentItem == ItemState::ITEM_RAILGUN)
			{
				Gadget = "Rail Gun";
			}
			else if (dynamic_cast<CSpaceShip*>(Player4)->CurrentItem == ItemState::ITEM_DROPBOX)
			{
				Gadget = "Drop Box";
			}
			Player4Gadget->SetText("Gadget: " + Gadget);
		}
		else
		{
			Player4Gadget->SetText("Gadget: ");
		}
	}


}

void CLevel1::CreateBlocks(int _iBlockID, std::string _name, std::string _spriteName, Transform _transform, std::string _tag)
{
	//std::shared_ptr<CBlocks>Blocks = std::make_shared<CBlocks>(iBlockID);
	CBlocks* Blocks = new CBlocks(_iBlockID);
	Blocks->SetWorld(this);
	Blocks->m_name = _name;
	Blocks->m_tag = _tag;
	Blocks->m_transform.position = _transform.position;
	Blocks->m_transform.rotation = _transform.rotation;
	Blocks->m_transform.scale = _transform.scale;
	this->m_vGameObj.push_back(std::move(Blocks));
	Blocks->GetComponent<CSpriteRender>()->SetSprite(_spriteName);
	Blocks->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_staticBody);
}
