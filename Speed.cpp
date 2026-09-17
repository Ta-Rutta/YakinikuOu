#include "stdafx.h"
#include "Speed.h"

void Speed::update()
{
	
	t += Scene::DeltaTime();

	if (t > 1)
	{
		t = 0;
		speed -= 2;
	}

	if (speed < minSpeed)speed = minSpeed;
	//if (speed > maxSpeed)speed = maxSpeed;
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

double Speed::get_player_game_over_speed() {
	return player_game_over_speed;
}
