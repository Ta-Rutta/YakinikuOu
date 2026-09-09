#pragma once
#include "BoostItem.h"
#include "DownItem.h"
#include "Player.h"


class ItemManager
{
private:
	Array<std::unique_ptr<Item>> items;

	std::shared_ptr<Speed> speed;

	Vec2 prePos;//1個前に生成したアイテムの座標

	const Texture BoostItemTexture{ U"Assets/image/accelerate.png" };

	const Texture DownItemTexture{ U"Assets/image/slow-down.png" };

public:

	ItemManager(std::shared_ptr<Speed> speed);

	void addBoostItem();

	void addDownItem();

	//アイテムが削除される条件を追加
	void deleteItem(Player& player);

	void draw()const;

	void update(Player& player);

    //プレイヤーとの衝突確認
	/*bool checkCollsion(Player& player);*/
};

