#include "stdafx.h"
#include "TitleScene.h"
// タイトルシーン


// コンストラクタ（親クラス IScene の初期化を行う）
TitleScene::TitleScene(const InitData& init)
	: IScene{ init }
	, start_button({ Arg::center(400, 250), 500, 100 })
	, exit_button({ Arg::center(400, 400), 425, 100 })
	, button_font({ 48, U"Assets/fonts/oshigo.otf" })
	, title_font({ 48, U"Assets/fonts/craftmincho.otf" })
	, button({ U"Assets/sound-effect/button.mp3" })
	, exit_audio_playing_flag(false)
{
	
}

// 更新関数
void TitleScene::update()
{
	// ボタンが左クリックされたらシーン遷移と音
	if (start_button.leftClicked()) {
		button.play();
		changeScene(U"Game");
	}
		

	// ボタンが左クリックされたら音とフラグ
	if (exit_button.leftClicked()) {
		button.play();
		exit_audio_playing_flag = true;

	}

	//前のフレーム音が再生中で今のフレームには再生中ではないときに終了
	if (exit_audio_playing_flag == true && !button.isPlaying()) { System::Exit(); Print << U"Exit"; }

	if (!button.isPlaying()) exit_audio_playing_flag = false;

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
