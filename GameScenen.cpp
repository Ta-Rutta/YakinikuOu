#include "GameScenen.h"
#include "stdafx.h"


// コンストラクタ（親クラス IScene の初期化を行う）
GameScenen::GameScenen(const InitData& init)
	: IScene{ init }
	, speed{ std::make_shared<Speed>() } // 1. 先に speed を生成
	, itemManager{ speed }               // 2. 生成した speed を渡して itemManager を初期化
	, tornadeManager{speed}                    // 3. tornade の初期化
	, player{ Vec2{200,400}, speed}
{
	// アセットを使用する
	AudioAsset(U"BGM_GameScene").setVolume(0.2);
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

	tornadeManager.update();

	spawnController.SpawnController(itemManager, milage);

	hitCheckTornade();

}

// 描画関数
void GameScenen::draw() const
{
	Scene::SetBackground(Palette::Skyblue);

	player.draw();

	itemManager.draw();

	tornadeManager.draw();

}


void GameScenen::addMilage(double t)
{
	double dist = speed->checkSpeed() * t;

	milage.addMilage(dist);
}

void GameScenen::hitCheckTornade()
{
	if (tornadeManager.collisionCheck(player))
	{
		getData().milage = milage.getMilage();
		changeScene(U"Result");
	}
}
