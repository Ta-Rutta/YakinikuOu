#pragma once

//飛行距離の管理
class Milage
{
private:
	double milage = 0;

public:
	//addMilage関数：milage変数にdist変数を加算
	void addMilage(double dist);

	//getMilage関数：mailage変数をreturn
	double getMilage();
};

