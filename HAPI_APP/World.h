#pragma once

#include <HAPISprites_Lib.h>
#include "HAPI_SPRITES/Shapes/Vector.h"
#include <unordered_map>
#include "Entity.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "Map.h"
#include "Camera.h"
#include "KeyCollectable.h"

using namespace HAPISPACE;

class World
{
public:
	World();
	~World();

	bool Initialise();
	bool Play();

private:

	HAPISPACE::Vector<int> screenDimensions = HAPISPACE::Vector<int>(1280, 832);
	std::unordered_map <std::string, Entity*> entityMap;
	Map gameMap;
	Camera gameCamera {832, 1280};
	bool levelComplete = false;

	const DWORD worldTickTime{ 10 };
	DWORD timeSinceLastWorldTick{ 0 };


	bool LoadSprites();
	bool LoadEntities();
	bool LoadWorld();

	void Update();
	void Render();

	void CheckCollision();
	void UpdateCamera();
};

