#pragma once
# include "Speed.h"

class BackGround
{
private:
	std::shared_ptr<Speed> speed;
	RectF small_mountainL;
	RectF small_mountainR;

	RectF big_mountainL;
	RectF big_mountainR;

	RectF UIBar{ Vec2{0,Scene::Height() - 200},Scene::Width(),Scene::Height() };

	RectF sun{ Vec2{Scene::Width() - 150,Scene::Height() - 800},100,100 };

	const double textureWidth = Scene::Width();

public:
	BackGround(std::shared_ptr<Speed> speed);

	void update();

	void SmallMountainUpdate();

	void BigMountainUpdate();

	void draw()const;
};

