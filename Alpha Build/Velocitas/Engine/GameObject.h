#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Global Include
#include "Utility.h"
#include "Scene.h"
// Forward Declare
class CGameObject;
class CComponent;

// Declare a Transform struct

class CGameObject
{
public:
	CGameObject();
	~CGameObject();

	// Properties
	std::string m_tag;
	std::string m_name;
	Transform m_transform;
	int m_iHealth = 100;
	CScene* m_Scene;
protected:
	
	bool m_ShouldDestroyed;
	bool m_isActive;
	bool m_isAlive;
	std::vector<CComponent*> m_components;

public:
	/**
	* Initialize the object
	* Call right after the scene initialize
	*/
	void SetWorld(CScene* world);
	virtual void BeginPlay();
	/*
	 * Call every frame
	 */
	virtual void Update(float _tick);
	/**
	* Try get the component of the gameobject
	*/
	template<typename T>
	T* GetComponent() const;
	/*
	 *Check if the object should be destroyed on thie frame
	 */
	bool ShouldDestroyed() const;
	/*
	 *Destroy current gameobject and set it to inactive 
	 *of the garbage cleaning next frame
	 */
	void DestroyObject();
    /*
	 *Check if the obejct is active which determent it should update or not
	 */
	bool IsActive() const;
	/*
	 *Set active state for a object
	 */
	void SetActive(bool);
	void TakeDamage(int _damage);

protected:
	
	/**
	 * Creates a component and push to the vector
	 */
	template<typename T>
	T* CreateComponent();

};

template<typename T>
T* CGameObject::CreateComponent()
{
	CComponent* newComponent = new T();
	newComponent->SetOwner(this);

	T* resultComponent = dynamic_cast<T*>(newComponent);

	if (resultComponent != nullptr)
	{
		m_components.push_back(resultComponent);
	}

	return resultComponent;
}

template<typename T>
T* CGameObject::GetComponent() const
{

	for (CComponent* iter : m_components)
	{
		T* component = dynamic_cast<T*>(iter);
		if (component != nullptr)
		{
			return component;
		}
	}

	return nullptr;
}

#endif // !GAMEOBJECT_H