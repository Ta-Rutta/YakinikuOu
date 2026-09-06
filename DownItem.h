#pragma once
#include "Item.h"

class DownItem
{
private:
	Vec2 pos;//描画位置
	Texture tex;//テクスチャ
	RectF hitBox;//当たり判定用
	Speed speed;//速さ

public:
	DownItem(Vec2 pos, Texture tex)
		:pos(pos),tex(tex)
	{

	}

	RectF getCollision();//当たり判定を返す

	void draw()const;//描画関数

	void update();//位置更新
};

