#include "stdafx.h"
#include "BoostItem.h"

BoostItem::BoostItem(Vec2 pos, Texture tex, std::shared_ptr<Speed> speed)
	: pos(pos), //描画位置
	tex(tex),  //テクスチャ
	speed(speed), //アイテムのスピード
	hitBox{ RectF(pos, 100, 100) } //当たり判定用 サイズは仮置きです
{

}

RectF BoostItem::getCollision() {
	return hitBox; //当たり判定を返す
}

void BoostItem::draw()const {
	hitBox(tex).draw(); //描画
}

void BoostItem::update() {
	pos.x -= speed->checkSpeed() * Scene::DeltaTime();
	hitBox.pos = pos;
}

Vec2 BoostItem::getPos()
{
	return pos;
}
