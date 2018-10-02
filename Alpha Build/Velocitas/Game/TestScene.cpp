
// This Include
#include "TestScene.h"

// Inlcude the game classes
#include "Game/GameClasses.h"
#include "Engine/Camera.h"
#include "Engine/RigidBody2D.h"
#include "Engine/SpriteRender.h"
#include "Engine/AssetMgr.h"
#include "Blocks.h"
#include "RaceCourse.h"
#include "CheckPoint.h"
#include "ContactListener.h"
#include "Engine/SceneMgr.h"
#include "Game/SpaceShip.h"
#include "Game/ItemCube.h"
#include "Engine/TextLabel.h"
#include "Game/GravityWellObj.h"
//Includes
#include <memory>
#include "Engine/Sound.h"
void CTestScene::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */

	this->m_sceneName = "Test Scene";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();
	
	/** Create game objects in the scenes */
	//Creating Sound
	CSound::GetInstance()->Init();
	CSound::GetInstance()->AddSound();
	CSound::GetInstance()->SoundMgr->playSound(CSound::GetInstance()->bgMusic, 0, false, &CSound::GetInstance()->BgMusicChannel);
	CSound::GetInstance()->BgMusicChannel->setVolume(0.2f);
	//BACKGROUND----------------------------------------------------
	CGameObject* BackGround = new CBlocks(1);
	BackGround->SetWorld(this);
	BackGround->m_name = "BackGround";
	BackGround->m_tag = "BackGround";
	BackGround->m_transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
	BackGround->m_transform.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	this->m_vGameObj.push_back(BackGround);
	BackGround->GetComponent<CSpriteRender>()->SetSprite("Background");
	//--------------------------------------------------------------

	//CTextLabel* Test = new CTextLabel("SpaceFont");
	//Test->SetText("Testing Text");
	//Test->SetPosition(glm::vec2((util::SCR_WIDTH /4) + 100.0f, util::SCR_HEIGHT/2));
	//Test->SetScale(1.0f);
	//Test->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	//m_vTextLabel.push_back(Test);

	//CGameObject* GravityBlock = new CBlocks(3);
	//GravityBlock->SetWorld(this);
	//GravityBlock->m_name = "Block1";
	//GravityBlock->m_tag = "Block";
	//GravityBlock->m_transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	//GravityBlock->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	//GravityBlock->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	//this->m_vGameObj.push_back(GravityBlock);
	//GravityBlock->GetComponent<CSpriteRender>()->SetSprite("Block");
	//GravityBlock->GetComponent<CRigiBody2D>()->CreateGravityWell(GetWorld(), 10.0f, true, 0.5f);

	CGameObject* ItemCube = new CItemCubes(ITEM_GRAPPLINGHOOK);
	ItemCube->SetWorld(this);
	ItemCube->m_name = "ItemCube1";
	ItemCube->m_tag = "ItemCube";
	ItemCube->m_transform.position = glm::vec3(10.0f, 10.0f, 0.0f);
	ItemCube->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	ItemCube->m_transform.scale = glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube);
	ItemCube->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);
	
	CGameObject* ItemCube2 = new CItemCubes(ITEM_GRAPPLINGHOOK);
	ItemCube2->SetWorld(this);
	ItemCube2->m_name = "ItemCube1";
	ItemCube2->m_tag = "ItemCube";
	ItemCube2->m_transform.position = glm::vec3(10.0f, 9.0f, 0.0f);
	ItemCube2->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	ItemCube2->m_transform.scale = glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube2);
	ItemCube2->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube2->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);

	CGameObject* ItemCube3 = new CItemCubes(ITEM_GRAPPLINGHOOK);
	ItemCube3->SetWorld(this);
	ItemCube3->m_name = "ItemCube1";
	ItemCube3->m_tag = "ItemCube";
	ItemCube3->m_transform.position = glm::vec3(10.0f, 8.0f, 0.0f);
	ItemCube3->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	ItemCube3->m_transform.scale = glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube3);
	ItemCube3->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube3->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);

	CGameObject* ItemCube4 = new CItemCubes(ITEM_GRAPPLINGHOOK);
	ItemCube4->SetWorld(this);
	ItemCube4->m_name = "ItemCube1";
	ItemCube4->m_tag = "ItemCube";
	ItemCube4->m_transform.position = glm::vec3(10.0f, 7.0f, 0.0f);
	ItemCube4->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	ItemCube4->m_transform.scale = glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube4);
	ItemCube4->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube4->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);
	
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
		checkPoint_1->m_transform.position = glm::vec3(14.5f, 5.5f, 0.0f);
		checkPoint_1->m_transform.scale = glm::vec3(5.0f, 1.0f, 0.0f);

		CGameObject* checkPoint_2 = new CCheckPoint();
		checkPoint_2->SetWorld(this);
		m_vGameObj.push_back(checkPoint_2);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_2);
		checkPoint_2->m_name = "CheckPoint_2";
		checkPoint_2->m_transform.position = glm::vec3(-10.0f, 8.5f, 0.0f);
		checkPoint_2->m_transform.scale = glm::vec3(1.0f, 3.0f, 0.0f);

		CGameObject* checkPoint_3 = new CCheckPoint();
		checkPoint_3->SetWorld(this);
		m_vGameObj.push_back(checkPoint_3);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_3);
		checkPoint_3->m_name = "CheckPoint_3";
		checkPoint_3->m_transform.position = glm::vec3(-14.5f, -5.5f, 0.0f);
		checkPoint_3->m_transform.scale = glm::vec3(5.0f, 1.0f, 0.0f);

		CGameObject* checkPoint_4 = new CCheckPoint();
		checkPoint_4->SetWorld(this);
		m_vGameObj.push_back(checkPoint_4);
		m_raceCourse->AddCheckPoint((CCheckPoint*)checkPoint_4);
		checkPoint_4->m_name = "CheckPoint_4";
		checkPoint_4->m_transform.position = glm::vec3(10.0f, -8.5f, 0.0f);
		checkPoint_4->m_transform.scale = glm::vec3(1.0f, 3.0f, 0.0f);
	}


	CGameObject* GravityWell1 = new CGravityWell();
	GravityWell1->SetWorld(this);
	GravityWell1->m_name = "GravityWell1";
	GravityWell1->m_transform.position = glm::vec3(9.0f, -6.0f, 0.0f);
	Instantiate(GravityWell1);

	LoadAllPlayers();
	LoadAllBlocks();
	LoadUserInterface();
	/** Create a example text */
	//CTextLabel* newTextLabel = new CTextLabel("FontName");
	//m_vTextLabel.push_back(newTextLabel);
	//newTextLabel->SetText("Whatever text here");
	

}

void CTestScene::BeginPlay()
{
	__super::BeginPlay();

}

void CTestScene::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	CheckWin();
	CheckCurrentGadget();
	
	// Make the camera to the first players position
	glm::vec3 newCameraPosition;
	if (CGameObject* firstPlayer = m_raceCourse->GetFirstPlayer())
	{
		newCameraPosition = firstPlayer->m_transform.position;
	}
	newCameraPosition.z = m_mainCamera->GetCameraPosition().z;
	m_mainCamera->SetCameraPosition(newCameraPosition);
}

void CTestScene::LoadAllBlocks()
{
	//Outer Ring------------------
		//Bot Center
		CreateBlocks(1, "BotCenter", "11Block", { {0.0f,-11.0f,0.0f},{0.0f,0.0f,0.0f},{0.5f,0.5f,0.5f} });
		//Bot Left plus turn
		CreateBlocks(1, "BotLeftTurn", "8Block", { { -17.0f,-8.5f,0.0f },{ 0.0f,0.0f,-45.0f },{ 0.5f,0.5f,0.5f } });
		CreateBlocks(1, "BotLeft", "9Block", { { -10.0f,-11.0f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.5f,0.5f,0.5f } });
		//Bot Right plus turn
		CreateBlocks(1, "BotRightTurn", "8Block", { { 17.0f,-8.5f,0.0f },{ 0.0f,0.0f,45.0f },{ 0.5f,0.5f,0.5f } });
		CreateBlocks(1, "BotRight", "9Block", { { 10.0f,-11.0f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.5f,0.5f,0.5f } });

		//Top Center
		CreateBlocks(1, "TopCenter", "11Block", { { 0.0f,11.0f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.5f,0.5f,0.5f } });
		//Top Left plus turn
		CreateBlocks(1, "TopLeftTurn", "8Block", { { -17.0f,8.5f,0.0f },{ 0.0f,0.0f,45.0f },{ 0.5f,0.5f,0.5f } });
		CreateBlocks(1, "TopLeft", "9Block", { { -10.0f,11.0f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.5f,0.5f,0.5f } });
		//Top Right plus turn
		CreateBlocks(1, "TopRightTurn", "8Block", { { 17.0f,8.5f,0.0f },{ 0.0f,0.0f,-45.0f },{ 0.5f,0.5f,0.5f } });
		CreateBlocks(1, "TopRIght", "9Block", { { 10.0f,11.0f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.5f,0.5f,0.5f } });

		//Left Side
		CreateBlocks(1, "LeftSide", "11Block", { { -19.5f,0.0f,0.0f },{ 0.0f,0.0f,90.0f },{0.55f,0.5f,0.5f } });
		//Right Side
		CreateBlocks(1, "RightSide", "11Block", { { 19.5f,0.0f,0.0f },{ 0.0f,0.0f,90.0f },{ 0.55f,0.5f,0.5f } });
	//------------------------------
		//Left Side
		CreateBlocks(1, "LeftSide", "11Block", { { -9.75f,0.0f,0.0f },{ 0.0f,0.0f,90.0f },{ 0.54f,0.5f,0.5f } });
		//Right Side
		CreateBlocks(1, "RightSide", "11Block", { { 9.75f,0.0f,0.0f },{ 0.0f,0.0f,90.0f },{ 0.54f,0.5f,0.5f } });

		//Bot Center
		CreateBlocks(1, "BotCenter", "11Block", { { 0.0f,-5.5f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.5f,0.5f,0.5f } });
		//Bot Left plus turn
		//CreateBlocks(1, "BotLeftTurn", "8Block", { { -8.5f,-4.25f,0.0f },{ 0.0f,0.0f,-45.0f },{ 0.5f,0.5f,0.5f } });
		CreateBlocks(1, "BotLeft", "9Block", { { -5.0f,-5.5f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.58f,0.5f,0.5f } });
		//Bot Right plus turn
		//CreateBlocks(1, "BotRightTurn", "8Block", { { 8.5f,-5.25f,0.0f },{ 0.0f,0.0f,45.0f },{ 0.5f,0.5f,0.5f } });
		CreateBlocks(1, "BotRight", "9Block", { { 5.0f,-5.5f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.58f,0.5f,0.5f } });

		//Top Center
		CreateBlocks(1, "TopCenter", "11Block", { { 0.0f,5.5f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.5f,0.5f,0.5f } });
		//Top Left plus turn
		//CreateBlocks(1, "TopLeftTurn", "8Block", { { -8.5f,4.25f,0.0f },{ 0.0f,0.0f,45.0f },{ 0.5f,0.5f,0.5f } });
		CreateBlocks(1, "TopLeft", "9Block", { { -5.0f,5.5f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.58f,0.5f,0.5f } });
		//Top Right plus turn
		//CreateBlocks(1, "TopRightTurn", "8Block", { { 8.5f,4.25f,0.0f },{ 0.0f,0.0f,-45.0f },{ 0.5f,0.5f,0.5f } });
		CreateBlocks(1, "TopRIght", "9Block", { { 5.0f,5.5f,0.0f },{ 0.0f,0.0f,0.0f },{ 0.58f,0.5f,0.5f } });

		
}

void CTestScene::LoadAllPlayers()
{
	Player1 = new CSpaceShip(1);
	Player1->SetWorld(this);
	Player1->m_name = "Player1";
	Player1->m_tag = "Player";
	Player1->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player1->m_transform.position = SpawnLocation1;
	this->m_vGameObj.push_back(Player1);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player1));
	Player1->GetComponent<CSpriteRender>()->SetSprite("Player1");
	dynamic_cast<CSpaceShip*>(Player1)->m_GravityWell->SetSprite("Gravity");
	CRigiBody2D* player1RB = Player1->GetComponent<CRigiBody2D>();
	player1RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
	player1RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
	player1RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
	player1RB->m_bHasGravityWell = false;

	Player2 = new CSpaceShip(2);
	Player2->SetWorld(this);
	Player2->m_name = "Player2";
	Player2->m_tag = "Player";
	Player2->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player2->m_transform.position = SpawnLocation2;
	this->m_vGameObj.push_back(Player2);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player2));
	Player2->GetComponent<CSpriteRender>()->SetSprite("Player2");
	dynamic_cast<CSpaceShip*>(Player2)->m_GravityWell->SetSprite("Gravity");
	CRigiBody2D* player2RB = Player2->GetComponent<CRigiBody2D>();
	player2RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
	player2RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
	player2RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
	player2RB->m_bHasGravityWell = false;
	dynamic_cast<CSpaceShip*>(Player2)->bControllerInput = false;

	Player3 = new CSpaceShip(3);
	Player3->SetWorld(this);
	Player3->m_name = "Player3";
	Player3->m_tag = "Player";
	Player3->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player3->m_transform.position = SpawnLocation3;
	this->m_vGameObj.push_back(Player3);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player3));
	Player3->GetComponent<CSpriteRender>()->SetSprite("Player3");
	dynamic_cast<CSpaceShip*>(Player3)->m_GravityWell->SetSprite("Gravity");
	CRigiBody2D* player3RB = Player3->GetComponent<CRigiBody2D>();
	player3RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
	player3RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
	player3RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
	player3RB->m_bHasGravityWell = false;

	Player4 = new CSpaceShip(4);
	Player4->SetWorld(this);
	Player4->m_name = "Player4";
	Player4->m_tag = "Player";
	Player4->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player4->m_transform.position = SpawnLocation4;
	this->m_vGameObj.push_back(Player4);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player4));
	Player4->GetComponent<CSpriteRender>()->SetSprite("Player4");
	dynamic_cast<CSpaceShip*>(Player4)->m_GravityWell->SetSprite("Gravity");
	CRigiBody2D* player4RB = Player4->GetComponent<CRigiBody2D>();
	player4RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
	player4RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
	player4RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
	player4RB->m_bHasGravityWell = false;

}

void CTestScene::LoadUserInterface()
{
	// Player names
	CTextLabel* Player1UI = new CTextLabel("SpaceFont");
	Player1UI->SetText("Player 1");
	Player1UI->SetPosition(glm::vec2(0, util::SCR_HEIGHT - 35.0f));
	Player1UI->SetScale(0.5f);
	Player1UI->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player1UI);

	CTextLabel* Player2UI = new CTextLabel("SpaceFont");
	Player2UI->SetText("Player 2");
	Player2UI->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, util::SCR_HEIGHT - 35.0f));
	Player2UI->SetScale(0.5f);
	Player2UI->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player2UI);

	CTextLabel* Player3UI = new CTextLabel("SpaceFont");
	Player3UI->SetText("Player 3");
	Player3UI->SetPosition(glm::vec2(0, 60.0f));
	Player3UI->SetScale(0.5f);
	Player3UI->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player3UI);

	CTextLabel* Player4UI = new CTextLabel("SpaceFont");
	Player4UI->SetText("Player 4");
	Player4UI->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, 60.0f));
	Player4UI->SetScale(0.5f);
	Player4UI->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player4UI);

	//Player 1 score:
	Player1Score = new CTextLabel("SpaceFont");
	Player1Score->SetText("Score: ");
	Player1Score->SetPosition(glm::vec2(0, util::SCR_HEIGHT - 65.0f));
	Player1Score->SetScale(0.4f);
	Player1Score->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player1Score);

	//Player 2 Score:
	Player2Score = new CTextLabel("SpaceFont");
	Player2Score->SetText("Score: ");
	Player2Score->SetPosition(glm::vec2(util::SCR_WIDTH - 300.0f, util::SCR_HEIGHT - 65.0f));
	Player2Score->SetScale(0.4f);
	Player2Score->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player2Score);

	//Player 3 Score:
	Player3Score = new CTextLabel("SpaceFont");
	Player3Score->SetText("Score: ");
	Player3Score->SetPosition(glm::vec2(0.0f, 30.0f));
	Player3Score->SetScale(0.4f);
	Player3Score->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Player3Score);

	//Player 4 Score:
	Player4Score = new CTextLabel("SpaceFont");
	Player4Score->SetText("Score: ");
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

void CTestScene::Reset()
{
	if(m_vPlayers.empty())
	{
		LoadAllPlayers();
		dynamic_cast<CSpaceShip*>(Player1)->iScore = 0;
		dynamic_cast<CSpaceShip*>(Player2)->iScore = 0;
		dynamic_cast<CSpaceShip*>(Player3)->iScore = 0;
		dynamic_cast<CSpaceShip*>(Player4)->iScore = 0;
		
	}
}

void CTestScene::CheckWin()
{
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

		if (Winner->iScore == 3)
		{
			Winner = m_vPlayers.at(0);
			CSceneMgr::GetInstance()->LoadScene("GameOver Scene");
		}
		//std::cout << Winner->iScore << std::endl;
	}
}

void CTestScene::CheckCurrentGadget()
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
		Player1Gadget->SetText("Gadget: " + Gadget);
	}
	else if(dynamic_cast<CSpaceShip*>(Player2)->CurrentItem != ItemState::ITEM_NONE)
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
		Player2Gadget->SetText("Gadget: " + Gadget);
	}
	else if (dynamic_cast<CSpaceShip*>(Player3)->CurrentItem != ItemState::ITEM_NONE)
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
		Player3Gadget->SetText("Gadget: " + Gadget);
	}
	else if (dynamic_cast<CSpaceShip*>(Player4)->CurrentItem != ItemState::ITEM_NONE)
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
		Player4Gadget->SetText("Gadget: " + Gadget);
	}
}

void CTestScene::CreateBlocks(int iBlockID, std::string Name,  std::string SpriteName, Transform Transform,std::string Tag )
{
	//std::shared_ptr<CBlocks>Blocks = std::make_shared<CBlocks>(iBlockID);
	CBlocks* Blocks = new CBlocks(iBlockID);
	Blocks->SetWorld(this);
	Blocks->m_name = Name;
	Blocks->m_tag = Tag;
	Blocks->m_transform.position = Transform.position;
	Blocks->m_transform.rotation.x = Transform.rotation.x;
	Blocks->m_transform.rotation.y = Transform.rotation.y;
	Blocks->m_transform.rotation.z = Transform.rotation.z;
	Blocks->m_transform.scale = Transform.scale;
	this->m_vGameObj.push_back(std::move(Blocks));
	Blocks->GetComponent<CSpriteRender>()->SetSprite(SpriteName);
	Blocks->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_staticBody);	
}

void CTestScene::CreatePlayers()
{

	CGameObject* Player1 = new CSpaceShip(1);
	Player1->SetWorld(this);
	Player1->m_name = "Player1";
	Player1->m_tag = "Player";
	Player1->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player1);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player1));
	Player1->GetComponent<CSpriteRender>()->SetSprite("Triangle");
	Player1->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);
	Player1->GetComponent<CRigiBody2D>()->GetBody()->GetFixtureList()->SetRestitution(0.3f);

	CGameObject* Player2 = new CSpaceShip(2);
	Player2->SetWorld(this);
	Player2->m_name = "Player2";
	Player2->m_tag = "Player";
	Player2->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player2);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player2));
	Player2->GetComponent<CSpriteRender>()->SetSprite("Triangle");
	Player2->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);
	dynamic_cast<CSpaceShip*>(Player2)->bControllerInput = false;

	CGameObject* Player3 = new CSpaceShip(3);
	Player3->SetWorld(this);
	Player3->m_name = "Player3";
	Player3->m_tag = "Player";
	Player3->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player3);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player3));
	Player3->GetComponent<CSpriteRender>()->SetSprite("Triangle");
	Player3->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Player4 = new CSpaceShip(4);
	Player4->SetWorld(this);
	Player4->m_name = "Player4";
	Player4->m_tag = "Player";
	Player4->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player4);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player4));
	Player4->GetComponent<CSpriteRender>()->SetSprite("Triangle");
	Player4->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);
}
