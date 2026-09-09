#include "stdafx.h"
#include "Player.h"

Player::Player(Vec2 Pos_, std::shared_ptr<Speed> speed)
	: Pos{ Pos_ }, //位置
	Vel{ 250 }, //速度
	PlayerRect{ RectF(Pos,30,10)},
	speed {speed}
{

}

void Player::update() {
	PlayerRect = { Pos,30,10 };
	move();
}

double Player::getVel() {
	return Vel; //速度を返す
}

bool Player::getCollision(const RectF& other) {
	return PlayerRect.intersects(other); //引数の物体に触れているかの判定を返す
}

void Player::draw()const {	
	PlayerRect.draw(); //プレイヤーの描画
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
