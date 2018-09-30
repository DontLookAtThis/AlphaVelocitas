// This Include
#include "GameObject.h"

// Local Include
#include "Component.h"
#include "RigidBody2D.h"
#include "SpriteRender.h"
#include "Scene.h"


/* Legacy Render Function*/
// void CGameObject::RenderObject(CCamera* _camera)
// {
// 	glUseProgram(m_ProgramID);
// 
// 	glm::mat4 translate = glm::translate(glm::mat4(), m_Position);
// 	glm::mat4 scale = glm::scale(glm::mat4(), m_Scale);
// 	glm::mat4 rotation = glm::mat4();
// 	rotation = glm::rotate(rotation, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
// 	rotation = glm::rotate(rotation, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
// 	rotation = glm::rotate(rotation, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
// 	glm::mat4 model = translate * rotation * scale;
// 	glm::mat4 mvp = _camera->GetProjectionMatrix() *  _camera->GetViewMatrix() * model;
// 	GLint mvpLoc = glGetUniformLocation(m_ProgramID, "MVP");
// 	glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));
// 
// 	GLint modelLoc = glGetUniformLocation(m_ProgramID, "model");
// 	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
// 
// 	glm::mat3 normalMat = glm::mat3(transpose(inverse(model)));
// 	GLuint normalMatLoc = glGetUniformLocation(m_ProgramID, "normalMat");
// 	glUniformMatrix3fv(normalMatLoc, 1, GL_FALSE, glm::value_ptr(normalMat));
// 
// 	GLuint camPosLoc = glGetUniformLocation(m_ProgramID, "camPos");
// 	glUniform3fv(camPosLoc, 1, glm::value_ptr(_camera->GetCameraPosition()));
// 
// 	if (m_IsModel)
// 	{
// 		glEnable(GL_DEPTH_TEST);
// 		glEnable(GL_CULL_FACE);
// 		glCullFace(GL_BACK);
// 		glFrontFace(GL_CCW);
// 
// 		// Render the model
// 		m_ObjModel->Render(_camera, this->m_ProgramID);
// 	}
// 	else
// 	{
// 		glActiveTexture(GL_TEXTURE0);
// 		glBindTexture(GL_TEXTURE_2D, m_TextureID);
// 		glUniform1i(glGetUniformLocation(m_ProgramID, "tex"), 0);
// 
// 		// Render the mesh after everything is binded
// 		m_ObjMesh->RenderMesh();
// 	}
// 
// 	// Unbind the program after finishing 
// 	glUseProgram(0);
// }

CGameObject::CGameObject()
{
	m_ShouldDestroyed = false;
	m_isActive = true;
	m_iHealth = 100;
	m_isAlive = true;
}

CGameObject::~CGameObject()
{

}

void CGameObject::SetWorld(CScene * world)
{
	m_Scene = world;
}

void CGameObject::BeginPlay()
{
	for (auto iter : m_components)
	{
		iter->BeginPlay();
	}
}

void CGameObject::Update(float _tick) 
{
	for (auto iter : m_components)
	{
		iter->Update(_tick);
	}
	if (m_iHealth <= 0 && m_isAlive == true)
	{
		m_isAlive = false;
		for (auto it: m_components)
		{
			if (dynamic_cast<CSpriteRender*>(it))
			{

			}
			else if (CRigiBody2D* body = dynamic_cast<CRigiBody2D*>(it))
			{
				body->GetBody()->SetTransform(b2Vec2(0.0f , -1000.0f), 0.0f);
				if (m_tag == "Pig" && m_Scene != nullptr)
				{
					m_Scene->m_PigCount--;
				}
			}
		}
		//std::cout << "dead" << std::endl;
	}
}

void CGameObject::DestroyObject()
{
	this->m_ShouldDestroyed = true;
}

bool CGameObject::IsActive() const
{
	return m_isActive;
}

void CGameObject::SetActive(bool _b)
{
	m_isActive = _b;

	for (auto component : m_components)
	{
		component->SetActive(_b);
	}
}

void CGameObject::TakeDamage(int _damage)
{
	m_iHealth -= _damage;
}

void CGameObject::OnCollisionEnter(CGameObject * CollidedObject)
{
}

void CGameObject::OnColliisionExit(CGameObject * CollidedObject)
{
}

bool CGameObject::ShouldDestroyed() const
{
	return m_ShouldDestroyed;
}