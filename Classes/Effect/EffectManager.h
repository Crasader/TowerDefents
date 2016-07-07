#pragma once
#include "CEffect.h"


class EffectManager
{
public:
	//����ģʽ
	static EffectManager* getInstance();

	int LoadEffectList();

	CEffect* createCEffect(string key, GameObject* parent, GameObject* target=nullptr);
	bool findEffect(const string& key);
private:
	EffectManager();
	static EffectManager* p_myinstance;
	std::map<string, CEffect*> effectlist;

};



