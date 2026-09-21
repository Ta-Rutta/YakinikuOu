#include "stdafx.h"
#include "ItemSpawnController.h"

ItemSpawnController::ItemSpawnController()
	:spawnTime(1.2)
{

}

void ItemSpawnController::SpawnController(ItemManager& manager, Milage& milage, std::shared_ptr<const ReadOnlySpeed> speed)
{
	//スポーン時間に補正値を加算することで揺らぎを与える
	t += Scene::DeltaTime();

	spawnTime = 1.2-(((speed->checkSpeed()/500)/5.0));

	spawnTime *= Random(1.0, 1.3);

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
