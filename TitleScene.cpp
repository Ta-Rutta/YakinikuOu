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

	// ボタンが左クリックされたらアプリを終了
	if (exit_button.leftClicked()) System::Exit();

	if (!button_font)
	{
		// ファイルパスが間違っている場合、ここに入る
		Print << U"フォントの読み込みに失敗しました。";
	}
}

// 描画関数
void TitleScene::draw() const
{
	Scene::SetBackground(Palette::Skyblue);

	start_button.draw(Palette::Black);
	exit_button.draw(Palette::Blue);

	button_font(U"Start").drawAt(60, Vec2{ 400, 250 });
	button_font(U"Exit").drawAt(60, Vec2{ 400, 400 });

	title_font(U"飛べ! イーグルくん").drawAt(80, Vec2{ 400, 100 });

	
}
