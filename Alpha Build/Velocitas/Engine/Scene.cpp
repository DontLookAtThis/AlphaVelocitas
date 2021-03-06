// This Include
#include "Scene.h"

// Local Include
#include "GameObject.h"
#include "SpriteRender.h"
#include "RigidBody2D.h"
#include "Debug.h"
#include "Camera.h"
//#include "Player.h"
//#include "PowerUps.h"
//#include "AssetMgr.h"
//#include "MeshMgr.h"
//#include "ModelMgr.h"
//#include "SceneMgr.h"
//#include "Input.h"
//#include "CAIMgr.h"
//#include "CubeMap.h"
//#include "TextLabel.h"
#include "ContactListener.h"

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

			if (CSpriteRender* spriteRenderer
				= gameObject->GetComponent<CSpriteRender>())
			{
				spriteRenderer->Render(m_mainCamera);
				//continue;
			}
		}
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
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	if (_tick == 0)
	{
		m_box2DWorld->Step(timeStep, velocityIterations, positionIterations);
	}

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

	//CheckCollision();
}

/* Legacy code */
// void CScene::CheckCollision()
// {
// 	size_t currVecSize = m_vGameObj.size();
// 	for (size_t index = 0; index < currVecSize; ++index)
// 	{
// 		if (m_vGameObj[index]->HasCollider()) // Check if object itself has a collider
// 		{
// 			// Get the collistion detail of the object
// 			float selfCollider = m_vGameObj[index]->GetCollisionRad();
// 			glm::vec3 selfPos = m_vGameObj[index]->GetTransform();
// 
// 			// Check with all the rest of the other objects
// 			for (size_t i = index + 1; i < currVecSize; ++i)
// 			{
// 				if (m_vGameObj[i]->HasCollider())
// 				{
// 					// Get the other objects' collision detail
// 					float otherCollider = m_vGameObj[i]->GetCollisionRad();
// 					glm::vec3 otherPos = m_vGameObj[i]->GetTransform();
// 
// 					float distance = glm::distance(selfPos, otherPos);
// 					if (distance <= (selfCollider + otherCollider))
// 					{
// 						m_vGameObj[index]->OnCollision(m_vGameObj[i]);
// 						m_vGameObj[i]->OnCollision(m_vGameObj[index]);
// 					}
// 				}
// 			}
// 		}
// 		
// 
// 
// 		currVecSize = m_vGameObj.size(); // Revalidate the number of item inside the vector
// 	}
// }

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

b2World* CScene::GetWorld() const
{
	return m_box2DWorld;
}

std::vector<CGameObject*> CScene::GetObjectVec() const
{
	return m_vGameObj;
}
