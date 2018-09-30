
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
	BackGround->m_name = "BackGround";
	BackGround->m_tag = "BackGround";
	BackGround->m_transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
	BackGround->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(BackGround);
	BackGround->GetComponent<CSpriteRender>()->SetSprite("Background");
	//--------------------------------------------------------------
	//CGameObject* GravityBlock = new CBlocks(3);
	//GravityBlock->m_name = "Block1";
	//GravityBlock->m_tag = "Block";
	//GravityBlock->m_transform.position = glm::vec3(-4.0f, 0.0f, 0.0f);
	//GravityBlock->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	//GravityBlock->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	//this->m_vGameObj.push_back(GravityBlock);
	//GravityBlock->GetComponent<CSpriteRender>()->SetSprite("1Block");
	//GravityBlock->GetComponent<CRigiBody2D>()->CreateGravityWell(GetWorld(), 10.0f, true, 1.0f);
	
	LoadAllPlayers();
	LoadAllBlocks();
	AddScore();
	
	//CreateBlocks();
	//CreatePigs();
	//CreateBirdies();
}

void CTestScene::BeginPlay()
{
	__super::BeginPlay();
	

}

void CTestScene::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	CheckWin();
	//if (m_PigCount <= 0)
	//{
	//	CSceneMgr::GetInstance()->LoadScene("Second Scene");
	//}
	//if (!bSlingLoaded)
	//{
	//	if (CurrentBird + 1 < m_vBirds.size())
	//	{
	//		CurrentBird++;
	//		m_vBirds[CurrentBird]->bIsLoaded = true;
	//		bSlingLoaded = true;
	//	}
	//}
	//else
	//{
	//	if (CurrentBird < m_vBirds.size())
	//	{
	//		if (m_vBirds[CurrentBird]->bIsLoaded == false)
	//		{
	//			bSlingLoaded = false;
	//		}
	//	}
	//}

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
	Player1->m_name = "Player1";
	Player1->m_tag = "Player";
	Player1->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player1->m_transform.position = SpawnLocation1;
	this->m_vGameObj.push_back(Player1);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player1));
	Player1->GetComponent<CSpriteRender>()->SetSprite("Player1");
	Player1->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);
	Player1->GetComponent<CRigiBody2D>()->GetBody()->GetFixtureList()->SetRestitution(0.3f);

	CGameObject* Player2 = new CSpaceShip(2);
	Player2->m_name = "Player2";
	Player2->m_tag = "Player";
	Player2->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player2->m_transform.position = SpawnLocation2;
	this->m_vGameObj.push_back(Player2);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player2));
	Player2->GetComponent<CSpriteRender>()->SetSprite("Player2");
	Player2->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Player3 = new CSpaceShip(3);
	Player3->m_name = "Player3";
	Player3->m_tag = "Player";
	Player3->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player3->m_transform.position = SpawnLocation3;
	this->m_vGameObj.push_back(Player3);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player3));
	Player3->GetComponent<CSpriteRender>()->SetSprite("Player3");
	Player3->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Player4 = new CSpaceShip(4);
	Player4->m_name = "Player4";
	Player4->m_tag = "Player";
	Player4->m_transform.scale = glm::vec3(0.65f, 0.65f, 1.0f);
	Player4->m_transform.position = SpawnLocation4;
	this->m_vGameObj.push_back(Player4);
	this->m_vPlayers.push_back(dynamic_cast<CSpaceShip*>(Player4));
	Player4->GetComponent<CSpriteRender>()->SetSprite("Player4");
	Player4->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

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
	}
}

void CTestScene::CreateBlocks(int iBlockID, std::string Name,  std::string SpriteName, Transform Transform,std::string Tag )
{
	//std::shared_ptr<CBlocks>Blocks = std::make_shared<CBlocks>(iBlockID);
	CBlocks* Blocks = new CBlocks(iBlockID);

	Blocks->m_name = Name;
	Blocks->m_tag = Tag;
	Blocks->m_transform.position = Transform.position;
	Blocks->m_transform.rotation.x = Transform.rotation.x ;
	Blocks->m_transform.rotation.y = Transform.rotation.y;
	Blocks->m_transform.rotation.z = Transform.rotation.z;
	Blocks->m_transform.scale = Transform.scale;
	this->m_vGameObj.push_back(std::move(Blocks));
	Blocks->GetComponent<CSpriteRender>()->SetSprite(SpriteName);
	Blocks->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_staticBody);	
}

