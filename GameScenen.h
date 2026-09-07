
/*
#pragma once
# include "Speed.h"
#include "ItemManager.h"
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
*/

//仮で書いておく
#pragma once

using App = SceneManager<String>;

// タイトルシーン
class GameScenen : public App::Scene
{
public:
	//スタートボタン
	const Rect start_button{ 400, 300, 200, 100 };

	//コンストラクタ
	GameScenen(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;
};

