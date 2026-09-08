#pragma once
#include "ItemManager.h"
#include "Milage.h"

class ItemSpawnController
{
private:
	double spawnTime = 1;
	double t = 0;
public:
	void SpawnController(ItemManager& manager, Milage& milage);
};

