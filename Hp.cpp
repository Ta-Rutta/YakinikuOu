#include "stdafx.h"
#include "Hp.h"

Hp::Hp()
	:hp(3),maxHp(5),minHp(0)
{
	
}

int Hp::checkHp()const
{
	return hp;
}

void Hp::hpDown()
{
	hp = Max(minHp, hp--);
}

void Hp::hpUp()
{
	hp = Min(maxHp, hp++);
}
