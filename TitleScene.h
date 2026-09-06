#pragma once

using App = SceneManager<String>;

// タイトルシーン
class TitleScene : public App::Scene
{
public:
	//スタートボタン
	const Rect start_button{ 400, 300, 200, 100 };

	//コンストラクタ
	TitleScene(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;
};
