#include "stdafx.h"
#include "Player.h"

Player::Player(Vec2 Pos_, std::shared_ptr<const ReadOnlySpeed> speed)
	: Pos{ Pos_ }, //位置
	Vel{ 500 }, //速度
	PlayerRect{ RectF(Pos,150,150)},
	speed {speed}
{

}

void Player::update() {
	move();
	t += Scene::DeltaTime();
	if (t > 1)t = 0;
	
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
		PlayerRect.y -= Vel * Scene::DeltaTime()*3;
	}
	if (KeyS.pressed() || KeyDown.pressed()) {
		PlayerRect.y += Vel * Scene::DeltaTime()*3;
	}

	if (PlayerRect.y < 200)PlayerRect.y = 200;
	if (PlayerRect.y > Scene::Height() - 200)PlayerRect.y = Scene::Height() - 200;
	

}

void Player::try_drawing_indicator(double player_speed) const {
	
		if (t < 0.5)
		{
			PlayerRect(eagle).draw(ColorF(1, 0, 0, 0.5));
			
		}
	
}
