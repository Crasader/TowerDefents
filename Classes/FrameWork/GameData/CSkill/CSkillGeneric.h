#pragma once
#include "CSkill.h"
#include "CCostUnit.h"


class CSkillGeneric :public CSkill
{
public:
	/* ----����---- */

	/*��ȴʱ��*/
	float ColdDown;
	/*��ȴʱ��ʣ��*/
	float ColdDowning;
	/*���ܻ���*/
	CCostUnit Cost;
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

