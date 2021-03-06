#include "CModification.h"
#include "CWeapon.h"
using namespace cocosgalaxy;

CModification::CModification()
{
	this->mainType = EModificationMainType::EModMainType_NoType;
	this->modType = EModificationType::EModType_None;
	this->value = 0;
	this->priority = 0;
	this->pid = 0;
}

CModification::~CModification()
{

}

CModification::CModification(EModificationMainType maintype, EModificationType modtype, Value value, int priority, int pid)
{
	this->mainType = maintype;
	this->modType = modtype;
	this->value = value;
	this->priority = priority;
	this->pid = pid;

}

bool CModification::operator()(const CModification& mod1, const CModification& mod2)
{
	return mod1.priority < mod2.priority;
}



void CModification::install(CUnit* unit, bool isUninstall)
{

	switch (mainType)
	{
	case EModificationMainType::EModMainType_NoType:

		break;
	case EModificationMainType::EModMainType_Weapon:
		switch (modType)
		{
		case EModType_Weapon:
			break;
		case EModType_Weapon_Chance_Addend:
			unit->getWeapon()->chance.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_Chance_Multiplier:
			unit->getWeapon()->chance.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_ColdDown_Addend:
			unit->getWeapon()->ColdDown.Max.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_ColdDown_Multiplier:
			unit->getWeapon()->ColdDown.Max.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_Range_Addend:
			unit->getWeapon()->Range.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_Range_Multiplier:
			unit->getWeapon()->Range.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_TargetCount_Addend:
			unit->getWeapon()->TargetCount.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_TargetCount_Multiplier:
			unit->getWeapon()->TargetCount.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_MinDamage_Addend:
			unit->getWeapon()->Damage.Min.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_MinDamage_Multiplier:
			unit->getWeapon()->Damage.Min.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_MaxDamage_Addend:
			unit->getWeapon()->Damage.Max.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_MaxDamage_Multiplier:
			unit->getWeapon()->Damage.Max.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_BoomRange_Addend:
			unit->getWeapon()->BoomRange.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_BoomRange_Multiplier:
			unit->getWeapon()->BoomRange.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_CriticalChance_Addend:
			unit->getWeapon()->criticalChance.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_CriticalChance_Multiplier:
			unit->getWeapon()->criticalChance.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_CriticalMultiplier_Addend:
			unit->getWeapon()->criticalMultiplier.add(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_CriticalMultiplier_Multiplier:
			unit->getWeapon()->criticalMultiplier.mul(this->value.asFloat(), isUninstall);
			break;
		case EModType_Weapon_DamageType_Addend:
			unit->getWeapon()->DamageType.add((EDamageType)this->value.asInt(),this->priority, isUninstall);
			break;
		case EModType_Weapon_AttackEffect_Addend:
			unit->getWeapon()->attack_Effect.add(this->value.asString(), this->priority, isUninstall);
			break;
		case EModType_Weapon_AttackAnimate_Addend:
			unit->getWeapon()->attack_Animate.add(this->value.asString(), this->priority, isUninstall);
			break;
		case EModType_Weapon_CriticalEffect_Addend:
			unit->getWeapon()->critical_Effect.add(this->value.asString(), this->priority, isUninstall);
			break;
		case EModType_Weapon_CriticslAnimate_Addend:
			unit->getWeapon()->critical_Animate.add(this->value.asString(), this->priority, isUninstall);
			break;
		case EModType_Weapon_ActorName_Addend:
			unit->getWeapon()->ActorName.add(this->value.asString(), this->priority, isUninstall);
			break;
		default:
			break;
		}
		break;

	}
}

void CModification::uninstall(CUnit* unit)
{
	this->install(unit, true);
}

void CModification::setModification(CUnit* unit, Value value)
{

}









