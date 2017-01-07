#pragma once
#include "CBehavior.h"
#include "CModification.h"

namespace cocosgalaxy
{
	class CBeahaviorBuff : public CBehavior
	{
	public:
		CBeahaviorBuff();
		~CBeahaviorBuff();

		virtual CBehavior* clone();
		virtual bool meetRequirement();
		virtual void Install(CUnit* parent);
		virtual void Uninstall(CUnit* parent);
		virtual void update(float dt);

		list<CModification> m_modList;	//����
		//Verfier m_verfier;			//��֤��
		bool isTimeLimitBuff;			//��ʱBUFF
		float m_lifetime;				//����ʱ��
		float m_cycle;					//����
		int m_cycleCount;				//������
		Name m_cycleEffect;				//����Ч��
		//DamageResponse m_damageResponse;//�˺���Ӧ
	private:




	};

}