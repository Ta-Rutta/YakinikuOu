#pragma once
# include "Common.h"

// タイトルシーン
class ResultScene : public App::Scene
{
private:
	//Commomから受け取るデータ
	String name;
	double milage;

	//今回のスコア表示をする
	Font score;

	//リトライ用ボタン
	const RectF retry_button{ 700,500,100,25 };
	Font retry;

	//タイトルに戻るボタン
	const RectF title_button{ 700,550,100,25 };
	Font title;

public:
	//コンストラクタ
	ResultScene(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;

	void RetryButton();

	void TitleButton();

};
