#pragma once
#include "CBehavior.h"
#include "BehaviorCreator.h"
#include "ResourceLoader.h"

namespace cocosgalaxy
{
	class BehaviorManager :public ResourceLoader
	{
	public:
		//����ģʽ
		static BehaviorManager* getInstance();
		~BehaviorManager();

		void init(BehaviorCreator* behaviorCreator = nullptr);

		virtual void LoadResource();
		virtual void LoadResource(const vector<Name>& resNameList);
		virtual void FreeAllResource();
		virtual void FreeResource(const vector<Name>& resName);

		CBehavior* createBehavior(string key, int parentID = -1, int targetID = -1);
	private:
		static BehaviorManager* p_myinstance;

		bool isInit;
		map<Name, CBehavior*> m_behaviorList;
		BehaviorCreator* behaviorCreator;

		BehaviorManager();
		CBehavior* loadBeahaviorBuff(JsonNode jNode);
	};

}

