#pragma once
#include "CEffectResponse.h"

namespace cocosgalaxy
{
	class CEffectDamage : public CEffectResponse
	{
	public:
		CEffectDamage();
		CEffectDamage(float minDamage, float maxDamage, EDamageType damageType = EDamageType::EDamageType_Weapon, Name effectAnimate = "", int parentID = -1, int targetID = -1);
		~CEffectDamage();

		virtual CEffect* clone();
		virtual void execute();


		float minDamage;			//��С�˺�
		float maxDamage;			//����˺�
		EDamageType damageType;	//�˺�����
		Name effectAnimate;		//Ч������
	private:


	};
}
