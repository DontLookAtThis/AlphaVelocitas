#pragma once

// Inherited Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigiBody2D;
class CCamera;

/**
 * The place of the death sensor 
 * relative to the camera view port
 */
enum ERELATIVEPOSITION
{
	CAM_TOP,
	CAM_BOTTOM,
	CAM_LEFT,
	CAM_RIGHT,
};

class CDeathSensor : public CGameObject
{

public:

	CDeathSensor(ERELATIVEPOSITION _relativePosition);
	virtual ~CDeathSensor();

	/** Derived Functions */
	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	virtual void OnCollisionEnter(CGameObject* CollidedObject);

	/**
	 * Set the relative position of the sensor base on the
	 * relative camera position and the shrink percentage
	 */
	void SetPositionBaseOnShrink();

	/** Getters and Setters ---------------------------------*/

	void SetShrinkPercentage(float _percentage);
	float GetShrinkPercentage() const;

	ERELATIVEPOSITION GetRelativePosition() const;

private:

	/** Components */
	CSpriteRender* m_spriteRender;
	CRigiBody2D* m_rigidBody;

	/** Member Data */

	// The relative position of the object according to the camera
	ERELATIVEPOSITION m_relatviePosition;
	float m_relativePositionX;
	float m_relativePositionY;

	// How much screen space does the death sensor cover
	float m_shrinkPercentage;

	// The camera this sensor will be following during the game
	CCamera* m_followingCamera;
};

