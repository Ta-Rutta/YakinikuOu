#include "stdafx.h"
#include "BoostItem.h"

BoostItem::BoostItem(Vec2 pos, Texture tex, std::shared_ptr<Speed> speed)
	: pos(pos), //描画位置
	tex(tex),  //テクスチャ
	speed(speed) //アイテムのスピード
	hitBox{ RectF(pos, 30, 30) } //当たり判定用 サイズは仮置きです
{

}

RectF BoostItem::getCollision() {
	return hitBox; //当たり判定を返す
}

void BoostItem::draw()const {
	tex.draw(); //描画
}

void BoostItem::update() {
	draw();
	hitBox = (pos, 30, 30) //位置の更新
}
