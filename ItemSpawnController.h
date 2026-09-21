#pragma once
#include "ItemManager.h"
#include "Milage.h"

class ItemSpawnController
{
private:
	double spawnTime;

	double t = 0;

	Array<int> lane{ 200,400,600,800 };

	std::shared_ptr<const ReadOnlySpeed> speed;

public:
	ItemSpawnController();

	void SpawnController(ItemManager& manager, Milage& milage, std::shared_ptr<const ReadOnlySpeed> speed);

	
};

