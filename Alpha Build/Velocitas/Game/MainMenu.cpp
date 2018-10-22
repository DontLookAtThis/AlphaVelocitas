#include "MainMenu.h"
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
#include "TestScene.h"
//Includes
#include <memory>
#include "Engine/Sound.h"



void CMainMenu::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */

	this->m_sceneName = "Test Scene";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();

	CGameObject* BackGround = new CBlocks(1);
	BackGround->SetWorld(this);
	BackGround->m_name = "BackGround";
	BackGround->m_tag = "BackGround";
	BackGround->m_transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
	BackGround->m_transform.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	this->m_vGameObj.push_back(BackGround);
	BackGround->GetComponent<CSpriteRender>()->SetSprite("Background");


	Button1 = new CBlocks(1);
	Button1->SetWorld(this);
	Button1->m_name = "BackGround";
	Button1->m_tag = "BackGround";
	Button1->m_transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
	Button1->m_transform.scale = glm::vec3(4.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Button1);
	Button1->GetComponent<CSpriteRender>()->SetSprite("Block");


	Button2 = new CBlocks(1);
	Button2->SetWorld(this);
	Button2->m_name = "BackGround";
	Button2->m_tag = "BackGround";
	Button2->m_transform.position = glm::vec3(0.0f, -3.0f, -1.0f);
	Button2->m_transform.scale = glm::vec3(4.0f, 1.0f, 1.0f);
	this->m_vGameObj.push_back(Button2);
	Button2->GetComponent<CSpriteRender>()->SetSprite("Block");

	Play = new CTextLabel("SpaceFont");
	Play->SetText("Play - A");
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, -1.0f);
	pos *= util::PIXELUNIT;
	Play->SetPosition({ pos.x + (util::SCR_WIDTH/2) - 140.0f, pos.y + (util::SCR_HEIGHT /2) - 20.0f});
	Play->SetScale(0.7f);
	Play->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Play);

	Quit = new CTextLabel("SpaceFont");
	Quit->SetText("Quit - Y");
	Quit->SetPosition({ pos.x + (util::SCR_WIDTH / 2) - 140.0f, pos.y + (util::SCR_HEIGHT / 2) - 140.0f });
	Quit->SetScale(0.7f);
	Quit->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Quit);

	Velocitas = new CTextLabel("SpaceFont");
	Velocitas->SetText("Velocitas");
	Velocitas->SetPosition({ pos.x + (util::SCR_WIDTH / 2) - 450.0f, pos.y + (util::SCR_HEIGHT / 2) + 80.0f });
	Velocitas->SetScale(2.0f);
	Velocitas->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(Velocitas);

}

void CMainMenu::BeginPlay()
{
	__super::BeginPlay();
}

void CMainMenu::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	m_mouseX = CInput::GetInstance()->MouseX;
	m_mouseY = CInput::GetInstance()->MouseY;
	m_mouseX = m_mouseX - (util::SCR_WIDTH / 2);
	m_mouseY = -(m_mouseY - (util::SCR_HEIGHT / 2));


	//std::cout << m_mouseX << std::endl;
	//std::cout << m_mouseY << std::endl;


	if (m_mouseX < (Button1->m_transform.position.x *util::PIXELUNIT) + (Button1->GetComponent<CSpriteRender>()->GetSprite()->GetWidth() * Button1->m_transform.scale.x /2) &&
		m_mouseX > (Button1->m_transform.position.x *util::PIXELUNIT) - (Button1->GetComponent<CSpriteRender>()->GetSprite()->GetWidth() * Button1->m_transform.scale.x / 2) &&
		m_mouseY < (Button1->m_transform.position.y *util::PIXELUNIT) + (Button1->GetComponent<CSpriteRender>()->GetSprite()->GetHeight() * Button1->m_transform.scale.y / 2) &&
		m_mouseY > (Button1->m_transform.position.y *util::PIXELUNIT) - (Button1->GetComponent<CSpriteRender>()->GetSprite()->GetHeight() * Button1->m_transform.scale.y / 2))
	{
		if (CInput::GetInstance()->g_cMouseState[0] == INPUT_FIRST_PRESS)
		{
			CSceneMgr::GetInstance()->LoadScene("ConnectionScene");
			return;
		}
	}

	if (m_mouseX < (Button2->m_transform.position.x *util::PIXELUNIT) + (Button2->GetComponent<CSpriteRender>()->GetSprite()->GetWidth() * Button2->m_transform.scale.x / 2) &&
		m_mouseX > (Button2->m_transform.position.x *util::PIXELUNIT) - (Button2->GetComponent<CSpriteRender>()->GetSprite()->GetWidth() * Button2->m_transform.scale.x / 2) &&
		m_mouseY < (Button2->m_transform.position.y *util::PIXELUNIT) + (Button2->GetComponent<CSpriteRender>()->GetSprite()->GetHeight()* Button2->m_transform.scale.y / 2) &&
		m_mouseY > (Button2->m_transform.position.y *util::PIXELUNIT) - (Button2->GetComponent<CSpriteRender>()->GetSprite()->GetHeight() * Button2->m_transform.scale.y / 2))
	{
		if (CInput::GetInstance()->g_cMouseState[0] == INPUT_FIRST_PRESS)
		{
			exit(0);
		}
	}

	if (CInput::GetInstance()->Players[0]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->LoadScene("ConnectionScene");
		return;
	}
	if (CInput::GetInstance()->Players[1]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->LoadScene("ConnectionScene");
		return;
	}
	if (CInput::GetInstance()->Players[2]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->LoadScene("ConnectionScene");
		return;
	}
	if (CInput::GetInstance()->Players[3]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->LoadScene("ConnectionScene");
		return;
	}

	if (CInput::GetInstance()->Players[0]->ControllerButtons[TOP_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		exit(0);
	}
	if (CInput::GetInstance()->Players[1]->ControllerButtons[TOP_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		exit(0);
	}
	if (CInput::GetInstance()->Players[2]->ControllerButtons[TOP_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		exit(0);
	}
	if (CInput::GetInstance()->Players[3]->ControllerButtons[TOP_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		exit(0);
	}
}

void CMainMenu::ResetScene()
{
	__super::ResetScene();

}
