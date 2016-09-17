#pragma once
#include "stdfax.h"
#include "Unit.h"

class Bullet : public Unit
{
public:
	Bullet();
	Bullet(CWeapon* weapon, int parentID, int targetID, Point pos);

	~Bullet();


	/*��������*/
	virtual void drawMyOutLine(DrawNode* drawNode);
	virtual void update(float dt);

	void setParent(int patentID);
	Unit* getParent();

	void setTarget(int targetID);
	Unit* getTarget();



	virtual void onMissTarget(Unit* target);

	virtual void setIsTrackTarget(bool IsTrackTarget);			//�Ƿ����Ŀ��
	virtual void setIsFaceToTargetPos(bool IsFaceToTargetPos);	//�����Ƿ�ָ��Ŀ��
	virtual void setOnHitEffect(CEffect* effect);				//�������к��Ч��

	virtual Bullet* clone();//ǳ����

protected:
	Point m_targetPos;
	int m_parentID;
	int m_targetID;
	CEffect* m_hitEffect;


	bool isTrackTarget;
	bool isFaceToTargetPos;

	virtual void onTargetDead();
	virtual void onMove(float dt);
	virtual void onHitTarget();
	virtual void onDead();
};

