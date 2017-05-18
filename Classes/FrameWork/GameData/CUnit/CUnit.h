#pragma once
#include "GalaxyBase.h"
#include "Ability.h"
#include "CGameData.h"

namespace cocosgalaxy
{
	class CWeapon;
	class CActor;
	class CBehavior;
	class CEffect;
	class CSkill;
	class CModification;

	class CUnit : public CGameData
	{
	public:
		/* ----����---- */
		
		AbilityEx<float> HP;
		AbilityEx<float> MP;
		AbilityEx<float> AP;
		Ability<float> HP_RegenRate;
		Ability<float> MP_RegenRate;
		Ability<float> AP_RegenRate;
		Ability<float> Speed;
		int Radius;
		//Ability<Cost> KillResource;
		//Ability<Cost> CreateCost;
		Ability<float> KillEXP;
		float EXP;
		Ability<float> Armor[DamageTypeCount];
		Ability<float> Resistance[DamageTypeCount];

		/* ----����---- */

		CUnit();
		~CUnit();

		Point getPos();
		void setPos(Point pos);

		Name getActorName();
		void setActorName(Name actorName);
		void bindActor();

		/*�ж������Ƿ���RADIUS��Χ��*/
		bool isClickMe(Point pos);

		/*��������*/
		virtual void drawMyOutLine(DrawNode* drawNode);

		virtual void update(float dt);


		virtual void onClick();
		virtual void onAttack(vector<CUnit*> targets);
		virtual void onBeAttack(int damage, EDamageType damageType);
		virtual void onMissTarget(CUnit* target);

		/*���Ч��*/
		virtual void addEffect(CEffect* effect);
		/*��Ӽ���*/
		virtual void addSkill(CSkill* skill);
		/*��Ӽ���*/
		virtual void addSkill(const Name& skillName);
		/*�����Ϊ*/
		virtual void addBehavior(CBehavior* behavior);
		/*�����Ϊ*/
		virtual void addBehavior(const Name& behaviorName);
		/*���Ŷ���*/
		virtual void applyAction(Name actionName, float playtime = 0);
		/*����Ч��*/
		virtual void applyAEffect(Name effectName, float playtime = 0);
		/*�Ƴ�Ч��*/
		virtual void removeEffect(const Name& effectName);
		/*�Ƴ�����*/
		virtual void removeSkill(const Name& skillName);
		/*�Ƴ���Ϊ*/
		virtual void removeBehavior(const Name& behaviorName);


		virtual void setType(UnitType type);
		virtual UnitType getType();

		void setState(EUnitState state);
		EUnitState getState();

		virtual void setWeapon(CWeapon* weapon);
		virtual void setWeapon(const Name& weapon);
		virtual CWeapon* getWeapon();

		virtual void setTarget(vector<int> targetID);
		virtual void setTarget(int targetID);
		virtual vector<CUnit*> getTarget();

		virtual CUnit* clone();
	protected:
		/* ----����---- */
		UnitType m_type;
		EUnitState m_state;
		Point m_pos;
		CWeapon* m_weapon;
		vector<Point> m_targetPos;
		vector<int> m_targetID;

		std::list<CEffect*> effects;
		std::list<CSkill*> skills;
		std::list<CBehavior*> m_behaviors;
		std::list<CModification> m_modification;


		Name m_actorName;
		CActor* m_actor;

		/* ----����---- */
		virtual void onBindSprite();
		virtual void onMove();
		virtual void onHitTarget();
		virtual void onDead();
		virtual void onDeaded();
	private:
		void updateModification();
	};

}