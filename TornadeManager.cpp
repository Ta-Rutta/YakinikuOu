#include "stdafx.h"
#include "TornadeManager.h"

TornadeManager::TornadeManager(std::shared_ptr<Speed> speed)
	:speed(speed)
{

}


//竜巻とプレイヤーの当たり判定
bool TornadeManager::collisionCheck(Player& player)
{
	for (const auto& tornade : tornades)
	{
		if (player.getCollision(tornade->getCollision()))return true;
	}
	return false;
}

//竜巻を生成し、配列に追加
void TornadeManager::addTornade()
{
	Vec2 pos{ 1000,0 };

	tornades.push_back(std::make_unique<Tornade>(pos, speed));
}

//画面外の竜巻を削除
void TornadeManager::deleteTornade()
{
	tornades.remove_if([](const std::unique_ptr<Tornade>& tornade)
		{
			if (tornade->getPos().x < 0) // ※仕様に合わせて変更
			{
				return true;
			}
			return false;
		}
	);
}


//アイテムを描画
void TornadeManager::draw()const
{
	for (const auto& tornade : tornades)
	{
		tornade->draw();
	}
}


void TornadeManager::update()
{

	t += Scene::DeltaTime();

	if (t > 5)
	{
		t = 0;
		addTornade();
	}

	for (const auto& tornade : tornades)
	{
		tornade->update();
	}

	deleteTornade();
}
