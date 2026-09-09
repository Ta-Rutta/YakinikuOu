#include "stdafx.h"
#include "ResultScene.h"

// コンストラクタ（親クラス IScene の初期化を行う）
ResultScene::ResultScene(const InitData& init)
	: IScene{ init },
	//飛んだ距離
	milage(getData().milage),
	//名前
	name(getData().name),
	//スコア表示用の変数
	score(50)
{

}

// 更新関数
void ResultScene::update()
{
	RetryButton();
	TitleButton();
}

// 描画関数
void ResultScene::draw() const
{
	Scene::SetBackground(Palette::White);

	Print << U"Result";

	score(U"{}m"_fmt(milage)).drawAt(400, 200);

	
}

void ResultScene::RetryButton()
{
	retry_button.draw(Palette::Black);
	if (retry_button.leftClicked()) {
		changeScene(U"Game", 1s);
	}

}

void ResultScene::TitleButton()
{
	title_button.draw(Palette::Black);
	if (title_button.leftClicked()) {
		changeScene(U"Title", 1s);
	}

}
