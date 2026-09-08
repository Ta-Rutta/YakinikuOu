#pragma once
class Player
{
private:
	Vec2 Pos; //位置
	double Vel; //速度
	RectF PlayerRect; //仮置きのプレイヤー
public:
	Player(Vec2 Pos_); //コンストラクタ

	void update();

	double getVel(); //速度を返す

	bool getCollision(const RectF& other); //当たり判定を返す

	void draw()const;

	void move(); //Playerを動かす処理
};

