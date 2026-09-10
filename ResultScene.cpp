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
	score(50),
	//Retry用ボタンの文字
	retry(15),
	//Titleに戻る用ボタンの文字
	title(13)
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
	Scene::SetBackground(Palette::Skyblue);

	Print << U"Result";

	score(U"{}m"_fmt(milage)).drawAt(400, 200);

	retry_button.draw(Palette::Black);
	retry(U"リトライ").drawAt(750, 512.5);

	title_button.draw(Palette::Black);
	title(U"タイトルに戻る").drawAt(750, 562.5);
}

void ResultScene::RetryButton()
{
	if (retry_button.leftClicked()) {
		changeScene(U"Game", 0.5s);
		AudioAsset(U"SE_ButtonClicked").playOneShot();
	}
}

void ResultScene::TitleButton()
{
	if (title_button.leftClicked()) {
		changeScene(U"Title", 0.5s);
		AudioAsset(U"SE_ButtonClicked").playOneShot();
	}	
}
