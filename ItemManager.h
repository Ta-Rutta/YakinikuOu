#pragma once
#include "BoostItem.h"
#include "DownItem.h"

class ItemManager
{
private:
	Array<Item*> items;

	RectF BoostItemBox;

	RectF DownItemBox;

	std::shared_ptr<Speed> speed;

	Vec2 prePos;//1個前に生成したアイテムの座標

	const Texture BoostItemTexture{ U"Assets/yoshidaViper.png" };

	const Texture DownItemTexture{ U"Assets/yoshidaWine.png" };

public:

	//
	void addBoostItem();

	void addDownItem();

	void deleteItem();

	void draw()const;

	void update();

};

