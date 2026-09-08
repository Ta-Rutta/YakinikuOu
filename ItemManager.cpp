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


//画面外のアイテムを削除
void ItemManager::deleteItem()
{
	items.remove_if([](const std::unique_ptr<Item>& item)
		{
			if (item->getPos().x < 0) // ※仕様に合わせて変更
			{ 
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



void ItemManager::update()
{

	for (const auto& item : items)
	{
		item->update();
	}
	deleteItem();
}
