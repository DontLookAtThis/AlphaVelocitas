// This Include
#include "Scene.h"

// Local Include
#include "GameObject.h"
#include "SpriteRender.h"
#include "RigidBody2D.h"
#include "Debug.h"
#include "Camera.h"
#include "TextLabel.h"
#include "ContactListener.h"
#include "Engine/Time.h"
#include "Engine/GameObject.h"
//#include "Player.h"
//#include "PowerUps.h"
//#include "AssetMgr.h"
//#include "MeshMgr.h"
//#include "ModelMgr.h"
//#include "SceneMgr.h"
//#include "Input.h"
//#include "CAIMgr.h"
//#include "CubeMap.h"

CScene::CScene()
{
	m_mainCamera = nullptr;
	m_cubemap = nullptr;
	m_gravity = b2Vec2(0.0f, 0.0f);
	m_box2DWorld = new b2World(m_gravity);
	m_ContactListener = new CContactListener();
	m_box2DWorld->SetContactListener(m_ContactListener);
	m_PigCount = 0;
}

CScene::~CScene()
{
	std::cout << "Cleaning Scene... \n";
	// Clean up the memory allocated variables inside the class
	// ========================================================
	delete m_mainCamera;
	m_cubemap = nullptr;

	for (auto obj : m_vGameObj)
	{
		delete obj;
	}
	m_vGameObj.clear();

	delete m_box2DWorld;

	// ========================================================
	std::cout << "Cleaning Done... \n";
}

void CScene::ConfigurateScene() 
{ 
	m_vGameObj.resize(0);
}

void CScene::BeginPlay()
{
	for (auto obj : m_vGameObj)
	{
		obj->BeginPlay();
	}
}

void CScene::RenderScene()
{
	//m_cCubeMap->Render(m_MainCamera);


	
	if (!m_vGameObj.empty())
	{
		for (CGameObject* gameObject : m_vGameObj)
		{
			// GameObject.render()
			
			for (CComponent* comp : gameObject->m_components)
			{
				if (CSpriteRender* spriteRenderer
					= dynamic_cast<CSpriteRender*>(comp))
				{
					spriteRenderer->Render(m_mainCamera);
					//continue;
				}
			}


			
		}
	}

	// Render all the textLabel in the scene
	for (CTextLabel* textLabel : m_vTextLabel)
	{
		textLabel->RenderTextLabel();
	}
	
}

void CScene::ResetScene()
{
	CDebug::Log("Resetting Scene: " + m_sceneName);

	m_cubemap = nullptr;

	m_mainCamera = nullptr;

	for (auto obj : m_vGameObj)
	{
		delete obj;
	}
	m_vGameObj.clear();
}

void CScene::UpdateScene(float _tick)
{
	// Delete the object that should be deleted fron last frame
	for (auto obj : m_vGameObj)
	{
		if (obj->ShouldDestroyed()) { DestroyObject(obj); }
	}	
	// Get each Object in the Scene and do their own Update Function
	size_t currVecSize = m_vGameObj.size();
	for (size_t index = 0; index < currVecSize; ++index)
	{
		m_vGameObj[index]->Update(_tick);
		currVecSize = m_vGameObj.size(); // Revalidate the number of item inside the vector
	}
	// Box2D step
	float32 timeStep = CTime::GetInstance()->GetDeltaTime();
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	m_box2DWorld->Step(timeStep, velocityIterations, positionIterations);
}

void CScene::Instantiate(CGameObject * _gameobj)
{
	_gameobj->BeginPlay();
	m_vGameObj.push_back(_gameobj);
}

void CScene::Instantiate(CGameObject * _gameobj, glm::vec3 _pos)
{
	_gameobj->BeginPlay();
	_gameobj->m_transform.position = _pos;
	m_vGameObj.push_back(_gameobj);
}

void CScene::Instantiate(CGameObject * _gameobj, 
	glm::vec3 _pos, 
	glm::vec3 _rotation, 
	glm::vec3 _scale = glm::vec3(1.0f, 1.0f, 1.0f))
{
	_gameobj->BeginPlay();
	_gameobj->m_transform.position = _pos;
	_gameobj->m_transform.rotation = _rotation;
	_gameobj->m_transform.scale = _scale;
	m_vGameObj.push_back(_gameobj);
}

void CScene::DestroyObject(CGameObject* _gameobj)
{
	for (auto iter = m_vGameObj.begin(); iter != m_vGameObj.end(); ++iter)
	{
		if ((*iter) == _gameobj)
		{
			delete (*iter);
			m_vGameObj.erase(iter);
			return;
		}
	}
}

CGameObject* CScene::FindGameObject(std::string _name) const
{
	// Try find the first game object with the same name
	for (auto iterOject : m_vGameObj)
	{
		// If found, return the game object
		if (iterOject->m_name == _name)
		{
			return iterOject;
		}
	}

	// After loop through the vector, if nothing being found, return nullptr
	return nullptr;
}

std::vector<CGameObject*> CScene::FindGameObjectAll(std::string _name) const
{
	std::vector<CGameObject*> resultVector;

	// Try find game objects with the same name
	for (auto iterOject : m_vGameObj)
	{
		// If found, append it into the vector
		if (iterOject->m_name == _name)
		{
			resultVector.push_back(iterOject);
		}
	}

	// Return the result
	return resultVector;
}

CGameObject* CScene::FindObjectWithTag(std::string _tag) const
{
	// Try find the first game object with the same tag
	for (auto iterOject : m_vGameObj)
	{
		if (iterOject->m_tag == _tag)
		{
			return iterOject;
		}
	}

	// After loop through the vector, if nothing being found, return nullptr
	return nullptr;
}

std::vector<CGameObject*> CScene::FindObjectWithTagAll(std::string _tag) const
{
	std::vector<CGameObject*> resultVector;

	// Try find game objects with the same tag
	for (auto iterOject : m_vGameObj)
	{
		// If found, append it into the vector
		if (iterOject->m_tag == _tag)
		{
			resultVector.push_back(iterOject);
		}
	}

	// Return the result
	return resultVector;
}

b2World* CScene::GetWorld() const
{
	return m_box2DWorld;
}

std::vector<CGameObject*> CScene::GetObjectVec() const
{
	return m_vGameObj;
}
