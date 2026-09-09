#include "stdafx.h"
#include "Player.h"

Player::Player(Vec2 Pos_, std::shared_ptr<Speed> speed)
	: Pos{ Pos_ }, //位置
	Vel{ 250 }, //速度
	PlayerRect{ RectF(Pos,100,100)},
	indicatorRect{ RectF(Pos,100,100) },
	speed {speed}
{

}

void Player::update() {
	PlayerRect = { Pos,100,100 };
	indicatorRect = { Pos, 100, 100 };
	move();
}

double Player::getVel() {
	return Vel; //速度を返す
}

bool Player::getCollision(const RectF& other) {
	return PlayerRect.intersects(other); //引数の物体に触れているかの判定を返す
}

void Player::draw()const {	
	PlayerRect(eagle).draw(); //プレイヤーの描画
    try_drawing_indicator(speed->checkSpeed());
	
}



void Player::move() {
	if (KeyW.pressed() || KeyUp.pressed()) {
		Pos.y -= Vel * Scene::DeltaTime();
	}
	if (KeyS.pressed() || KeyDown.pressed()) {
		Pos.y += Vel * Scene::DeltaTime();
	}

	/*if (KeyD.pressed() || KeyRight.pressed()) {
		Pos.x += 1*Scene::DeltaTime();
	}
	if (KeyA.pressed() || KeyLeft.pressed()) {
		Pos.x -= 1 * Scene::DeltaTime();
	}*/
	// 左右移動
}

void Player::try_drawing_indicator(double player_speed) const {
	if (player_speed < speed->get_player_game_over_speed()) {
		indicatorRect.draw(Palette::Orange);
	}
}
