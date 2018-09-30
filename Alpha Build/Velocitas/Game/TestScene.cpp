
// This Include
#include "TestScene.h"

// Inlcude the game classes
#include "Game/GameClasses.h"
#include "Engine/Camera.h"
#include "Engine/RigidBody2D.h"
#include "Engine/SpriteRender.h"
#include "Engine/AssetMgr.h"
#include "Blocks.h"
#include "ContactListener.h"
#include "Engine/SceneMgr.h"
#include "Game/SpaceShip.h"
#include "Game/ItemCube.h"
#include "Engine/TextLabel.h"
//Includes
#include <memory>

void CTestScene::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */
	bSlingLoaded = false;
	CurrentBird = -1;

	this->m_sceneName = "Test Scene";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();
	
	/** Create game objects in the scenes */

	//BACKGROUND----------------------------------------------------
	CGameObject* BackGround = new CBlocks(1);
	BackGround->SetWorld(this);
	BackGround->m_name = "BackGround";
	BackGround->m_tag = "BackGround";
	BackGround->m_transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
	BackGround->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(BackGround);
	BackGround->GetComponent<CSpriteRender>()->SetSprite("Background");
	//--------------------------------------------------------------

	CTextLabel* Test = new CTextLabel("SpaceFont");
	Test->SetText("Testing Text");
	Test->SetPosition(glm::vec2((util::SCR_WIDTH /4) + 100.0f, util::SCR_HEIGHT/2));
	Test->SetScale(1.0f);
	Test->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextList.push_back(Test);
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

	CGameObject* ItemCube = new CItemCubes(ITEM_NONE);
	ItemCube->SetWorld(this);
	ItemCube->m_name = "ItemCube1";
	ItemCube->m_tag = "ItemCube";
	ItemCube->m_transform.position = glm::vec3(10.0f, 10.0f, 0.0f);
	ItemCube->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	ItemCube->m_transform.scale = glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube);
	ItemCube->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);
	
	CGameObject* ItemCube2 = new CItemCubes(ITEM_NONE);
	ItemCube2->SetWorld(this);
	ItemCube2->m_name = "ItemCube1";
	ItemCube2->m_tag = "ItemCube";
	ItemCube2->m_transform.position = glm::vec3(10.0f, 9.0f, 0.0f);
	ItemCube2->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	ItemCube2->m_transform.scale = glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube2);
	ItemCube2->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube2->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);

	CGameObject* ItemCube3 = new CItemCubes(ITEM_NONE);
	ItemCube3->SetWorld(this);
	ItemCube3->m_name = "ItemCube1";
	ItemCube3->m_tag = "ItemCube";
	ItemCube3->m_transform.position = glm::vec3(10.0f, 8.0f, 0.0f);
	ItemCube3->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	ItemCube3->m_transform.scale = glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube3);
	ItemCube3->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube3->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);

	CGameObject* ItemCube4 = new CItemCubes(ITEM_NONE);
	ItemCube4->SetWorld(this);
	ItemCube4->m_name = "ItemCube1";
	ItemCube4->m_tag = "ItemCube";
	ItemCube4->m_transform.position = glm::vec3(10.0f, 7.0f, 0.0f);
	ItemCube4->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	ItemCube4->m_transform.scale = glm::vec3(0.3f, 0.1f, 0.5f);
	this->m_vGameObj.push_back(ItemCube4);
	ItemCube4->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	ItemCube4->GetComponent<CRigiBody2D>()->CreateSensorCube(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f);

	LoadAllPlayers();
	LoadAllBlocks();
	AddScore();

}

void CTestScene::BeginPlay()
{
	__super::BeginPlay();
	

}

void CTestScene::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	CheckWin();
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
	CGameObject* Player1 = new CSpaceShip(1);
	Player1->SetWorld(this);
	Player1->m_name = "Player1";
	Player1->m_tag = "Player";
	Player1->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player1->m_transform.position = SpawnLocation1;
	this->m_vGameObj.push_back(Player1);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player1));
	Player1->GetComponent<CSpriteRender>()->SetSprite("Player1");
	CRigiBody2D* player1RB = Player1->GetComponent<CRigiBody2D>();
	player1RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
	player1RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
	player1RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
	player1RB->m_bHasGravityWell = false;

	CGameObject* Player2 = new CSpaceShip(2);
	Player2->SetWorld(this);
	Player2->m_name = "Player2";
	Player2->m_tag = "Player";
	Player2->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player2->m_transform.position = SpawnLocation2;
	this->m_vGameObj.push_back(Player2);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player2));
	Player2->GetComponent<CSpriteRender>()->SetSprite("Player2");
	CRigiBody2D* player2RB = Player2->GetComponent<CRigiBody2D>();
	player2RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
	player2RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
	player2RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
	player2RB->m_bHasGravityWell = false;
	dynamic_cast<CSpaceShip*>(Player2)->bControllerInput = false;

	CGameObject* Player3 = new CSpaceShip(3);
	Player3->SetWorld(this);
	Player3->m_name = "Player3";
	Player3->m_tag = "Player";
	Player3->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player3->m_transform.position = SpawnLocation3;
	this->m_vGameObj.push_back(Player3);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player3));
	Player3->GetComponent<CSpriteRender>()->SetSprite("Player3");
	CRigiBody2D* player3RB = Player3->GetComponent<CRigiBody2D>();
	player3RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
	player3RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
	player3RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
	player3RB->m_bHasGravityWell = false;

	CGameObject* Player4 = new CSpaceShip(4);
	Player4->SetWorld(this);
	Player4->m_name = "Player4";
	Player4->m_tag = "Player";
	Player4->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player4->m_transform.position = SpawnLocation4;
	this->m_vGameObj.push_back(Player4);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player4));
	Player4->GetComponent<CSpriteRender>()->SetSprite("Player4");
	CRigiBody2D* player4RB = Player4->GetComponent<CRigiBody2D>();
	player4RB->CreateBodyCircle(GetWorld(), b2_dynamicBody, false, true, 1.0f, 1.0f, 1);
	player4RB->GetBody()->GetFixtureList()->SetRestitution(0.1f);
	player4RB->CreateGravityWell(GetWorld(), 5.0f, true, 0.5f);
	player4RB->m_bHasGravityWell = false;

}

void CTestScene::Reset()
{
	if(m_vPlayers.empty())
	{
		LoadAllPlayers();
	}
}

void CTestScene::AddScore()
{
	auto Score = std::make_shared<CTextLabel>("Score:", "Resources/Fonts/Space.TTF", glm::vec2(0, 0));
}

void CTestScene::CheckWin()
{
	if (m_vPlayers.size() == 1)
	{
		IsGameWon = true;
		CSpaceShip* Winner = m_vPlayers.at(0);
		std::cout << Winner->m_name << " Has Won!" << std::endl;
		Winner->iScore += 1;
		std::cout << Winner->iScore << std::endl;
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
