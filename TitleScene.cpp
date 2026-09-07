#include "stdafx.h"
#include "TitleScene.h"
// タイトルシーン


// コンストラクタ（親クラス IScene の初期化を行う）
TitleScene::TitleScene(const InitData& init)
	: IScene{ init }
{

}

// 更新関数
void TitleScene::update()
{
	// ボタンが左クリックされたらシーン遷移
	if (start_button.leftClicked())
	{
		// 次のシーンへ遷移（例: ゲーム本体シーンへ遷移する場合は U"Game" など）
		changeScene(U"Game");
	}
}

// 描画関数
void TitleScene::draw() const
{
	Scene::SetBackground(Palette::White);

	start_button.draw(Palette::Black);

	Print << U"Title";
}
