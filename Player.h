#pragma once
class Player
{
public:
	Vec2 Pos; //位置
	double Vel; //速度
	RectF PlayerRect; //仮置きのプレイヤー

	Player(Vec2 Pos_,double Vel_); //コンストラクタ

	void update();
	double getVel(); //速度を返す
	bool getCollision(const RectF &other); //当たり判定を返す
	void drawPlayer();
	void move(); //Playerを動かす処理
};

