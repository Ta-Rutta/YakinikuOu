#pragma once
# include "Speed.h"

class Item
{
public:
	virtual RectF getCollision() = 0;

	virtual void draw()const = 0;

	virtual void update() = 0;

	virtual Vec2 getPos() = 0;

	virtual void RunEffect() = 0;
};

