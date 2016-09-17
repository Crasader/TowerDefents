#pragma once
#include "stdfax.h"
#include "CBehavior.h"
#include "Modification.h"




class CBeahaviorBuff : public CBehavior
{
public:
	CBeahaviorBuff();
	~CBeahaviorBuff();

	virtual CBehavior* clone();
	virtual bool meetRequirement();
	virtual void Install(Unit* parent);
	virtual void Uninstall(Unit* parent);
	virtual void update(float dt);

	list<Modification> m_modList;	//����
	//Verfier m_verfier;			//��֤��
	bool isTimeLimitBuff;			//��ʱBUFF
	float m_lifetime;				//����ʱ��
	float m_cycle;					//����
	Name m_cycleEffect;				//����Ч��
	int m_cycleCount;				//������
	//DamageResponse m_damageResponse;//�˺���Ӧ
private:




};

