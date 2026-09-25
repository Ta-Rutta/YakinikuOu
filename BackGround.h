#pragma once
# include "Speed.h"
# include "Hp.h"

class BackGround
{
private:
	std::shared_ptr<const ReadOnlySpeed> speed;

	std::shared_ptr<const IHpReadOnly> hp;

	RectF small_mountainL;
	RectF small_mountainR;

	RectF big_mountainL;
	RectF big_mountainR;

	RectF UIBar{ Vec2{0,Scene::Height() - 200},Scene::Width(),Scene::Height() };

	RectF sun{ Vec2{Scene::Width() - 150,Scene::Height() - 1000},100,100 };

	const double textureWidth = Scene::Width();

public:
	BackGround(std::shared_ptr<const ReadOnlySpeed> speed, std::shared_ptr<const IHpReadOnly> hp);

	void update();

	void SmallMountainUpdate();

	void BigMountainUpdate();

	void draw()const;

	void drawHp()const;
};

