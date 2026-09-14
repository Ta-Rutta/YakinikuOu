#include "stdafx.h"
#include "Tornade.h"

Tornade::Tornade(Vec2 pos, std::shared_ptr<Speed> speed,Texture tex)
	:pos(pos),
	speed(speed),
	hitBox(RectF{pos,400,800}),
	tex(tex)
{

}

void Tornade::draw()const
{
	hitBox(tex).draw();
}

RectF Tornade::getCollision()
{
	return hitBox;
}

void Tornade::update()
{
	pos.x -= speed->checkSpeed() * Scene::DeltaTime()*2;
	hitBox.pos = pos;
}

Vec2 Tornade::getPos()
{
	return pos;
}
