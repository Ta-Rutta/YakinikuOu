#pragma once
#include "BoostItem.h"
#include "DownItem.h"

class ItemManager
{
private:
	Array<Item> items;

	RectF BoostItemBox{};

	RectF DownItemBox;
public:

	//
	void addBoostItem();

	void addDownItem();

	void deleteItem();

	void draw()const;

	void update();

};

