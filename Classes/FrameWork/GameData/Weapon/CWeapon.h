#pragma once
#include "stdfax.h"
#include "EnumConst.h"
#include "Ability.h"
#include "CCostUnit.h"

class CEffect;

class CWeapon
{
public:

	/*�����̶�����  ʵ�ʻ���=CostBase + ((Damage.Max - Damage.Min)*CostDamageRangeRate + Damage.Min)*TargetCount*CostDamageRate */
	CCostUnit CostBase;
	/*�����˺�����  ʵ�ʻ���=CostBase + ((Damage.Max - Damage.Min)*CostDamageRangeRate + Damage.Min)*TargetCount*CostDamageRate  */
	CCostUnit CostDamageRate;
	/*�����˺���������  ʵ�ʻ���=CostBase + ((Damage.Max - Damage.Min)*CostDamageRangeRate + Damage.Min)*TargetCount*CostDamageRate */
	Ability<float> CostDamageRangeRate;

	/*������*/
	Ability<float> chance;
	/*���*/
	Ability<float> Range;
	/*CD*/
	AbilityEx<float> ColdDown;
	/*���ͬʱ����Ŀ��*/
	Ability<int> TargetCount;
	/*Ŀ�����*/
	UnitType Filter;
	/*�˺�����*/
	AbilityKey<EDamageType> DamageType;
	/*�˺�*/
	AbilityEx<float> Damage;


	/*��ը��Χ*/
	Ability<float> BoomRange;
	/*��������Ч��*/
	AbilityKey<string> attack_Effect;
	/*����Ч������*/
	AbilityKey<string> attack_Animate;
	/*������*/
	Ability<float> criticalChance;
	/*�����˺�����*/
	Ability<float> criticalMultiplier;
	/*��������Ч��(����ʱ����������Ч���뱩������Ч��һ�𷢶�)*/
	AbilityKey<string> critical_Effect;
	/*����Ч������*/
	AbilityKey<string> critical_Animate;

	/*��Ա����*/
	AbilityKey<string> ActorName;
	/*ǰҡʱ��*/
	float beforing_Delay;
	/*ʩ��ʱ��*/
	float using_Delay;
	/*��ҡʱ��*/
	float aftering_Delay;
	/*ǰҡ����*/
	string beforing_Animate;
	/*ʩ�Ŷ���*/
	string using_Animate;
	/*��ҡ����*/
	string aftering_Animate;

	/*�ӵ�����*/
	BulletType bulletType;
	/*�Ƿ�׷��Ŀ��*/
	bool IsTrackTarget;
	/*�Ƿ�����Ŀ��*/
	bool IsFaceToTarget;
	/*�ӵ��ƶ��ٶ�*/
	float BulletSpeed;

	CWeapon();
	~CWeapon();
	CWeapon* clone();

	void clearAbility();

	//CWeapon* getCurWeapon();
	//template <typename T>
	//void Upgrade(EWeapon_Upgradable type, T value);
	//void Downgrade();


private:


};

