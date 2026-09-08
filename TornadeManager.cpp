#include "stdafx.h"
#include "TornadeManager.h"

TornadeManager::TornadeManager(std::shared_ptr<Speed> speed)
	:speed(speed)
{

}


//加速アイテムを生成し、配列に追加
void TornadeManager::addTornade()
{
	Vec2 pos{ 1000,Random(30,800) };

	tornades.push_back(std::make_unique<Tornade>(pos, speed));
}

//画面外のアイテムを削除
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
	for (const auto& tornade : tornades)
	{
		tornade->update();
	}
}
