#pragma once
# include "Common.h"

// タイトルシーン
class ResultScene : public App::Scene
{
public:
	//Commomから受け取るデータ
	String name;
	double milage;

	//今回のスコア表示をする
	Font score;

	const RectF retry_button{ 100,25,750,550 };

	const RectF title_button{ 100,25,750,575 };

	//コンストラクタ
	ResultScene(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;

	void RetryButton();

	void TitleButton();

};
