#pragma once
#include "Item.h"

class DownItem
{
private:
	Vec2 pos;//描画位置
	Texture tex;//テクスチャ
	RectF hitBox;//当たり判定用
	std::shared_ptr<Speed> speed; //アイテムのスピード


public:
	DownItem(Vec2 pos, Texture tex, std::shared_ptr<Speed> speed);

	RectF getCollision();//当たり判定を返す

	void draw()const;//描画関数

	void update();//位置更新
};

