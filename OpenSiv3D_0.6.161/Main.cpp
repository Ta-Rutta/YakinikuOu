# include <Siv3D.hpp>


// ステートの型は String
using App = SceneManager<String>;

#include "Title.h"
void Main()
{
	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 48, Typeface::Bold);

	// シーンマネージャーを作成
	App manager;

	// タイトルシーン（名前は "Title"）を登録する
	manager.add<Title>(U"Title");


	while (System::Update())
	{
		// 現在のシーンを実行する
		// シーンに実装した .update() と .draw() が実行される
		if (not manager.update())
		{
			break;
		}
	}
}
