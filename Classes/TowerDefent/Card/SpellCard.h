#pragma once
#include "stdfax.h"
#include "CCostPlayer.h"

class SpellCard
{
public:
	SpellCard();
	//SpellCard(Tower* tower, Direction direction);
	~SpellCard();


	int ID;			//���п�Ƭ��ID
	int gid;		//��Ϸ����ʱ��ID��0-7��
	Name name;
	int Icon;
	Name behaviorName;
	Name uiName;
	Name uiDescription;
	CCostPlayer costPlayer;

	float cost;
	CCostPlayer price;

private:

};
