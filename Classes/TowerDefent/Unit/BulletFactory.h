#pragma once
#include "stdfax.h"
#include "Bullet.h"



class BulletFactory
{
public:
	//����ģʽ
	static BulletFactory* getInstance();

	Bullet* CreateBullet(int BulletID, Point pos, CUnit* target);
	Bullet* CreateBullet(int BulletID);
	Bullet* CreateBullet(string bulletName);

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



