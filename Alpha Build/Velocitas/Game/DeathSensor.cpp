
// This Include
#include "DeathSensor.h"

// Game Include
#include "SpaceShip.h"

// Engine Include
#include "Engine/Scene.h"
#include "Engine/Camera.h"
#include "Engine/SpriteRender.h"
#include "Engine/Sprite.h"
#include "Engine/RigidBody2D.h"

CDeathSensor::CDeathSensor(ERELATIVEPOSITION _relativePosition) :
	m_shrinkPercentage(1.0f),
	m_relatviePosition(_relativePosition)
{
	m_spriteRender = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();

	m_spriteRender->SetSprite("DeathSensor");
}

CDeathSensor::~CDeathSensor()
{}

void CDeathSensor::BeginPlay()
{
	__super::BeginPlay();
	
	// Get the main camera of the scene
	m_followingCamera = m_Scene->GetMainCamera();

	// Set the scale of the sprite according to the Camera
	float scalerX, scalerY;
	scalerX = m_followingCamera->m_viewPortWidth / (float)m_spriteRender->GetSprite()->GetWidth();
	scalerY = m_followingCamera->m_viewPortHeight / (float)m_spriteRender->GetSprite()->GetHeight();
	m_transform.scale.x = scalerX;
	m_transform.scale.y = scalerY;

	// Create a body and its fixture
	m_rigidBody->CreateSensorCube(m_Scene->GetWorld(), b2_staticBody, false);

	// Set the position to the relative position to the camera
	switch (m_relatviePosition)
	{
	case CAM_TOP:
		m_relativePositionX = 0.0f;
		m_relativePositionY = (m_followingCamera->m_viewPortHeight / (float)util::PIXELUNIT);
		break;

	case CAM_BOTTOM:
		m_relativePositionX = 0.0f;
		m_relativePositionY = -(m_followingCamera->m_viewPortHeight / (float)util::PIXELUNIT);
		break;
	
	case CAM_LEFT:
		m_relativePositionX = -(m_followingCamera->m_viewPortWidth / (float)util::PIXELUNIT);
		m_relativePositionY = 0.0f;
		break;
	
	case CAM_RIGHT:
		m_relativePositionX = (m_followingCamera->m_viewPortWidth / (float)util::PIXELUNIT);
		m_relativePositionY = 0.0f;
		break;
	
	default: break;
	}

	// Set the postion of the death sensor the first time
	SetPositionBaseOnShrink();

}

void CDeathSensor::Update(float _tick)
{
	__super::Update(_tick);
	
	// Update the position every single frame cuz the camera is constantly moving
	SetPositionBaseOnShrink();
}

void CDeathSensor::OnCollisionEnter(CGameObject* CollidedObject)
{
	__super::OnCollisionEnter(CollidedObject);
	
	// If any ship touch is death zone, they die!!!!
	if (CSpaceShip* spaceShip = dynamic_cast<CSpaceShip*>(CollidedObject))
	{
		spaceShip->Die();
	}
}

void CDeathSensor::SetPositionBaseOnShrink()
{
	b2Vec2 position;
	position.x = m_followingCamera->m_cameraPosition.x + (m_relativePositionX * m_shrinkPercentage);
	position.y = m_followingCamera->m_cameraPosition.y + (m_relativePositionY * m_shrinkPercentage);

	m_rigidBody->GetBody()->SetTransform(position, m_rigidBody->GetBody()->GetAngle());

}

void CDeathSensor::SetShrinkPercentage(float _percentage)
{
	m_shrinkPercentage = _percentage;
}

float CDeathSensor::GetShrinkPercentage() const
{
	return m_shrinkPercentage;
}

ERELATIVEPOSITION CDeathSensor::GetRelativePosition() const
{
	return m_relatviePosition;
}
