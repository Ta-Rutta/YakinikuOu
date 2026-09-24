#include "GameScenen.h"
#include "stdafx.h"


// コンストラクタ（親クラス IScene の初期化を行う）
GameScenen::GameScenen(const InitData& init)
	: IScene{ init }
	, speed{ std::make_shared<Speed>() } // 1. 先に speed を生成
	, hp{ std::make_shared<Hp>() } // 1. 先に speed を生成
	, itemManager{ speed }               // 2. 生成した speed を渡して itemManager を初期化
	, tornadeManager{ speed }                    // 3. tornade の初期化
	, player{ Vec2{100,Scene::Height() / 2}, speed }
	, backGraund{ speed,hp }
{
	// アセットを使用する
	AudioAsset(U"BGM_GameScene").setVolume(0.02);
	AudioAsset(U"BGM_GameScene").play();
}

// 更新関数
void GameScenen::update()
{
	const double t = Scene::DeltaTime();

	addMilage(t);

	speed->update();

	player.update();

	itemManager.update(player);

	spawnController.SpawnController(itemManager, milage,speed);

	//hitCheckTornade();

	backGraund.update();

	//デバック用処理
	if (KeyA.down())
	{
		speed->speedUp();
	}
}

// 描画関数
void GameScenen::draw() const
{
	Scene::Rect().draw(Arg::top = ColorF{ 0.05, 0.35, 0.75 },Arg::bottom = ColorF{ 0.4, 0.75, 0.95 });

	backGraund.draw();

	player.draw();

	itemManager.draw();

}


void GameScenen::addMilage(double t)
{
	double dist = speed->checkSpeed() * t;

	milage.addMilage(dist);
}

//void GameScenen::hitCheckTornade()
//{
//	if (tornadeManager.collisionCheck(player) && speed->checkSpeed()<speed->get_player_game_over_speed())
//	{
//		getData().milage = milage.getMilage();
//		AudioAsset(U"BGM_GameScene").stop();
//		changeScene(U"Result");
//	}
//}
