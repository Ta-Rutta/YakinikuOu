#pragma once
#include "Tornade.h"

class TornadeManager
{
private:
	Array<std::unique_ptr<Tornade>> tornades;

	RectF DownItemBox;

	std::shared_ptr<Speed> speed;

	const Texture TornadeTexture{ U"Assets/yoshidaViper.png" };

public:

	TornadeManager(std::shared_ptr<Speed> speed);

	void addTornade();

	void deleteTornade();

	void draw()const;

	void update();

};

