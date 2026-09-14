#include "stdafx.h"
#include "DownItem.h"

DownItem::DownItem(Vec2 pos, Texture tex, std::shared_ptr<Speed> speed)
	: pos(pos), //描画位置
	tex(tex),  //テクスチャ
	speed(speed), //アイテムのスピード
	hitBox{ RectF(pos, 100, 100) } //当たり判定用 サイズは仮置きです
{

}

RectF DownItem::getCollision() {
	return hitBox; //当たり判定を返す
}

void DownItem::draw()const {
	hitBox(tex).draw(); //描画
}

void DownItem::update() {
	pos.x -= speed->checkSpeed() * Scene::DeltaTime()*2;
	hitBox.pos = pos;
}

Vec2 DownItem::getPos()
{
	return pos;
}


void DownItem::RunEffect()
{
	AudioAsset(U"SE_SpeedDown").playOneShot();
	speed->speedDown();
}
