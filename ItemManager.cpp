#include "stdafx.h"
#include "ItemManager.h"

ItemManager::ItemManager(std::shared_ptr<Speed> speed)
	:speed(speed)
{

}


//加速アイテムを生成し、配列に追加
void ItemManager::addBoostItem()
{
	Vec2 pos{ 1000,Random(0,500) };

	items.push_back(std::make_unique<BoostItem>(pos, BoostItemTexture, speed));
}


//減速アイテムを生成し、配列に追加
void ItemManager::addDownItem()
{
	Vec2 pos{ 1000,Random(0,500) };

	items.push_back(std::make_unique<DownItem>(pos, DownItemTexture, speed));
}


//アイテムを削除するのはこのメソッド
void ItemManager::deleteItem(Player& player)
{
	items.remove_if([&player](const std::unique_ptr<Item>& item)
		{
			if (item->getPos().x < -100) // ※仕様に合わせて変更
			{
				return true;
			}

			if (player.getCollision(item->getCollision()))
			{
				item->RunEffect();
				return true;
			}
			return false;
		}
	);
}


//アイテムを描画
void ItemManager::draw()const
{
	for (const auto& item : items)
	{
		item->draw();
	}
}



void ItemManager::update(Player& player)
{

	for (const auto& item : items)
	{
		item->update();
	}
	deleteItem(player);
}


//bool ItemManager::checkCollsion(Player& player)
//{
//	for (const auto& item : items)
//	{
//		if (player.getCollision(item->getCollision()))
//		{
//
//		}
//	}
//	
//}
