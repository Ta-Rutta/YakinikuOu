#pragma once

class ReadOnlySpeed
{
public:
	virtual ~ReadOnlySpeed() = default;

	// 値を取得するメソッドのみを定義 (const メソッド)
	virtual double checkSpeed()const = 0;


};
