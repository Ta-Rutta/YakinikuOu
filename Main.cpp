# include <Siv3D.hpp> // Siv3D v0.6.16

// ステートの型は String
using App = SceneManager<String>;

# include "TitleScene.h"
# include "GameScenen.h"
# include "ResultScene.h"

void Main()
{
	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 48, Typeface::Bold);

	// シーンマネージャーを作成
	App manager;

	// タイトルシーン（名前は "Title"）を登録する
	manager.add<TitleScene>(U"Title");

	// ゲームシーンを登録する
	manager.add<GameScenen>(U"Game");

	// リザルトシーンを登録する
	manager.add<ResultScene>(U"Result");


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

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
