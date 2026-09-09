#pragma once
class Speed
{
private:
	double speed=100;//速さ

	double accelerate=100;//加速量

	double deceleration=-10;//減速量

	const double minSpeed = 80;//速度の最小値

	const double maxSpeed = 1000;//速度の最大値

	double t = 0;//時間計測

	const double player_game_over_speed = 200;

public:
	void update();

	void speedUp();

	void speedDown();

	double checkSpeed();

	double get_player_game_over_speed();
};

