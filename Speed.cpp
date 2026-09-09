#include "stdafx.h"
#include "Speed.h"

void Speed::update()
{
	t += Scene::DeltaTime();

	if (t > 0.1)
	{
		t = 0;
		speed -= 0.1;
	}

	if (speed < minSpeed)speed = minSpeed;
	if (speed > maxSpeed)speed = maxSpeed;
}

void Speed::speedUp(){
	speed += accelerate;
}

void Speed::speedDown(){
	speed += deceleration;
}

double Speed::checkSpeed(){
	return speed;
}
