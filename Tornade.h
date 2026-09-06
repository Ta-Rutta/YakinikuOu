#pragma once
# include "Speed.h"
class Tornade
{
private:
	Vec2 pos;//位置

	std::shared_ptr<Speed> speed;//スピード

	Texture tex;//テクスチャ

	RectF hitBox;//当たり判定

public:
	Tornade(Vec2 pos, std::shared_ptr<Speed> speed);

	void draw()const;//描画

	RectF getCollision();//当たり判定返す

	void update();//位置更新
};

