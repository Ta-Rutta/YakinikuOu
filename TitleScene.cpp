#include "stdafx.h"
#include "TitleScene.h"
// タイトルシーン


// コンストラクタ（親クラス IScene の初期化を行う）
TitleScene::TitleScene(const InitData& init)
	: IScene{ init }
	, start_button(RectF{ Arg::center(Scene::Width() / 2, Scene::Height() / 2),500, 100 })
	, exit_button(RectF{ Arg::center(Scene::Width() / 2, Scene::Height() / 1.5),425, 100 })
	, button_font({ 48, U"Assets/fonts/oshigo.otf" })
	, title_font({ 100, U"Assets/fonts/craftmincho.otf" })
	, guide_font({ 28, U"Assets/fonts/oshigo.otf" })
	, exit_audio_playing_flag(false)
	, selected_index(0)
{

}

// 選択中の項目（Start / Exit）を実行する
void TitleScene::decideSelected()
{
	AudioAsset(U"SE_ButtonClicked").playOneShot();

	if (selected_index == 0)
	{
		// Start
		changeScene(U"Game", 0.5);
	}
	else
	{
		// Exit
		exit_audio_playing_flag = true;
	}
}

// 更新関数
void TitleScene::update()
{
	// ↑キーで選択を上（Start）へ
	if (KeyUp.down())
	{
		selected_index = 0;
	}

	// ↓キーで選択を下（Exit）へ
	if (KeyDown.down())
	{
		selected_index = 1;
	}

	// マウスがボタンの上に乗ったら、選択状態もそちらに合わせる
	if (start_button.mouseOver())
	{
		selected_index = 0;
	}
	if (exit_button.mouseOver())
	{
		selected_index = 1;
	}

	// Enterキーで選択中の項目を決定
	if (KeyEnter.down())
	{
		decideSelected();
	}

	// ボタンが左クリックされたらシーン遷移と音
	if (start_button.leftClicked()) {
		selected_index = 0;
		AudioAsset(U"SE_ButtonClicked").playOneShot();
		changeScene(U"Game", 0.5);
	}


	// ボタンが左クリックされたら音とフラグ
	if (exit_button.leftClicked()) {
		selected_index = 1;
		AudioAsset(U"SE_ButtonClicked").playOneShot();
		exit_audio_playing_flag = true;

	}

	//前のフレーム音が再生中で今のフレームには再生中ではないときに終了
	if (exit_audio_playing_flag == true && !AudioAsset(U"SE_ButtonClicked").isPlaying())
	{
		System::Exit(); Print << U"Exit";
	}

	if (!AudioAsset(U"SE_ButtonClicked").isPlaying()) exit_audio_playing_flag = false;

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

	// 選択中のボタンには目立つ枠を追加で描画（子供にも分かりやすいように）
	if (selected_index == 0)
	{
		start_button.stretched(8).drawFrame(0, 6, Palette::Yellow);
	}
	else
	{
		exit_button.stretched(8).drawFrame(0, 6, Palette::Yellow);
	}

	start_button.draw(Palette::Black);
	exit_button.draw(Palette::Blue);

	button_font(U"Start").drawAt(60, start_button.center());

	button_font(U"Exit").drawAt(60, exit_button.center());

	title_font(U"飛べ! イーグルくん").drawAt(100, Vec2{ Scene::Width() / 2,Scene::Height() / 3 });

	// 子供向けの操作説明（画面下部）
	guide_font(U"↑↓ キー：えらぶ　　Enter キー：けってい").drawAt(
		Scene::Width() / 2, Scene::Height() - 40, Palette::White);


}
