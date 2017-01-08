#pragma once
#include "GalaxyBase.h"
#include "CUnit.h"
#include "UnitCreator.h"

namespace cocosgalaxy
{
	/*
	UnitManager
	������Ϸ�����е�Unit�������������
	*/
	class UnitManager
	{
	public:
		static bool isDebug;

		static UnitManager* getInstance();

		//��ʼ��Manager
		void init(UnitCreator* unitCreator = nullptr);
		void update(float dt);

		/*��UnitCreator���ɵĻᱻ�ͷţ�*/
		void bindUnitCreator(UnitCreator* unitCreator);
		/*����typeID��ʹ�ð󶨵�UnitCreator����Unit�������������*/
		CUnit* CreateUnit(int typeID);
		/*����typeName��ʹ�ð󶨵�UnitCreator����Unit�������������*/
		CUnit* CreateUnit(string typeName);

		/*����ID��ȡUnit����*/
		CUnit* getUnit(int id);
		/*���Unit��Manager����*/
		void addUnit(CUnit* child);
		
		/*�Ƴ�������Unit*/
		void removeUnit(CUnit* child);
		/*Ѱ��һ���ض�����Unit*/
		vector<CUnit*> findUnit(UnitType TypeFilter);

	private:
		int next_UnitID;
		static UnitManager* p_myinstance;
		std::list<CUnit*> m_UnitList;
		UnitCreator* unitCreator;

		UnitManager();
		void debugDraw();
	};
}


