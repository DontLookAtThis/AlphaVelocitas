
// This Include
#include "AssetMgr.h"

// Engine Include
#include "ShaderLoader.h"
#include "Sprite.h"
#include "Debug.h"

// Static Variable
CAssetMgr* CAssetMgr::s_pAssetMgr = nullptr;

CAssetMgr* CAssetMgr::GetInstance()
{
	if (s_pAssetMgr == nullptr)
	{
		s_pAssetMgr = new CAssetMgr();
	}

	return s_pAssetMgr;
}

void CAssetMgr::DestroyInstance()
{
	delete s_pAssetMgr;
	s_pAssetMgr = nullptr;
}

CAssetMgr::CAssetMgr() {}
CAssetMgr::~CAssetMgr() {}

void CAssetMgr::InitializeAssets()
{
	/** Initialize Programs */
	CreateProgram("DefaultSpriteProgram", "Engine/Shaders/Sprite.vs", "Engine/Shaders/Sprite.fs");

	/** Initialize Sprites */
	CreateSprite("DefaultSprite", "Resources/Sprites/DefaultSprite.png");
	CreateSprite("Triangle", "Resources/Sprites/Player2.png");
	CreateSprite("Block", "Resources/Sprites/Block.png");
	CreateSprite("Player", "Resources/Sprites/spaceship.png");
	CreateSprite("Gate", "Resources/Sprites/gate.png");
	CreateSprite("Collectable", "Resources/Sprites/collectable.png");
	CreateSprite("Birdie", "Resources/Sprites/Bird.png");
	CreateSprite("BackGround", "Resources/Sprites/Backgrounds/blue_grass.png");
	CreateSprite("WoodBlock", "Resources/Sprites/Wood elements/elementWood019.png");
	CreateSprite("Pig", "Resources/Sprites/Happy_pig.png");
	CreateSprite("Ground", "Resources/Sprites/Other/grass.png");
	CreateSprite("Sling", "Resources/Sprites/Slingshot.png");
}


CSprite* CAssetMgr::GetSprite(std::string _name) const
{
	for (auto iter = m_spriteMap.begin(); iter != m_spriteMap.end(); ++iter)
	{
		if (iter->first == _name)
		{
			return iter->second;
		}
	}

	CDebug::Log("Unable to grab sprite from name.");
	return nullptr;
}

GLuint CAssetMgr::GetProgramID(std::string _name) const
{
	for (auto iter = m_programMap.begin(); iter != m_programMap.end(); ++iter)
	{
		if (iter->first == _name)
		{
			return iter->second;
		}
	}

	CDebug::Log("Unable to grab program ID from name.");
	return NULL;
}

void CAssetMgr::CreateProgram(std::string _name, const char* _vertexPath, const char* _fragmentPath)
{
	GLuint newProgram = ShaderLoader::CreateProgram(_vertexPath, _fragmentPath);

	m_programMap.insert(std::pair<std::string, GLuint>(_name, newProgram));
}

void CAssetMgr::CreateSprite(std::string _name, const char* _pathName)
{
	CSprite* newSprite = new CSprite();
	newSprite->CreateSprite(_pathName);

	m_spriteMap.insert(std::pair<std::string, CSprite*>(_name, newSprite));
}
