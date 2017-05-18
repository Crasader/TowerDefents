#pragma once
#include "CActor.h"
#include "ResourceLoader.h"

namespace cocosgalaxy
{
	class ActorManager :public ResourceLoader
	{
	public:
		//����ģʽ
		static ActorManager* getInstance();
		~ActorManager();

		void init(Layer* layer);

		virtual void LoadResource();
		virtual void LoadResource(const vector<Name>& resNameList);
		virtual void FreeAllResource();
		virtual void FreeResource(const vector<Name>& resName);

		CActor* createActor(int id, Name name);
		void playAction(int actorID, Name actionName, float playtime = 0);
		/*�Ƴ�һ����Ա����������������*/
		void removeActor(int id);
		/*�Ƴ�һ����Ա�����̣��޶�����*/
		void destoryActor(int id);

		void destoryAllActor();
	private:
		static ActorManager* p_myinstance;
		Layer* m_layer;

		map<int, CActor*> m_actorlist;
		map<Name, ActorData> m_actordata;

		ActorManager();
		//int findActor(int id);
	};

}




















