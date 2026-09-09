#pragma once
#include "Tornade.h"
#include "Player.h"

class TornadeManager
{
private:
	Array<std::unique_ptr<Tornade>> tornades;

	std::shared_ptr<Speed> speed;

	const Texture TornadeTexture{ U"Assets/yoshidaViper.png" };

	double t = 0;
public:

	TornadeManager(std::shared_ptr<Speed> speed);

	void addTornade();

	void deleteTornade();

	bool collisionCheck(Player& player);

	void draw()const;

	void update();

};

