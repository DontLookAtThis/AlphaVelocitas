
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
	BackGround->m_transform.scale = glm::vec3(1.6f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(BackGround);
	BackGround->GetComponent<CSpriteRender>()->SetSprite("BackGround");
	//--------------------------------------------------------------

	CGameObject* Ground = new CBlocks(2);
	Ground->m_name = "Ground";
	Ground->m_tag = "Ground";
	Ground->m_transform.position = glm::vec3(0.0f, -11.0f, 0.0f);
	Ground->m_transform.scale = glm::vec3(25.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Ground);

	Ground->GetComponent<CSpriteRender>()->SetSprite("Ground");
	Ground->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f, 0);

	CGameObject* Player1 = new CSpaceShip(1);
	Player1->m_name = "Player1";
	Player1->m_tag = "Player";
	Player1->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player1);
	this->m_vBirds.push_back(dynamic_cast<CSpaceShip*>(Player1));
	Player1->GetComponent<CSpriteRender>()->SetSprite("Triangle");
	Player1->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Player2 = new CSpaceShip(1);
	Player2->m_name = "Player2";
	Player2->m_tag = "Player";
	Player2->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player2);
	this->m_vBirds.push_back(dynamic_cast<CSpaceShip*>(Player2));
	Player2->GetComponent<CSpriteRender>()->SetSprite("Triangle");
	Player2->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Player3 = new CSpaceShip(1);
	Player3->m_name = "Player3";
	Player3->m_tag = "Player";
	Player3->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player3);
	this->m_vBirds.push_back(dynamic_cast<CSpaceShip*>(Player3));
	Player3->GetComponent<CSpriteRender>()->SetSprite("Triangle");
	Player3->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Player4 = new CSpaceShip(1);
	Player4->m_name = "Player4";
	Player4->m_tag = "Player";
	Player4->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player4);
	this->m_vBirds.push_back(dynamic_cast<CSpaceShip*>(Player4));
	Player4->GetComponent<CSpriteRender>()->SetSprite("Triangle");
	Player4->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

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

void CTestScene::CreateBlocks()
{
	CGameObject* VerticalBlock1 = new CBlocks(3);
	VerticalBlock1->m_name = "Block1";
	VerticalBlock1->m_tag = "Block";
	VerticalBlock1->m_transform.position = glm::vec3(5.5f, -8.7f, 0.0f);
	VerticalBlock1->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	VerticalBlock1->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	this->m_vGameObj.push_back(VerticalBlock1);
	VerticalBlock1->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	VerticalBlock1->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 0.8f, 0.5f, 0);

	CGameObject* VerticalBlock2 = new CBlocks(4);
	VerticalBlock2->m_name = "Block2";
	VerticalBlock2->m_tag = "Block";
	VerticalBlock2->m_transform.position = glm::vec3(8.5f, -8.7f, 0.0f);
	VerticalBlock2->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	VerticalBlock2->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	this->m_vGameObj.push_back(VerticalBlock2);
	VerticalBlock2->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	VerticalBlock2->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 0.8f, 0.5f, 0);

	CGameObject* VerticalBlock3 = new CBlocks(5);
	VerticalBlock3->m_name = "Block3";
	VerticalBlock3->m_tag = "Block";
	VerticalBlock3->m_transform.position = glm::vec3(11.5f, -8.7f, 0.0f);
	VerticalBlock3->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	VerticalBlock3->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	this->m_vGameObj.push_back(VerticalBlock3);
	VerticalBlock3->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	VerticalBlock3->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 0.8f, 0.5f, 0);

	CGameObject* HorizontalBlock1 = new CBlocks(6);
	HorizontalBlock1->m_name = "Block4";
	HorizontalBlock1->m_tag = "Block";
	HorizontalBlock1->m_transform.position = glm::vec3(7.0f, -7.0f, 0.0f);
	HorizontalBlock1->m_transform.rotation = glm::vec3(0.0f, 0.0f, 90.0f);
	HorizontalBlock1->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	this->m_vGameObj.push_back(HorizontalBlock1);
	HorizontalBlock1->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	HorizontalBlock1->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 0.8f, 0.5f, 0);

	CGameObject* HorizontalBlock2 = new CBlocks(7);
	HorizontalBlock2->m_name = "Block5";
	HorizontalBlock2->m_tag = "Block";
	HorizontalBlock2->m_transform.position = glm::vec3(10.0f, -7.0f, 0.0f);
	HorizontalBlock2->m_transform.rotation = glm::vec3(0.0f, 0.0f, 90.0f);
	HorizontalBlock2->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	this->m_vGameObj.push_back(HorizontalBlock2);
	HorizontalBlock2->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	HorizontalBlock2->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 0.8f, 0.5f, 0);

	CGameObject* VerticalBlock4 = new CBlocks(8);
	VerticalBlock4->m_name = "Block6";
	VerticalBlock4->m_tag = "Block";
	VerticalBlock4->m_transform.position = glm::vec3(7.0f, -5.5f, 0.0f);
	VerticalBlock4->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	VerticalBlock4->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	this->m_vGameObj.push_back(VerticalBlock4);
	VerticalBlock4->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	VerticalBlock4->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 0.8f, 0.5f, 0);

	CGameObject* VerticalBlock5 = new CBlocks(9);
	VerticalBlock5->m_name = "Block7";
	VerticalBlock5->m_tag = "Block";
	VerticalBlock5->m_transform.position = glm::vec3(10.0f, -5.5f, 0.0f);
	VerticalBlock5->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	VerticalBlock5->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	this->m_vGameObj.push_back(VerticalBlock5);
	VerticalBlock5->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	VerticalBlock5->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 0.8f, 0.5f, 0);

	CGameObject* HorizontalBlock3 = new CBlocks(10);
	HorizontalBlock3->m_name = "Block8";
	HorizontalBlock3->m_tag = "Block";
	HorizontalBlock3->m_transform.position = glm::vec3(8.5f, -3.7, 0.0f);
	HorizontalBlock3->m_transform.rotation = glm::vec3(0.0f, 0.0f, 90.0f);
	HorizontalBlock3->m_transform.scale = glm::vec3(0.25f, 0.5f, 0.5f);
	this->m_vGameObj.push_back(HorizontalBlock3);
	HorizontalBlock3->GetComponent<CSpriteRender>()->SetSprite("WoodBlock");
	HorizontalBlock3->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 0.8f, 0.5f, 0);

}

void CTestScene::CreatePigs()
{
	CGameObject* Pig1 = new CBlocks(10);
	Pig1->m_name = "Pig1";
	Pig1->m_tag = "Pig";
	Pig1->m_transform.position = glm::vec3(8.5f, -6.0f, 0.0f);
	Pig1->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	Pig1->m_transform.scale = glm::vec3(0.25f, 0.25f, 0.25f);
	this->m_vGameObj.push_back(Pig1);
	Pig1->GetComponent<CSpriteRender>()->SetSprite("Pig");
	Pig1->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 0.5f, 0);
	Pig1->World = this;
	m_PigCount++;

	CGameObject* Pig2 = new CBlocks(10);
	Pig2->m_name = "Pig2";
	Pig2->m_tag = "Pig";
	Pig2->m_transform.position = glm::vec3(7.0, -9.5f, 0.0f);
	Pig2->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	Pig2->m_transform.scale = glm::vec3(0.25f, 0.25f, 0.25f);
	this->m_vGameObj.push_back(Pig2);
	Pig2->GetComponent<CSpriteRender>()->SetSprite("Pig");
	Pig2->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 0.5f, 0);
	Pig2->World = this;
	m_PigCount++;

	CGameObject* Pig3 = new CBlocks(10);
	Pig3->m_name = "Pig3";
	Pig3->m_tag = "Pig";
	Pig3->m_transform.position = glm::vec3(10.0, -9.5f, 0.0f);
	Pig3->m_transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	Pig3->m_transform.scale = glm::vec3(0.25f, 0.25f, 0.25f);
	this->m_vGameObj.push_back(Pig3);
	Pig3->GetComponent<CSpriteRender>()->SetSprite("Pig");
	Pig3->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 0.5f, 0);
	Pig3->World = this;
	m_PigCount++;

}

void CTestScene::CreateBirdies()
{
	CGameObject* Bird1 = new CSpaceShip(1);
	Bird1->m_name = "Bird1";
	Bird1->m_tag = "Player";
	Bird1->m_transform.scale = glm::vec3(0.05f, 0.05f, 0.05f);
	this->m_vGameObj.push_back(Bird1);
	this->m_vBirds.push_back(dynamic_cast<CSpaceShip*>(Bird1));
	Bird1->GetComponent<CSpriteRender>()->SetSprite("Birdie");
	Bird1->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Bird2 = new CSpaceShip(1);
	Bird2->m_name = "Bird1";
	Bird2->m_tag = "Player";
	Bird2->m_transform.scale = glm::vec3(0.05f, 0.05f, 0.05f);
	this->m_vGameObj.push_back(Bird2);
	this->m_vBirds.push_back(dynamic_cast<CSpaceShip*>(Bird2));
	Bird2->GetComponent<CSpriteRender>()->SetSprite("Birdie");
	Bird2->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Bird3 = new CSpaceShip(1);
	Bird3->m_name = "Bird1";
	Bird3->m_tag = "Player";
	Bird3->m_transform.scale = glm::vec3(0.05f, 0.05f, 0.05f);
	this->m_vGameObj.push_back(Bird3);
	this->m_vBirds.push_back(dynamic_cast<CSpaceShip*>(Bird3));
	Bird3->GetComponent<CSpriteRender>()->SetSprite("Birdie");
	Bird3->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_dynamicBody, true, true, 1.0f, 1.0f, 1);

	CGameObject* Sling = new CBlocks(1);
	Sling->m_name = "Sling";
	Sling->m_tag = "Sling";
	Sling->m_transform.position = glm::vec3(-14.0, -8.5f, 0.0f);
	Sling->m_transform.scale = glm::vec3(0.15f, 0.15f, 0.15f);
	this->m_vGameObj.push_back(Sling);
	Sling->GetComponent<CSpriteRender>()->SetSprite("Sling");
	Sling->GetComponent<CRigiBody2D>()->CreateBodyCircle(GetWorld(), b2_staticBody, true, true, 1.0f, 1.0f, 1);
}