#pragma once
class Tornade
{
private:
	Vec2 pos;
	Speed speed;
	Texture tex;
	RectF hitBox;

public:
	Tornade();

	void draw()const;//描画

	RectF getCollision();//当たり判定返す

	void update();//位置更新
};

