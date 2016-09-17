#pragma once
#include "stdfax.h"
#include "Bullet.h"



class BulletFactory
{
public:
	//����ģʽ
	static BulletFactory* getInstance();

	Bullet* CreateBullet(int BulletID, Point pos, Unit* target);

private:
	BulletFactory();
	static BulletFactory* p_myinstance;


	/*���ļ��������е�ͷ*/
	int LoadBulletList();
	std::map<int, Bullet*> bulletlist;

	//BulletType getBulletType(int BulletID);
	//Sprite* getSprite(int BulletID);
	//Ability getAbility(int BulletID);
};



