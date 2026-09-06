#pragma once
#include "Item.h"
class BoostItem:public Item
{
private:
	Vec2 pos;//描画座標
	Texture tex;//テクスチャ
	RectF hitBox;//当たり判定用の四角
	Speed speed;//速度

public:
	BoostItem(Vec2 pos, Texture tex)
		:pos(pos), tex(tex)
	{

	}

	RectF getCollision();//当たり判定返す

	void draw()const;//描画

	void update();//位置更新

};

