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
	title(13),
	//選択の効果音
	select(U"Assets/sound-effect/button.mp3")
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

	
}

void ResultScene::RetryButton()
{
	retry_button.draw(Palette::Black);
	if (retry_button.leftClicked()) {
		select.play();
		changeScene(U"Game", 1s);
	}
	retry(U"リトライ").drawAt(750, 512.5);
}

void ResultScene::TitleButton()
{
	title_button.draw(Palette::Black);
	if (title_button.leftClicked()) {
		select.play();
		changeScene(U"Title", 1s);
	}
	title(U"タイトルに戻る").drawAt(750, 562.5);
}
