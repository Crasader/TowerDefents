#pragma once
#include "stdfax.h"
#include "Ability.h"
#include "EnumConst.h"
#include "CWeapon.h"
#include "Modification.h"
class Actor;
class CEffect;
class CSkill;
class CBehavior;

class Unit
{
public:
	/* ----����---- */
	
	int ID;
	AbilityValueEx<float> HP;
	AbilityValueEx<float> MP;
	AbilityValueEx<float> AP;
	Ability<float> Speed;
	int Radius;
	//Ability<Cost> KillResource;
	//Ability<Cost> CreateCost;
	Ability<float> KillEXP;
	float EXP;
	Ability<float> DamageDefents[DamageTypeCount];

	/* ----����---- */

	Unit();
	~Unit();

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
	virtual void onAttack(Unit* target);
	virtual void onBeAttack(int damage, EDamageType damageType);
	virtual void onMissTarget(Unit* target);

	virtual void addEffect(CEffect* effect);
	virtual void addSkill(CSkill* skill);
	virtual void addBehavior(CBehavior* behavior);
	virtual void applyAction(Name actionName, float playtime = 0);
	virtual void applyAEffect(Name effectName, float playtime = 0);

	virtual void setType(UnitType type);
	virtual UnitType getType();

	void setState(EUnitState state);
	EUnitState getState();

	void setWeapon(CWeapon* weapon);
	CWeapon* getWeapon();
protected:
	/* ----����---- */
	Name m_name;
	UnitType m_type;
	EUnitState m_state;
	Point m_pos;
	CWeapon* m_weapon;

	std::list<CEffect*> effects;
	std::list<CSkill*> skills;
	std::list<CBehavior*> m_behaviors;
	std::list<Modification> m_modification;


	Name m_actorName;
	Actor* m_actor;

	/* ----����---- */
	virtual void onBindSprite();
	virtual void onMove();
	virtual void onHitTarget();
	virtual void onDead();
	virtual void onDeaded();
private:
	void updateModification();
};

