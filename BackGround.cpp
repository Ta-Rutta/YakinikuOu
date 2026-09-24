#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(std::shared_ptr<const ReadOnlySpeed> speed, std::shared_ptr<const IHpReadOnly> hp)
	:speed(speed),
	hp(hp),
	small_mountainL(RectF{ Vec2{0,Scene::Height()-500},1920,1200 }),
	small_mountainR(RectF{ Vec2{Scene::Width(),Scene::Height() - 500},1920,1200 }),
	big_mountainL(RectF{ Vec2{0,Scene::Height() - 900},1920,1200 }),
	big_mountainR(RectF{ Vec2{Scene::Width()-10,Scene::Height() - 900},1920,1200 })
{

}

void BackGround::update()
{
	SmallMountainUpdate();
	BigMountainUpdate();
}

void BackGround::SmallMountainUpdate()
{
	small_mountainL.x -= speed->checkSpeed() * Scene::DeltaTime() * 1.2;
	small_mountainR.x -= speed->checkSpeed() * Scene::DeltaTime() * 1.2;
	if (small_mountainL.x <= -Scene::Width()+10)small_mountainL.x = Scene::Width();
	if(small_mountainR.x <= -Scene::Width()+10)small_mountainR.x = Scene::Width();
}

void BackGround::BigMountainUpdate()
{
	big_mountainL.x -= speed->checkSpeed() * Scene::DeltaTime();
	big_mountainR.x -= speed->checkSpeed() * Scene::DeltaTime();
	if (big_mountainL.x <= -Scene::Width()+10)big_mountainL.x = Scene::Width();
	if (big_mountainR.x <= -Scene::Width()+10)big_mountainR.x = Scene::Width();
}

void BackGround::draw()const
{
	big_mountainL(TextureAsset(U"big_mountain")).draw();
	big_mountainR(TextureAsset(U"big_mountain")).draw();
	small_mountainL(TextureAsset(U"small_mountain")).draw();
	small_mountainR(TextureAsset(U"small_mountain")).draw();
	sun(TextureAsset(U"sun")).draw();
	UIBar.draw(Palette::Lightgreen);
	drawHp();
}

void BackGround::drawHp()const
{
	// HPの数値（個数）を取得
	const int currentHp = hp->checkHp();

	// ハートのサイズと描画開始位置
	const double heartSize = 30.0; // ハートの大きさ（半径）
	const Vec2 startPos{ 50, 50 }; // 1つ目のハートの中心座標
	const double spacing = 70.0;    // ハート同士の間隔

	// HPの数だけハートを描画
	for (int i = 0; i < currentHp; ++i)
	{
		// 横に並べる座標を計算
		const Vec2 pos = startPos + Vec2{ i * spacing, 0 };

		// 赤色のハートを描画
		Shape2D::Heart(heartSize, pos).draw(Palette::Crimson);
	}
}
