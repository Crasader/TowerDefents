#pragma once
#include "CSkillEffect.h"

class CSkillEffectInstant : public CSkillEffect
{
public:
	/*��ȴʱ��*/
	float ColdDown;
	/*��ȴʱ��ʣ��*/
	float ColdDowning;

	CSkillEffectInstant();
	~CSkillEffectInstant();

	virtual CSkill* clone();


};

