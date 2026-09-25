#pragma once
# include "Common.h"

// タイトルシーン
class TitleScene : public App::Scene
{
private:
	//スタートボタン
	const RectF start_button;
	const RectF exit_button;

	const Font button_font;
	const Font title_font;

	const Font guide_font;

	bool exit_audio_playing_flag;

	// キー操作用：現在選択中の項目（0:Start, 1:Exit）
	int32 selected_index;

	// 選択中の項目を実行する（Start/Exit共通処理）
	void decideSelected();

public:
	//コンストラクタ
	TitleScene(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;
};
