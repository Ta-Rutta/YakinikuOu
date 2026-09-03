#include "stdafx.h"
#include "Player.h"

Player::Player(Vec2 Pos_,double Vel_)
	: Pos{Pos_}, //位置
	Vel{Vel_}, //速度
	PlayerRect{ RectF(Pos,30,10) }
{

}

void Player::update() {
	move();
	drawPlayer();
}

double Player::getVel() {
	return Vel; //速度を返す
}

bool Player::getCollision(const RectF& other) {
	return PlayerRect.intersects(other); //引数の物体に触れているかの判定を返す
}

void Player::drawPlayer() {
	PlayerRect = { Pos,30,10 };
	PlayerRect.draw(); //プレイヤーの描画
}



void Player::move() {
	if (KeyW.pressed() || KeyUp.pressed()) {
		Pos.y -= 100*Scene::DeltaTime();
	}
	if (KeyS.pressed() || KeyDown.pressed()) {
		Pos.y += 100 * Scene::DeltaTime();
	}
	//上下移動

	/*if (KeyD.pressed() || KeyRight.pressed()) {
		Pos.x += 1*Scene::DeltaTime();
	}
	if (KeyA.pressed() || KeyLeft.pressed()) {
		Pos.x -= 1 * Scene::DeltaTime();
	}*/
	// 左右移動
}
