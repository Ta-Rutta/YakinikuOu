#pragma once
#include "ItemManager.h"
#include "Milage.h"

class ItemSpawnController
{
private:
	double spawnTime = 1.5;

	double t = 0;

	Array<int> lane{ 200,400,600,800 };

	std::shared_ptr<Speed> speed;

public:
	void SpawnController(ItemManager& manager, Milage& milage,double speed);

	void SpawnItems(int LaneNumber);
};

