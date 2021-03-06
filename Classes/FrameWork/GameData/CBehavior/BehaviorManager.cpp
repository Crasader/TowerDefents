#include "BehaviorManager.h"

using namespace cocosgalaxy;

BehaviorManager* BehaviorManager::p_myinstance = nullptr;

BehaviorManager::BehaviorManager()
{
	isInit = false;
	behaviorCreator = nullptr;
}

BehaviorManager::~BehaviorManager()
{

}

BehaviorManager* BehaviorManager::getInstance()
{
	if (p_myinstance == nullptr)
	{
		p_myinstance = new BehaviorManager();
	}
	return p_myinstance;
}

void BehaviorManager::init(BehaviorCreator* behaviorCreator)
{
	if (behaviorCreator == nullptr)
	{
		this->behaviorCreator = new BehaviorCreator();
	}
	else
	{
		this->behaviorCreator = behaviorCreator;
	}

	isInit = true;
}


void BehaviorManager::LoadResource()
{
	this->LoadResource(vector<Name>());
}

void BehaviorManager::LoadResource(const vector<Name>& resNameList)
{
	CCASSERT(isInit, "the BehaviorManager is NOT init !");

	//1.打开文件
	FileUtils* fin = FileUtils::getInstance();
	Data data = fin->getDataFromFile("data/Behavior.json");
	CCASSERT(!data.isNull(), "[Behavior.json] NOT found");

	//2.载入json
	string str = string((char*)data.getBytes(), data.getSize());
	rapidjson::Document root;
	root.Parse<0>(str.c_str());
	CCASSERT(root.IsObject() && root.HasMember("Behaviors") && root["Behaviors"].IsArray(), "illegal [Behavior.json]: BehaviorData error");

	//3.读取json数据
	float scale = 1 / Director::getInstance()->getContentScaleFactor();

	bool fullLoad = true;
	if (resNameList.size() != 0)fullLoad = false;
	int Size = root["Behaviors"].Size();
	for (int i = 0; i < Size; i++) 
	{
		JsonNode jNode = root["Behaviors"][i];
		string name = jNode["name"].GetString();
		if (fullLoad || std::find(resNameList.begin(), resNameList.end(), name) != resNameList.end())
		{
			string className = jNode["class"].GetString();
			rapidjson::StringBuffer buffer;
			rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
			jNode.Accept(writer);
			m_behaviorList[name] = static_cast<CBehavior*>(behaviorCreator->Create(className, buffer.GetString()));
		}
	}
}

void BehaviorManager::FreeAllResource()
{
	for (auto var : m_behaviorList)
		delete var.second;
	m_behaviorList.clear();
}

void BehaviorManager::FreeResource(const vector<Name>& resName)
{

}


CBehavior* BehaviorManager::createBehavior(string key, int parentID, int targetID)
{
	CCASSERT(isInit, "the BehaviorManager is NOT init !");

	if (m_behaviorList.find(key) != m_behaviorList.end()){
		CBehavior* behavior = m_behaviorList[key]->clone();
		return behavior;
	}
	//log("EffectManager->createCEffect() : CEffect [%s] Not Found !", key.c_str());
	CCASSERT(false, StringUtils::format("EffectManager->createCEffect() : CEffect [%s] Not Found !", key.c_str()).c_str());
	return nullptr;
}



CBehavior* BehaviorManager::loadBeahaviorBuff(JsonNode jNode)
{
	//CBeahaviorBuff* beahavior = new CBeahaviorBuff();

	//if (jNode.HasMember("name"))				beahavior->name = jNode["name"].GetString();
	//if (jNode.HasMember("isTimeLimitBuff"))		beahavior->isTimeLimitBuff = jNode["isTimeLimitBuff"].GetBool();
	//if (jNode.HasMember("lifetime"))			beahavior->m_lifetime = jNode["lifetime"].GetDouble();
	//if (jNode.HasMember("cycle"))				beahavior->m_cycle = jNode["cycle"].GetDouble();
	//if (jNode.HasMember("cycleCount"))			beahavior->m_cycleCount = jNode["cycleCount"].GetInt();
	//if (jNode.HasMember("cycleEffect"))			beahavior->m_cycleEffect = jNode["cycleEffect"].GetString();

	//if (jNode.HasMember("mod") && jNode["mod"].IsArray())
	//{
	//	JsonNode modNode = jNode["mod"];

	//	int Size = modNode.Size();
	//	for (int i = 0; i < Size; i++) {
	//		CModification mod;
	//		if (modNode[i].HasMember("modMainType"))	mod.mainType = (EModificationMainType)modNode[i]["modMainType"].GetInt();
	//		if (modNode[i].HasMember("modValueType"))	mod.modType = (EModificationType)modNode[i]["modValueType"].GetInt();
	//		if (modNode[i].HasMember("priority"))		mod.priority = modNode[i]["priority"].GetInt();
	//		if (modNode[i].HasMember("valueType") && modNode[i].HasMember("value"))
	//		{
	//			JsonNode var = modNode[i]["value"];
	//			switch ((EModValueType)modNode[i]["valueType"].GetInt())
	//			{
	//			case EModValueType::EModValueType_int:		mod.value = Value(var.GetInt());	break;
	//			case EModValueType::EModValueType_float:	mod.value = Value(var.GetDouble());	break;
	//			case EModValueType::EModValueType_string:	mod.value = Value(var.GetString());	break;
	//			case EModValueType::EModValueType_bool:		mod.value = Value(var.GetBool());	break;
	//			default:CCASSERT(false, "Error EModValueType!"); break;
	//			};
	//		}
	//		beahavior->m_modList.push_back(mod);
	//	}
	//}

	//return beahavior;
	return nullptr;
}


