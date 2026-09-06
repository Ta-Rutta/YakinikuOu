#include "GameScenen.h"
#include "stdafx.h"


// コンストラクタ（親クラス IScene の初期化を行う）
GameScenen::GameScenen(const InitData& init)
	: IScene{ init }
{

}

// 更新関数
void GameScenen::update()
{
	// ボタンが左クリックされたらシーン遷移
	if (start_button.leftClicked())
	{
		// 次のシーンへ遷移（例: ゲーム本体シーンへ遷移する場合は U"Game" など）
		changeScene(U"Result");
	}
}

// 描画関数
void GameScenen::draw() const
{
	Scene::SetBackground(Palette::White);

	start_button.draw(Palette::Yellow);

	Print << U"Game";
}
