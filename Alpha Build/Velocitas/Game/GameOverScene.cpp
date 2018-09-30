#include "GameOverScene.h"
#include "SpaceShip.h"
void CGameOver::ConfigurateScene()
{
	CTextLabel* GameOver = new CTextLabel("SpaceFont");
	GameOver->SetText("Game Over");
	GameOver->SetPosition(glm::vec2((util::SCR_WIDTH / 4) + 180.0f, util::SCR_HEIGHT / 2));
	GameOver->SetScale(1.0f);
	GameOver->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextLabel.push_back(GameOver);

	//CTextLabel* WinnerText = new CTextLabel("SpaceFont");
	//WinnerText->SetText("Congradulations" + dynamic_cast<CSpaceShip*>(Winner->m_name));
	//WinnerText->SetPosition(glm::vec2((util::SCR_WIDTH / 4) + 180.0f, util::SCR_HEIGHT / 2));
	//WinnerText->SetScale(1.0f);
	//WinnerText->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	//m_vTextLabel.push_back(WinnerText);
}

void CGameOver::BeginPlay()
{
	__super::BeginPlay();
}

void CGameOver::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
}
