#pragma once
#include "stdfax.h"
#include "Bullet.h"

enum BulletType{Ball,Missile};

class BulletFactory
{
public:
	//����ģʽ
	static BulletFactory* getInstance();

	Bullet* CreateBullet(int BulletID, Point pos, GameObject* target);


private:
	BulletFactory();
	static BulletFactory* p_myinstance;

	BulletType getBulletType(int BulletID);
	Sprite* getSprite(int BulletID);
	Ability getAbility(int BulletID);
};



