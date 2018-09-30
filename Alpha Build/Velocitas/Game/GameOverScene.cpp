#include "GameOverScene.h"

void CGameOver::ConfigurateScene()
{
	CTextLabel* GameOver = new CTextLabel("SpaceFont");
	GameOver->SetText("Game Over");
	GameOver->SetPosition(glm::vec2((util::SCR_WIDTH / 4) + 180.0f, util::SCR_HEIGHT / 2));
	GameOver->SetScale(1.0f);
	GameOver->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_vTextList.push_back(GameOver);
}

void CGameOver::BeginPlay()
{
	__super::BeginPlay();
}

void CGameOver::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
}
