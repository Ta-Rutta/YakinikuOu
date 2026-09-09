#pragma once
# include "Common.h"

// タイトルシーン
class TitleScene : public App::Scene
{
public:
	//スタートボタン
	const Rect start_button;
	const Rect exit_button;

	const Font button_font;
	const Font title_font;

	const Audio button;

	bool exit_audio_playing_flag;
	//コンストラクタ
	TitleScene(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;
};
