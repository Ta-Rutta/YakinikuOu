#include "stdafx.h"
#include "ResultScene.h"

// コンストラクタ（親クラス IScene の初期化を行う）
ResultScene::ResultScene(const InitData& init)
	: IScene{ init }
{

}

// 更新関数
void ResultScene::update()
{

}

// 描画関数
void ResultScene::draw() const
{
	Scene::SetBackground(Palette::White);

	Print << U"Result";
}
