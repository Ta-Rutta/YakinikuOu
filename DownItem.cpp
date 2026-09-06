#include "stdafx.h"
#include "DownItem.h"

DownItem::DownItem(Vec2 pos, Texture tex, std::shared_ptr<Speed> speed)
	: pos(pos), //描画位置
	tex(tex),  //テクスチャ
	speed(speed) //アイテムのスピード
	hitBox{ RectF(pos, 30, 30) } //当たり判定用 サイズは仮置きです
{

}

RectF DownItem::getCollision() {
	return hitBox; //当たり判定を返す
}

void DownItem::draw()const {
	hitBox(tex).draw(); //描画
}

void DownItem::update() {
	pos.x -= speed->checkSpeed() * Scene::DeltaTime();
	hitBox = (pos, 30, 30) //位置の更新
}
