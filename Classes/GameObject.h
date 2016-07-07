#pragma once
#include"stdfax.h"
#include"Ability.h"

enum GameObjectType
{
	GameObject_UnKnow = 0,
	GameObject_Tower,
	GameObject_Monster,
	GameObject_Bullet
};

class GameObjectLayer;

class GameObject : public Layer
{
public:
	GameObject();
	~GameObject();


	Ability m_ability;
	Ability cur_ability;
	CC_SYNTHESIZE(Point, m_pos, Pos);					//����Pos��get set����


	bool isClickMe(Point pos);	//�ж������Ƿ���RADIUS��Χ��
	void bindSprite(Sprite* sprite);
	Sprite* getSprite();
	GameObjectLayer* getPatentLayer();

	/*��������*/
	virtual void drawMyOutLine(DrawNode* drawNode);

	bool isDead();

	virtual void onBeAttack(int damage);
	virtual void onMissTarget(GameObject* target);

	virtual GameObjectType getObjectType() = 0;
protected:
	virtual void onBindSprite();
	virtual void onAttack();
	virtual void onMove();
	virtual void onHitTarget();
	virtual void onDead();

private:
	bool m_isDeath;				//�Ƿ�����
	Sprite* m_sprite;			//�������

};

