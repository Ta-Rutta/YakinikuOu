#include "stdafx.h"
#include "Player.h"

Player::Player(Vec2 Pos_)
	: Pos{ Pos_ }, //位置
	Vel{ 100 }, //速度
	PlayerRect{ RectF(Pos,30,10) }
{

}

void Player::update() {
	move();
	drawPlayer();
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
		Pos.y -= Vel * Scene::DeltaTime();
	}
	if (KeyS.pressed() || KeyDown.pressed()) {
		Pos.y += Vel * Scene::DeltaTime();
	}
	//上下移動

	/*if (KeyD.pressed() || KeyRight.pressed()) {
		Pos.x += Vel*Scene::DeltaTime();
	}
	if (KeyA.pressed() || KeyLeft.pressed()) {
		Pos.x -= Vel* Scene::DeltaTime();
	}*/
	// 左右移動
}
