#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(std::shared_ptr<Speed> speed)
	:speed(speed),
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
	Print << speed->checkSpeed();
	UIBar.draw(Palette::Lightgreen);
}
