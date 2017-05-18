#pragma once
#include "GalaxyBase.h"
#include "Ability.h"
#include "CCostUnit.h"
#include "CGameData.h"

//class CEffect;

namespace cocosgalaxy
{
	class CWeapon : public CGameData
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
		AbilityKey<std::string> attack_Effect;
		/*����Ч������*/
		AbilityKey<std::string> attack_Animate;
		/*������*/
		Ability<float> criticalChance;
		/*�����˺�����*/
		Ability<float> criticalMultiplier;
		/*��������Ч��(����ʱ����������Ч���뱩������Ч��һ�𷢶�)*/
		AbilityKey<std::string> critical_Effect;
		/*����Ч������*/
		AbilityKey<std::string> critical_Animate;

		/*��Ա����*/
		AbilityKey<std::string> ActorName;
		/*ǰҡʱ��*/
		float beforing_Delay;
		/*ʩ��ʱ��*/
		float using_Delay;
		/*��ҡʱ��*/
		float aftering_Delay;
		/*ǰҡ����*/
		std::string beforing_Animate;
		/*ʩ�Ŷ���*/
		std::string using_Animate;
		/*��ҡ����*/
		std::string aftering_Animate;

		/*�ӵ�����*/
		//BulletType bulletType;
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

}