#pragma once
#include "stdfax.h"
#include "Unit.h"
#include "GridPos.h" 
#include "SpellCard.h"

class Tower : public Unit
{
public:
	//Tower();
	Tower(GridPos* GridPos);
	~Tower();

	/*��������*/
	virtual void drawMyOutLine(DrawNode* drawNode);
	
	virtual void update(float dt);
	virtual void onClick();

	void buildTower(int tid);
	void buildSpellTowerPos(Direction direction);
	void buildSpellTower(Direction direction, const SpellCard* spellTower);
	void sellSpellTower(Direction direction);
	void sellTower();

	Color3B getColor();

private:
	GridPos* m_gridPos;
	Color3B m_color;
	//vector<SpellTower*> m_SpellTower;
	SpellCard* m_SpellTower[8];

	virtual void onAttack(Unit* target);
	virtual void onBindSprite();

};

