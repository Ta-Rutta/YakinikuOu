#pragma once
class Speed
{
private:
	double speed=100;//速さ

	double accelerate=10;//加速量

	double deceleration=-10;//減速量

public:
	void speedUp();

	void speedDown();

	double checkSpeed();
};

