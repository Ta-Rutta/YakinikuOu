#include "stdafx.h"
#include "ItemSpawnController.h"

void ItemSpawnController::SpawnController(ItemManager& manager, Milage& milage)
{
	
	t += Scene::DeltaTime();

	if (t>spawnTime)
	{
		t = 0;
		manager.addBoostItem();
		manager.addDownItem();
	}
}
