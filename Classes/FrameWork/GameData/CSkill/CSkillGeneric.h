#pragma once
#include "CSkill.h"

class CSkillGeneric :public CSkill
{
public:
	/* ----����---- */

	/*��ȴʱ��*/
	float ColdDown;
	/*��ȴʱ��ʣ��*/
	float ColdDowning;
	/*���ܻ���*/
	SkillCost Cost;
	/*���*/
	float Range;
	/*Ŀ��ɸѡ��*/
	UnitType Fliter;
	/*�Զ�ʩ�ŷ�Χ 0=���Զ�ʩ��*/
	float AutoUseRange;
	/*�ɹ���*/
	float chance;

	/* ----����---- */

	CSkillGeneric();
	~CSkillGeneric();
protected:
	ESkillEffectState m_state;
};

