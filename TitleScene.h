#pragma once
# include "Common.h"

// タイトルシーン
class TitleScene : public App::Scene
{
public:
	//スタートボタン
	const Rect start_button{ 400, 300, 200, 100 };
	const Rect exit_button{ 100, 100, 200, 200 };

	//コンストラクタ
	TitleScene(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;
};
