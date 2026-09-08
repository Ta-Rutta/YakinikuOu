#pragma once

struct GameData
{
	String name;//ユーザーネーム
	double milage;//飛行距離
};

using App = SceneManager<String,GameData>;
