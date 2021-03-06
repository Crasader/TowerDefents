#pragma once
#include "CSkill.h"
#include "ResourceLoader.h"

namespace cocosgalaxy
{
	class SkillManager :public ResourceLoader
	{
	public:
		//����ģʽ
		static SkillManager* getInstance();
		~SkillManager();

		virtual void LoadResource();
		virtual void LoadResource(const vector<Name>& resNameList);
		virtual void FreeAllResource();
		virtual void FreeResource(const vector<Name>& resName);

		CSkill* createCSkill(string key, CUnit* parent);
		bool findSkill(const string& key);


	private:
		SkillManager();
		static SkillManager* p_myinstance;


		std::map<string, CSkill*> m_skilllist;
	};
}


