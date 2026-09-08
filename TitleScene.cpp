#include "stdafx.h"
#include "TitleScene.h"
// タイトルシーン


// コンストラクタ（親クラス IScene の初期化を行う）
TitleScene::TitleScene(const InitData& init)
	: IScene{ init }
{

}

// 更新関数
void TitleScene::update()
{
	// ボタンが左クリックされたらシーン遷移
	if (start_button.leftClicked()) changeScene(U"Game");

	if (exit_button.leftClicked()) System::Exit();
}

// 描画関数
void TitleScene::draw() const
{
	Scene::SetBackground(Palette::Skyblue);

	start_button.draw(Palette::Black);
	exit_button.draw(Palette::Blue);

	Print << U"Title";
}
