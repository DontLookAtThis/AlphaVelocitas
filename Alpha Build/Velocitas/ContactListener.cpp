#include "ContactListener.h"
#include "Engine\RigidBody2D.h"


CContactListener::CContactListener()
{
}

CContactListener::~CContactListener()
{
}

void CContactListener::BeginContact(b2Contact* _contact)
{
	//Get 2 bodies colliding
	CRigiBody2D* bodyA = static_cast<CRigiBody2D*>(_contact->GetFixtureA()->GetBody()->GetUserData());
	CRigiBody2D* bodyB = static_cast<CRigiBody2D*>(_contact->GetFixtureB()->GetBody()->GetUserData());;

	bodyA->OnCollisionEnter(bodyB);
	bodyB->OnCollisionEnter(bodyA);
}

void CContactListener::EndContact(b2Contact * _contact)
{
	CRigiBody2D* bodyA = static_cast<CRigiBody2D*>(_contact->GetFixtureA()->GetBody()->GetUserData());
	CRigiBody2D* bodyB = static_cast<CRigiBody2D*>(_contact->GetFixtureB()->GetBody()->GetUserData());;

	bodyA->OnCollisionExit(bodyB);
	bodyB->OnCollisionExit(bodyA);
}

void CContactListener::PostSolve(b2Contact * _contact, const b2ContactImpulse * impulse)
{
}

void CContactListener::PreSolve(b2Contact * _contact, const b2Manifold * oldManifold)
{
}
