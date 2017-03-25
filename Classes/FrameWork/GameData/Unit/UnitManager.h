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
		CUnit* CreateUnit(int classHash, string typeName);
		/*����typeName��ʹ�ð󶨵�UnitCreator����Unit�������������*/
		CUnit* CreateUnit(string className, string typeName);

		/*����ID��ȡUnit����*/
		CUnit* getUnit(int id);
		/*���Unit��Manager����*/
		void addUnit(CUnit* child);
		
		/*�Ƴ�������Unit*/
		void removeUnit(CUnit* child);
		/*��������unit*/
		void removeAllUnit();

		/*Ѱ��һ���ض�����Unit*/
		vector<CUnit*> findUnit(UnitType TypeFilter);

		/*��ѯ�Ƿ�����ض����͵�unit*/
		bool hasUnitType(UnitType TypeFilter);

	private:
		bool isInit;

		int next_UnitID;
		static UnitManager* p_myinstance;
		std::list<CUnit*> m_UnitList;
		UnitCreator* unitCreator;

		UnitManager();
		~UnitManager();
		void debugDraw();
	};
}


