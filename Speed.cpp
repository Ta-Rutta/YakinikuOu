#include "stdafx.h"
#include "Speed.h"

void Speed::speedUp(){
	speed += accelerate;
}

void Speed::speedDown(){
	speed += deceleration;
}

double Speed::checkSpeed(){
	return speed;
}
