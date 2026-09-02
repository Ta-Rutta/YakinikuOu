#pragma once

using App = SceneManager<String>;

// タイトルシーン
class Title : public App::Scene
{
public:

	//スタートボタン
	const Rect start_button{ 400, 300, 200, 100 };

	// コンストラクタ（必ず実装する）
	Title(const InitData& init)
		: IScene{ init }
	{

	}

	// 更新関数
	void update() override
	{
		// 長方形を左クリックしたら
		if (start_button.leftClicked());
		{
			changeScene(U"Title");
		}
	}

	// 描画関数
	void draw() const override
	{
		Scene::SetBackground(Palette::White);

		start_button.draw(Palette::Black);
	}
};
