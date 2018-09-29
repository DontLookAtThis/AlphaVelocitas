
// Derive Include
#include "Engine/Scene.h"


class CSpaceShip;

class CTestScene : public CScene
{
public:

	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;


	void CreateBlocks(int iBlockID, std::string Name, std::string Tag, std::string SpriteName, Transform Transform, std::string ShapeOfBody, b2BodyType BodyType, bool bCanRotate = false, bool bHasFixture = true, int iFixtureType = 0, float fDensity = 1.0f, float fFriction = 0.3f);

	bool bSlingLoaded;
	int CurrentBird;
	std::vector<CSpaceShip*> m_vBirds;
private:


};