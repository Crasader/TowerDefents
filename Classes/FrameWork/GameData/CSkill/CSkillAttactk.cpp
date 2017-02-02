#include "CSkillAttactk.h"
#include "UnitManager.h"
//#include "Bullet.h"
using namespace cocosgalaxy;

CSkillAttactk::CSkillAttactk()
{
	m_weapon = nullptr;
	m_targetID = -1;
	m_targetPos = Point::ZERO;
}


CSkillAttactk::~CSkillAttactk()
{

}

CSkill* CSkillAttactk::clone()
{
	CSkillAttactk* skill = new CSkillAttactk();
	skill->name = this->name;
	skill->m_state = this->m_state;
	skill->Range = this->Range;
	skill->AutoUseRange = this->AutoUseRange;
	skill->Cost = this->Cost;
	skill->chance = this->chance;
	skill->Fliter = this->Fliter;

	return skill;
}



void CSkillAttactk::update(float dt)
{
	CUnit* m_parent = getParent();
	if (m_parent == nullptr )return;

	m_weapon = getParent()->getWeapon();
	if (m_weapon == nullptr)return;

	float ColdDown = m_weapon->ColdDown.Max;
	float ColdDowning = m_weapon->ColdDown;
	if (ColdDowning > ColdDown)ColdDowning = ColdDown;

	if (ColdDowning > dt)
		ColdDowning -= dt;
	else
	{
		switch (m_state)
		{
		case SkillEffectState_ColdDowning:
			ColdDowning = 0;
			m_state = SkillEffectState_Ready;
			break;

		case SkillEffectState_Ready:
			//ʹ�ü��ܵ�����
			if (m_parent->getState() == EUnitState::UnitState_Normal && IsCanExecute())
			{
				//�ɹ����ж�
				if (chance == 1 || rand_0_1() <= chance)
				{
					m_parent->setState(EUnitState::UnitState_UsingSkill);
					m_state = SkillEffectState_Approaching;
				}
				else
					m_state = SkillEffectState_End;
			}
			break;

		case SkillEffectState_Approaching:
			ColdDowning = 0;
			m_state = SkillEffectState_Beforing;
			if (ColdDowning != 0)break;

		case SkillEffectState_Beforing:
			ColdDowning = m_weapon->beforing_Delay;
			m_parent->applyAction(m_weapon->beforing_Animate, m_weapon->beforing_Delay);
			m_state = SkillEffectState_Using;
			if (ColdDowning != 0)break;

		case SkillEffectState_Using:
			ColdDowning = m_weapon->using_Delay;
			this->onAttack(m_parent);//onAttack
			m_parent->applyAction(m_weapon->using_Animate, m_weapon->using_Delay);
			m_state = SkillEffectState_Aftering;
			if (ColdDowning != 0)break;
			       
		case SkillEffectState_Aftering:
			ColdDowning = m_weapon->aftering_Delay;
			m_parent->applyAction(m_weapon->aftering_Animate, m_weapon->aftering_Delay);
			m_state = SkillEffectState_End;
			if (ColdDowning != 0)break;

		case SkillEffectState_End:
			ColdDowning = m_weapon->ColdDown.Max;
			m_parent->setState(EUnitState::UnitState_Normal);
			m_state = SkillEffectState_ColdDowning;
			m_targetID = -1;
			m_targetPos = Point::ZERO;
			if (ColdDowning != 0)break;
		default:
			break;
		}
	}

	m_weapon->ColdDown = ColdDowning;
}


bool CSkillAttactk::IsCanExecute()
{
	//��󹥻�Ŀ��С��0
	int targetCount = m_weapon->TargetCount;
	if (targetCount <= 0)return false;

	//������һ�������ڹ�����Χ��ʱ���������ܣ�������Ŀ��
	CUnit* m_parent = getParent();
	auto vec = UnitManager::getInstance()->findUnit(m_weapon->Filter);
	for (auto target : vec){
		if ((target->getPos() - m_parent->getPos()).lengthSquared() < m_weapon->Range*m_weapon->Range)
		{
			m_targetID = target->ID;
			m_targetPos = target->getPos();
			return true;
		}

	}

	return false;
}


void CSkillAttactk::onAttack(CUnit* parent)
{
	CUnit* m_parent = getParent();
	int targetCount = m_weapon->TargetCount;
	auto vec = UnitManager::getInstance()->findUnit(m_weapon->Filter);

	CCostUnit costPerAtk;
	float costPer = (m_weapon->Damage.Max.getValue() - m_weapon->Damage.Min.getValue())*m_weapon->CostDamageRangeRate.getValue() + m_weapon->Damage.Min.getValue();
	costPerAtk.HP = m_weapon->CostBase.HP + costPer * m_weapon->CostDamageRate.HP.getValue();
	costPerAtk.MP = m_weapon->CostBase.MP + costPer * m_weapon->CostDamageRate.MP.getValue();
	costPerAtk.AP = m_weapon->CostBase.AP + costPer * m_weapon->CostDamageRate.AP.getValue();
	costPerAtk.Speed = m_weapon->CostBase.Speed + costPer * m_weapon->CostDamageRate.Speed.getValue();

	bool missTaget = true;
	for (auto target : vec){
		if (targetCount <= 0)break;
		if (!costPerAtk.isCanPay(parent))break;

		if ((target->getPos() - parent->getPos()).lengthSquared() < m_weapon->Range*m_weapon->Range)
		{
			costPerAtk.payCost(parent);
			missTaget = false;
			m_parent->onAttack(target);
			targetCount--;
		}
	}

	//���ʧȥĿ�꣬ԭ��������Ŀ����ǰҡʱ�ܳ��˹�����Χ����ǿ�ƹ���һ��ʼ������Ŀ��
	if (missTaget && m_weapon->TargetCount > 0)
	{
		auto target = UnitManager::getInstance()->getUnit(m_targetID);
		if (costPerAtk.isCanPay(parent) && target != nullptr)
		{
			costPerAtk.payCost(parent);
			m_parent->onAttack(target);
			//Bullet* bullet = new Bullet(m_weapon, m_parent->ID, target->ID, parent->getPos());
			//UnitManager::getInstance()->addUnit(bullet);
			missTaget = false;
		}
	}

	if (!missTaget)
	{
		m_weapon->CostBase.payCost(parent);
	}
}






