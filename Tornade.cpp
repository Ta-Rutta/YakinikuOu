#include "stdafx.h"
#include "Tornade.h"

Tornade::Tornade(Vec2 pos, std::shared_ptr<Speed> speed)
	:pos(pos),speed(speed),hitBox(RectF{pos,100,800})
{

}

void Tornade::draw()const
{
	hitBox.draw();
}

RectF Tornade::getCollision()
{
	return hitBox;
}

void Tornade::update()
{
	pos.x -= speed->checkSpeed() * Scene::DeltaTime();
	hitBox.pos = pos;
}

Vec2 Tornade::getPos()
{
	return pos;
}
