#pragma once
# include "Common.h"

// タイトルシーン
class TitleScene : public App::Scene
{
public:
	//スタートボタン
	const Rect start_button{ Arg::center(400, 250), 500, 100 };
	const Rect exit_button { Arg::center(400, 400), 425, 100 };

	const Font button_font { 48, U"Assets/fonts/oshigo.otf" };
	const Font title_font{ 48, U"Assets/fonts/craftmincho.otf" };

	//コンストラクタ
	TitleScene(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;
};
