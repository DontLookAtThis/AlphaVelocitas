
// Derive Include
#include "Engine/Scene.h"


class CSpaceShip;

class CTestScene : public CScene
{
public:

	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;


	void CreateBlocks();
	void CreatePigs();
	void CreateBirdies();

	bool bSlingLoaded;
	int CurrentBird;
	std::vector<CSpaceShip*> m_vBirds;
private:


};