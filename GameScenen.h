#pragma once
#include "ItemManager.h"
# include "Speed.h"
# include "Tornade.h"
#include "Milage.h"
#include "Player.h"

class GameScenen
{
private:
	ItemManager itemManager; //アイテム管理クラス
	Speed speed; //全体で統一させる速さ
	Milage milage; //飛行距離
	Tornade tornade;
	Player player;

public:
	//プレイヤーとアイテムの当たり判定のみをここで判断
	bool hitCheckItem();

	//プレイヤーと竜巻の当たり判定のみをここで判断
	bool hitCheckTornade();

	void commitSpeed();

	void update();

	void draw()const;

};

