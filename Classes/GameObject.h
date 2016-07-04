#pragma once
#include"stdfax.h"
#include"Ability.h"

class GameObjectLayer;

class GameObject : public Layer
{
public:
	GameObject();
	~GameObject();

	Ability m_ability;
	Ability cur_ability;
	CC_SYNTHESIZE(Point, m_pos, Pos);					//����Pos��get set����


	static GameObject* create(Point pos);
	bool init(Point pos);
	bool isClickMe(Point pos);	//�ж������Ƿ���RADIUS��Χ��
	void bindSprite(Sprite* sprite);
	Sprite* getSprite();

	/*��������*/
	virtual void drawMyOutLine(DrawNode* drawNode);

	bool isDead();

	virtual void onBeAttack(int damage);
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

