
// This Include
#include "SceneMgr.h"

// Local Include
#include "Scene.h"
#include "Debug.h"

#include "Game/TestScene.h"
#include "Game/GameOverScene.h"

// Static Variable
CSceneMgr* CSceneMgr::s_pSceneMgr = nullptr;

CSceneMgr* CSceneMgr::GetInstance()
{
	if (s_pSceneMgr == nullptr)
	{
		s_pSceneMgr = new CSceneMgr();
	}

	return s_pSceneMgr;
}

void CSceneMgr::DestroyInstance()
{
	delete s_pSceneMgr;
	s_pSceneMgr = nullptr;
}

void CSceneMgr::InitializeScenes()
{
	/** Create scenes that is going to build in the game */
	CreateNewScene("Test Scene", new CTestScene());
	CreateNewScene("GameOver Scene", new CGameOver());
	//CreateNewScene("Second Scene", new CTestScene());

	/** Run the first scene */
	
	if (!m_scenes.empty())
	{
		LoadScene("Test Scene");
	}
	else
	{
		CDebug::Log("There is no scene builded.");
	}
}

void CSceneMgr::RenderCurrentScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_runningScene->RenderScene();
}

void CSceneMgr::UpdateCurrentScene(float _tick)
{
	// Only Proccess the current running scene
	m_runningScene->UpdateScene(_tick);
}

void CSceneMgr::CreateNewScene(std::string _name, CScene* _scene)
{
	_scene->m_sceneName = _name;
	m_scenes.insert(std::pair<std::string, CScene*>(_name, _scene));
}

void CSceneMgr::LoadScene(std::string _name)
{
	// Reset the current scene
	if (m_runningScene != nullptr)
	{
		m_runningScene->ResetScene();
	}
	
	// Jump to another scene and initialise 
	for (auto iter = m_scenes.begin(); iter != m_scenes.end(); ++iter)
	{
		if (iter->first == _name)
		{
			// Assign the runnig scene to the new scene and initiate it
			m_runningScene = iter->second;
			m_runningScene->ConfigurateScene();
			m_runningScene->BeginPlay();
		}
	}
}

CScene* CSceneMgr::GetRunningScene() const
{
	return m_runningScene;
}

void CSceneMgr::RestScore()
{
	m_playerOneScore = 0;
	m_playerTwoScore = 0;
	m_playerThreeScore = 0;
	m_playerFourScore = 0;
}

CSceneMgr::CSceneMgr()
{
	m_runningScene = nullptr;
}

CSceneMgr::~CSceneMgr()
{
	for (auto iter = m_scenes.begin(); iter != m_scenes.end(); ++iter)
	{
		delete iter->second;
	}
	m_scenes.clear();
}
