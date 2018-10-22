
// This Include
#include "GameOverScene.h"

// Game Class Include
#include "SpaceShip.h"

// Engine Include
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/SceneMgr.h"

void CGameOver::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */

	this->m_sceneName = "Test Scene";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();

	/** Create game objects in the scenes */

	CTextLabel* GameOver = new CTextLabel("SpaceFont");
	GameOver->SetText("Game Over");
	GameOver->SetPosition(glm::vec2((util::SCR_WIDTH / 4) + 180.0f, util::SCR_HEIGHT / 2 + 100.0f));
	GameOver->SetScale(1.0f);
	GameOver->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(GameOver);

	CTextLabel* PressButtonToGoBack = new CTextLabel("SpaceFont");
	PressButtonToGoBack->SetText("Press A to Continue");
	PressButtonToGoBack->SetPosition(glm::vec2((util::SCR_WIDTH / 4), util::SCR_HEIGHT / 2 - 100.0f));
	PressButtonToGoBack->SetScale(1.0f);
	PressButtonToGoBack->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(PressButtonToGoBack);

	/*CTextLabel* WinnerText = new CTextLabel("SpaceFont");
	WinnerText->SetText("Congradulations" + Winner->m_name);
	WinnerText->SetPosition(glm::vec2((util::SCR_WIDTH / 4) + 180.0f, (util::SCR_HEIGHT / 2) - 50.0f));
	WinnerText->SetScale(1.0f);
	WinnerText->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(WinnerText);*/
}

void CGameOver::BeginPlay()
{
	__super::BeginPlay();
}

void CGameOver::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);

	if (CInput::GetInstance()->g_cKeyState[(unsigned char)'a'] == INPUT_FIRST_PRESS
		|| CInput::GetInstance()->Players[0]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS)
	{
		CSceneMgr::GetInstance()->RestScore();
		CSceneMgr::GetInstance()->LoadScene("MainMenu");
	}
}
