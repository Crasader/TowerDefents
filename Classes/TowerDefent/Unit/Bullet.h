#pragma once
#include "stdfax.h"
#include "CUnit.h"

class Bullet : public CUnit
{
public:
	Bullet();
	Bullet(CWeapon* weapon, int parentID, int targetID, Point pos);

	~Bullet();


	/*��������*/
	virtual void drawMyOutLine(DrawNode* drawNode);
	virtual void update(float dt);

	void setParent(int patentID);
	CUnit* getParent();

	virtual void setTarget(int targetID);
	virtual CUnit* getTarget();



	virtual void onMissTarget(CUnit* target);

	virtual void setIsTrackTarget(bool IsTrackTarget);			//�Ƿ����Ŀ��
	virtual void setIsFaceToTargetPos(bool IsFaceToTargetPos);	//�����Ƿ�ָ��Ŀ��
	virtual void setOnHitEffect(CEffect* effect);				//�������к��Ч��

	virtual Bullet* clone();//ǳ����

protected:
	int m_parentID;
	CEffect* m_hitEffect;


	bool isTrackTarget;
	bool isFaceToTargetPos;

	virtual void onTargetDead();
	virtual void onMove(float dt);
	virtual void onHitTarget();
	virtual void onDead();
	virtual void onBindSprite();
};

