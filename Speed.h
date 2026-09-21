#pragma once
#include "ReadOnlySpeed.h"

class Speed:public ReadOnlySpeed
{
private:
	double speed=200;//速さ

	double accelerate=30;//加速量

	double deceleration=-30;//減速量

	const double minSpeed = 80;//速度の最小値

	const double maxSpeed = 300;//速度の最大値

	double t = 0;//時間計測

	const double player_game_over_speed = 150;//竜巻を通過できない速度
	
public:
	void update();

	void speedUp();

	void speedDown();

	double checkSpeed()const;

	
};

