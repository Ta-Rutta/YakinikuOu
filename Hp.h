#pragma once

class IHpReadOnly
{
public:
	virtual ~IHpReadOnly() = default;

	virtual int checkHp()const = 0;
};

class Hp:public IHpReadOnly
{
private:
	int hp;

	int maxHp; //最大Hp

	int minHp; //最少Hp

public:
	Hp(); //コンストラクタ

	int checkHp()const; //現在のHpを確認

	void hpDown(); //Hp減少メソッド

	void hpUp(); //Hp上昇メソッド

	
};

