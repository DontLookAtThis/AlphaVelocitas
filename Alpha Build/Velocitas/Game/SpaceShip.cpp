
// This Include
#include "SpaceShip.h"
#include "GrapplingHook.h"
// Engine Include
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRender.h"
#include "Engine/RigidBody2D.h"
#include "Engine/Input.h"
#include "Engine/Utility.h"
#include "Engine/Camera.h"
#include "Engine/Time.h"
#include "RailgunShot.h"
CSpaceShip::CSpaceShip(int playerID)
{
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();
	bInputEnabled = true;
	m_iPlayerID = playerID;
	bControllerInput = true;
	m_fCurrentRotation = 0;
	bHasBeenFired = false;
	bIsLoaded = false;
	bIsHeld = false;
	fMovementSpeed = 2.0f;
	m_fInputReEnabletime = 2.0f;
	m_fGravityWellDuration = 4.0f;
}

CSpaceShip::~CSpaceShip()
{}

void CSpaceShip::BeginPlay()
{
	__super::BeginPlay();
	
	/** Set the sprite for the object */
	//m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Triangle"));
	//m_spriteRenderer->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));

}

void CSpaceShip::Update(float _tick)
{
	__super::Update(_tick);

	//CInput::GetInstance()->g_cKeyState[]
	MovementChecks();
	b2Body* myBody = Get2DBody()->GetBody();
	if (myBody)
	{
		Movement();
	}
	//Reenabling Input;
	if (!bInputEnabled)
	{ 
		m_fInputReEnabletime -= CTime::GetInstance()->GetDeltaTime();
	}
	if (m_fInputReEnabletime <= 0)
	{
		m_fInputReEnabletime = 3.0f;
		bInputEnabled = true;
	}
	//-----------------

	//Disabling Gravity
	if (Get2DBody()->m_bHasGravityWell == true)
	{
		m_fGravityWellDuration -= CTime::GetInstance()->GetDeltaTime();
	}
	if (m_fGravityWellDuration <= 0)
	{
		m_fGravityWellDuration = 4.0f;
		Get2DBody()->m_bHasGravityWell = false;
	}
	//-----------------
	UseItem();
}

void CSpaceShip::MovementChecks()
{
	if (!bInputEnabled) return;
	bUpPressed = false;
	bDownPressed = false;
	bLeftPressed = false;
	bRightPressed = false;

	glm::vec2 Direction = { 0, 0 };
	glm::vec2 LeftThumbStick = { CInput::GetInstance()->Players[m_iPlayerID - 1]->GetState().Gamepad.sThumbLX , CInput::GetInstance()->Players[m_iPlayerID - 1]->GetState().Gamepad.sThumbLY };
	if (!bControllerInput)
	{
		bLeftPressed = m_iPlayerID == 2 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'a'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'a'] == INPUT_FIRST_PRESS);
		bRightPressed = m_iPlayerID == 2 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'d'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'d'] == INPUT_FIRST_PRESS);
		bUpPressed = m_iPlayerID == 2 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'w'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'w'] == INPUT_FIRST_PRESS);
		bDownPressed = m_iPlayerID == 2 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'s'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'s'] == INPUT_FIRST_PRESS);
		bFirePressed = m_iPlayerID == 2 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'j'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'j'] == INPUT_FIRST_PRESS);
	}
	else
	{
		bLeftPressed = (CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[DPAD_LEFT] == INPUT_FIRST_PRESS
			|| CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[DPAD_LEFT] == INPUT_HOLD);
		bRightPressed = (CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[DPAD_RIGHT] == INPUT_FIRST_PRESS
			|| CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[DPAD_RIGHT] == INPUT_HOLD);

		if (CInput::GetInstance()->Players[m_iPlayerID -1]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_FIRST_PRESS 
			|| CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[BOTTOM_FACE_BUTTON] == INPUT_HOLD)
		{
			bUpPressed = true;
		}
		else
		{
			bUpPressed = false;
		}
		if (CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[RIGHT_FACE_BUTTON] == INPUT_FIRST_PRESS
			|| CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[RIGHT_FACE_BUTTON] == INPUT_HOLD)
		{
			bDownPressed = true;
		}
		else
		{
			bDownPressed = false;
		}
		if (CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[LEFT_FACE_BUTTON] == INPUT_FIRST_PRESS
			|| CInput::GetInstance()->Players[m_iPlayerID - 1]->ControllerButtons[LEFT_FACE_BUTTON] == INPUT_HOLD)
		{
			bFirePressed = true;
		}
		else
		{
			bFirePressed = false;
		}
	}
}

void CSpaceShip::SetIsController(bool _bIsController)
{
	bControllerInput = _bIsController;
}

CRigiBody2D * CSpaceShip::Get2DBody()
{
	if (GetComponent<CRigiBody2D>())
	{
		return GetComponent<CRigiBody2D>();
	}
	else
	{
		return nullptr;
	}
}

void CSpaceShip::Movement()
{
	float Right = 0;
	float up = 0;
	if (bLeftPressed) { Right += 1.5f; };
	if (bRightPressed) { Right -= 1.5f; };
	if (bUpPressed) { up++; };
	if (bDownPressed) { up -= 0.5f; };
	m_fCurrentRotation += (Right * 2);
	b2Body* myBody = Get2DBody()->GetBody();
	if (myBody)
	{
		myBody->SetTransform(myBody->GetPosition(), (m_fCurrentRotation / 180 * b2_pi));
		m_FacingDirection = b2Vec2(0.0f, 1.0f);
		RotateVecotr(m_FacingDirection, m_fCurrentRotation);
		m_FacingDirection.Normalize();
		b2Vec2 direction = m_FacingDirection;
		direction *= (float)up * fMovementSpeed; // 10.0f;
		myBody->ApplyForceToCenter(direction, true);
	}
	return;
}

void CSpaceShip::Movement(bool bLeft, bool bRight, bool bUp, bool bDown)
{
	float Right = 0;
	float up = 0;
	if (bLeft) { Right += 1.5f; };
	if (bRight) { Right -= 1.5f; };
	if (bUp) { up++; };
	if (bDown) { up -= 0.5f; };
	m_fCurrentRotation += (Right * 2);
	b2Body* myBody = Get2DBody()->GetBody();
	if (myBody)
	{
		myBody->SetTransform(myBody->GetPosition(), (m_fCurrentRotation / 180 * b2_pi));
		m_FacingDirection = b2Vec2(0.0f, 1.0f);
		RotateVecotr(m_FacingDirection, m_fCurrentRotation);
		m_FacingDirection.Normalize();
		b2Vec2 direction = m_FacingDirection;
		direction *= (float)up * fMovementSpeed; // 10.0f;
		myBody->ApplyForceToCenter(direction, true);
	}
	return;
}

void CSpaceShip::MouseMovement(float MouseX, float MouseY)
{

	b2Body* myBody = Get2DBody()->GetBody();
	if (myBody)
	{
		this->m_transform.position = glm::vec3(myBody->GetPosition().x, myBody->GetPosition().y, 0.0f);
		this->m_transform.rotation.z = m_fCurrentRotation;
		if (bIsLoaded)
		{
			myBody->SetGravityScale(0.0f);
			//myBody->ApplyForceToCenter(b2Vec2(0.0f, 7.0f), true);
			if (!bIsHeld && !bHasBeenFired && bIsLoaded)
			{
				myBody->SetTransform(b2Vec2(-14.0, -6.5f), (m_fCurrentRotation / 180 * b2_pi));
			}
			if (bIsHeld)
			{
				if (CInput::GetInstance()->g_cMouseState[0] == INPUT_RELEASED)
				{
					myBody->SetGravityScale(1.0f);
					bIsHeld = false;
					bHasBeenFired = true;
					bIsLoaded = false;
					b2Vec2 Impulse = b2Vec2(-14.0, -6.5f) - b2Vec2(myBody->GetPosition().x, myBody->GetPosition().y);
					Impulse *= 4.0f;
					myBody->ApplyLinearImpulseToCenter(Impulse, true);
				}
				else
				{
					if ((b2Vec2(MouseX, MouseY) - b2Vec2(-14.0, -6.5f)).Length() < 3.5f)
					{
						myBody->SetTransform(b2Vec2(MouseX, MouseY), (m_fCurrentRotation / 180 * b2_pi));
					}
					else
					{
						b2Vec2 Direction = (b2Vec2(MouseX, MouseY) - b2Vec2(-14.0, -6.5f));
						Direction.Normalize();
						Direction *= 3.5f;
						b2Vec2 position = b2Vec2(-14.0, -6.5f) + Direction;
						myBody->SetTransform(position, (m_fCurrentRotation / 180 * b2_pi));
					}
				}
			}
			else if (!bHasBeenFired && bIsLoaded)
			{
				if (!bIsHeld && (b2Vec2(MouseX, MouseY) - b2Vec2(myBody->GetPosition().x, myBody->GetPosition().y)).Length() < Get2DBody()->fRadius)
				{
					if (CInput::GetInstance()->g_cMouseState[0] == INPUT_HOLD)
					{
						bIsHeld = true;
					}
				}
			}
		}
		else
		{

		}
	}

}

void CSpaceShip::RotateVecotr(b2Vec2 & Vector, float fDeg)
{
	float px = Vector.x * cosf(fDeg / 180 * b2_pi) - Vector.y * sinf(fDeg / 180 * b2_pi);
	float py = Vector.x * sinf(fDeg / 180 * b2_pi) + Vector.y * cosf(fDeg / 180 * b2_pi);
	Vector.x = px;
	Vector.y = py;
}

void CSpaceShip::UseItem()
{
	if (bFirePressed)
	{
		switch (CurrentItem)
		{
		case ITEM_NONE:
			break;
		case ITEM_RAILGUN:
			CurrentItem = ITEM_NONE;
			m_Scene->Instantiate(new CRailgunShot(m_FacingDirection, this));
			break;
		case ITEM_GRAVITYWELL:
			CurrentItem = ITEM_NONE;
			Get2DBody()->m_bHasGravityWell = true;
			break;
		case ITEM_GRAPPLINGHOOK:
			CurrentItem = ITEM_NONE;
			m_Scene->Instantiate(new CGrapplingHook(m_FacingDirection, this));
			break;
		}
	}
}
