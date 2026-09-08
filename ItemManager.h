#pragma once
#include "BoostItem.h"
#include "DownItem.h"


class ItemManager
{
private:
	Array<std::unique_ptr<Item>> items;

	std::shared_ptr<Speed> speed;

	Vec2 prePos;//1個前に生成したアイテムの座標

	const Texture BoostItemTexture{ U"Assets/yoshidaViper.png" };

	const Texture DownItemTexture{ U"Assets/yoshidaWine.png" };

public:

	ItemManager(std::shared_ptr<Speed> speed);

	void addBoostItem();

	void addDownItem();

	void deleteItem();

	void draw()const;

	void update();

};

