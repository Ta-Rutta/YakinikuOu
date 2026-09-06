#pragma once

using App = SceneManager<String>;

// タイトルシーン
class ResultScene : public App::Scene
{
public:

	//コンストラクタ
	ResultScene(const InitData& init);

	//更新関数
	void update() override;

	//描画関数
	void draw() const override;
};
