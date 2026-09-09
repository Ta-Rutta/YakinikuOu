#pragma once
# include "Common.h"
# include "Speed.h"
#include "ItemManager.h"
# include "TornadeManager.h"
#include "Milage.h"
#include "Player.h"
#include "CollisionSystem.h"
#include "ItemSpawnController.h"

class GameScenen : public App::Scene
{
private:

	std::shared_ptr<Speed> speed; //全体で統一させる速さ

	ItemManager itemManager; //アイテム管理クラス

	Milage milage; //飛行距離

	TornadeManager tornadeManager;

	Player player;

	ItemSpawnController spawnController;

public:

    //コンストラクタ
	GameScenen(const InitData& init);

	//プレイヤーと竜巻の当たり判定のみをここで判断
	void hitCheckTornade();

	void update() override;

	void draw()const override;

	//飛距離を計算してMailageクラスに渡す
	void addMilage(double t);

};
