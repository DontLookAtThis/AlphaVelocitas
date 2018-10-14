#include "ConnectionMenu.h"
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
#include "Engine/Sprite.h"
//Includes
#include <memory>
#include "Engine/Sound.h"



void CConnectionMenu::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */

	this->m_sceneName = "Test Scene";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();

	Player1Connected = false;
	Player2Connected = false;
	Player3Connected = false;
	Player4Connected = false;
	ReadyCount = 0;


	CGameObject* BackGround = new CBlocks(1);
	BackGround->SetWorld(this);
	BackGround->m_name = "BackGround";
	BackGround->m_tag = "BackGround";
	BackGround->m_transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
	BackGround->m_transform.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	this->m_vGameObj.push_back(BackGround);
	BackGround->GetComponent<CSpriteRender>()->SetSprite("Background");

	Player1 = new CBlocks(1);
	Player1->SetWorld(this);
	Player1->m_name = "BackGround";
	Player1->m_tag = "BackGround";
	Player1->m_transform.position = glm::vec3(-12.0f, -5.0f, -1.0f);
	Player1->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player1);
	Player1->GetComponent<CSpriteRender>()->SetSprite("Player1");
	Player1->SetActive(false);

	Player2 = new CBlocks(1);
	Player2->SetWorld(this);
	Player2->m_name = "BackGround";
	Player2->m_tag = "BackGround";
	Player2->m_transform.position = glm::vec3(-4.0f, -5.0f, -1.0f);
	Player2->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player2);
	Player2->GetComponent<CSpriteRender>()->SetSprite("Player2");
	Player2->SetActive(false);

	Player3 = new CBlocks(1);
	Player3->SetWorld(this);
	Player3->m_name = "BackGround";
	Player3->m_tag = "BackGround";
	Player3->m_transform.position = glm::vec3(4.0f, -5.0f, -1.0f);
	Player3->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player3);
	Player3->GetComponent<CSpriteRender>()->SetSprite("Player3");
	Player3->SetActive(false);

	Player4 = new CBlocks(1);
	Player4->SetWorld(this);
	Player4->m_name = "BackGround";
	Player4->m_tag = "BackGround";
	Player4->m_transform.position = glm::vec3(12.0f, -5.0f, -1.0f);
	Player4->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Player4);
	Player4->GetComponent<CSpriteRender>()->SetSprite("Player4");
	Player4->SetActive(false);

	//TEXT
	CTextLabel* P1 = new CTextLabel("SpaceFont");
	P1->SetText("P1");
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, -1.0f);
	pos *= util::PIXELUNIT;
	P1->SetPosition({ pos.x + (util::SCR_WIDTH / 2) - 520.0f, pos.y + (util::SCR_HEIGHT / 2) - 30.0f });
	P1->SetScale(1.0f);
	P1->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(P1);

	CTextLabel* P2 = new CTextLabel("SpaceFont");
	P2->SetText("P2");
	P2->SetPosition({ pos.x + (util::SCR_WIDTH / 2) - 200.0f, pos.y + (util::SCR_HEIGHT / 2) - 30.0f });
	P2->SetScale(1.0f);
	P2->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(P2);

	CTextLabel* P3 = new CTextLabel("SpaceFont");
	P3->SetText("P3");
	P3->SetPosition({ pos.x + (util::SCR_WIDTH / 2) + 120.0f, pos.y + (util::SCR_HEIGHT / 2) - 30.0f });
	P3->SetScale(1.0f);
	P3->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(P3);

	CTextLabel* P4 = new CTextLabel("SpaceFont");
	P4->SetText("P4");
	P4->SetPosition({ pos.x + (util::SCR_WIDTH / 2) + 420.0f, pos.y + (util::SCR_HEIGHT / 2) - 30.0f });
	P4->SetScale(1.0f);
	P4->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(P4);

	CTextLabel* Play = new CTextLabel("SpaceFont");
	Play->SetText("Press Y to play");
	Play->SetPosition({ pos.x + (util::SCR_WIDTH / 2) - 350.0f, pos.y + (util::SCR_HEIGHT / 2) + 300.0f });
	Play->SetScale(1.0f);
	Play->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Play);
}

void CConnectionMenu::BeginPlay()
{
	__super::BeginPlay();
}

void CConnectionMenu::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	ReadyCount = 0;

	if (CInput::GetInstance()->Players[0]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		Player1Connected = !Player1Connected;
		Player1->SetActive(Player1Connected);
	}
	if (CInput::GetInstance()->Players[1]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		Player2Connected = !Player2Connected;
		Player2->SetActive(Player2Connected);
	}
	if (CInput::GetInstance()->Players[2]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		Player3Connected = !Player3Connected;
		Player3->SetActive(Player3Connected);
	}
	if (CInput::GetInstance()->Players[3]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		Player4Connected = !Player4Connected;
		Player4->SetActive(Player4Connected);
	}

	if (Player1Connected == true) ReadyCount++;
	if (Player2Connected == true) ReadyCount++;
	if (Player3Connected == true) ReadyCount++;
	if (Player4Connected == true) ReadyCount++;

	if (ReadyCount >= 2)
	{
		if (CInput::GetInstance()->Players[0]->ControllerButtons[TOP_FACE_BUTTON] == INPUT_FIRST_PRESS)
		{
			CSceneMgr::GetInstance()->LoadScene("Test Scene");
		}
		if (CInput::GetInstance()->Players[1]->ControllerButtons[TOP_FACE_BUTTON] == INPUT_FIRST_PRESS)
		{
			CSceneMgr::GetInstance()->LoadScene("Test Scene");
		}
		if (CInput::GetInstance()->Players[2]->ControllerButtons[TOP_FACE_BUTTON] == INPUT_FIRST_PRESS)
		{
			CSceneMgr::GetInstance()->LoadScene("Test Scene");
		}
		if (CInput::GetInstance()->Players[3]->ControllerButtons[TOP_FACE_BUTTON] == INPUT_FIRST_PRESS)
		{
			CSceneMgr::GetInstance()->LoadScene("Test Scene");
		}
	}
}

void CConnectionMenu::ResetScene()
{
	__super::ResetScene();
	Player1Connected = false;
	Player2Connected = false;
	Player3Connected = false;
	Player4Connected = false;
	ReadyCount = 0;
}