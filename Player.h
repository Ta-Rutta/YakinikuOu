#pragma once
#include "Speed.h"

class Player
{
private:
	Vec2 Pos; //位置
	double Vel; //速度
	RectF PlayerRect; //仮置きのプレイヤー
	RectF indicatorRect; //仮置きのアレ
	std::shared_ptr<Speed> speed;
	const Texture eagle{ U"Assets/image/eagle.png"};
public:
	Player(Vec2 Pos_, std::shared_ptr<Speed> speed);//コンストラクタ

	void update();

	double getVel(); //速度を返す

	bool getCollision(const RectF& other); //当たり判定を返す

	void draw()const;

	void move(); //Playerを動かす処理

	void try_drawing_indicator(double speed) const;
};

