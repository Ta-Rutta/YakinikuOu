#include "stdafx.h"
#include "ItemSpawnController.h"

void ItemSpawnController::SpawnController(ItemManager& manager, Milage& milage,double speed)
{
	
	t += Scene::DeltaTime();

	spawnTime = 1.2-(((speed/500)/5.0));

	if (t>spawnTime)
	{
		int ItemAmount = Random(0, 5);
		t = 0;
		std::random_device rd; // 非決定的な乱数生成器
		std::default_random_engine engine(rd()); // 決定的な乱数生成器
		std::shuffle(lane.begin(), lane.end(), engine);

		if (ItemAmount == 0)
		{
			manager.addBoostItem(lane[0]);
			manager.addBoostItem(lane[1]);
			manager.addBoostItem(lane[2]);
			manager.addBoostItem(lane[3]);
		}
	    else if (ItemAmount == 1)
		{
			manager.addBoostItem(lane[0]);
			manager.addDownItem(lane[1]);
			manager.addDownItem(lane[2]);
		}
		else if (ItemAmount == 4 || ItemAmount == 2)
		{
			manager.addBoostItem(lane[0]);
			manager.addDownItem(lane[1]);
			manager.addDownItem(lane[2]);
			manager.addDownItem(lane[3]);
		}
		else if (ItemAmount == 5 || ItemAmount == 3)
		{
			manager.addDownItem(lane[1]);
			manager.addDownItem(lane[2]);
			manager.addDownItem(lane[3]);
		}

		
	}
}
