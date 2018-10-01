#ifndef CAMERA_H
#define CAMERA_H

// Local Include
#include "Utility.h"

class CCamera
{
public:
	CCamera();
	~CCamera();

	CCamera(glm::vec3 _Positition, glm::vec3 _Facing, glm::vec3 _Normal);
	void UpdateCamera();

	glm::mat4 GetView() const;
	void CalcViewMatrix();

	glm::mat4 GetProj() const;
	void SetProjectionMatrix();
	void SetProjectionMatrix(float _fov);

	glm::vec3 GetCameraPosition() const;
	void SetCameraPosition(glm::vec3 _Position);

	glm::vec3 GetCameraFacing() const;
	void SetCameraFacing(glm::vec3 _Facing);

	glm::vec3 GetCameraNormal() const;
	void SetCameraNormal(glm::vec3 _Normal);

	float GetCameraWidth() const;
	float GetCameraHeight() const;

private:
	glm::vec3 m_CameraPosition;
	glm::vec3 m_CameraFacing;
	glm::vec3 m_CameraNormal;

	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;
};

#endif // !CAMERA_H