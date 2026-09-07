#include "stdafx.h"
#include "ItemManager.h"


void ItemManager::addBoostItem()
{
	Vec2 pos{ 1000,Random(30,800) };
	BoostItem* addItem = new BoostItem(pos, BoostItemTexture, speed);
	items.push_back(addItem);
}
