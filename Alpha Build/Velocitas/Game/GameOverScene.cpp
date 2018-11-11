
// This Include
#include "GameOverScene.h"

// Game Class Include
#include "SpaceShip.h"

// Engine Include
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/SceneMgr.h"

// Game Classes Include
#include "Blocks.h"

void CGameOver::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */

	this->m_sceneName = "Test Scene";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();

	/** Create game objects in the scenes */

	CGameObject* BackGround = new CBlocks(1);
	BackGround->SetWorld(this);
	BackGround->m_name = "BackGround";
	BackGround->m_tag = "BackGround";
	BackGround->m_transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
	BackGround->m_transform.scale = glm::vec3(2.0f, 2.0f, 2.0f);
	BackGround->GetComponent<CSpriteRender>()->SetSprite("Background");
	this->m_vGameObj.push_back(BackGround);

	CTextLabel* GameOver = new CTextLabel("Taurus");
	GameOver->SetText("Game Over");
	GameOver->SetPosition(glm::vec2((util::SCR_WIDTH / 4) + 140.0f, util::SCR_HEIGHT / 2 + 200.0f));
	GameOver->SetScale(1.5f);
	GameOver->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(GameOver);

	CTextLabel* WinnerText = new CTextLabel("Taurus-Bold");
	WinnerText->SetText("Congradulations " + CSceneMgr::GetInstance()->m_finalWinner);
	WinnerText->SetPosition(glm::vec2((util::SCR_WIDTH / 4) - 50.0f, (util::SCR_HEIGHT / 2) ));
	WinnerText->SetScale(1.0f);
	WinnerText->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(WinnerText);

	CTextLabel* PressButtonToGoBack = new CTextLabel("Taurus");
	PressButtonToGoBack->SetText("Press A to Continue");
	PressButtonToGoBack->SetPosition(glm::vec2((util::SCR_WIDTH / 4) + 140.0f, util::SCR_HEIGHT / 2 - 200.0f));
	PressButtonToGoBack->SetScale(0.7f);
	PressButtonToGoBack->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(PressButtonToGoBack);
}

void CGameOver::BeginPlay()
{
	__super::BeginPlay();
}

void CGameOver::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);

	if (CInput::GetInstance()->g_cKeyState[(unsigned char)'a'] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->ResetScore();
		CSceneMgr::GetInstance()->LoadScene("MainMenu");
		return;
	}
	if (CInput::GetInstance()->Players[0]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->ResetScore();
		CSceneMgr::GetInstance()->LoadScene("MainMenu");
		return;
	}
	if (CInput::GetInstance()->Players[1]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->ResetScore();
		CSceneMgr::GetInstance()->LoadScene("MainMenu");
		return;
	}
	if (CInput::GetInstance()->Players[2]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->ResetScore();
		CSceneMgr::GetInstance()->LoadScene("MainMenu");
		return;
	}
	if (CInput::GetInstance()->Players[3]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->ResetScore();
		CSceneMgr::GetInstance()->LoadScene("MainMenu");
		return;
	}
}
