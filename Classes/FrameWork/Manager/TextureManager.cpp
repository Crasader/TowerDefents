#include "TextureManager.h"
using namespace cocosgalaxy;

TextureManager* TextureManager::p_myinstance = nullptr;

TextureManager::TextureManager()
{

}

TextureManager* TextureManager::getInstance()
{
	if (p_myinstance == nullptr)
	{
		p_myinstance = new TextureManager();
	}
	return p_myinstance;
}

void TextureManager::LoadResource()
{
	this->LoadResource(vector<Name>());
}


void TextureManager::LoadResource(const vector<Name>& resNameList)
{
	//bool fullLoad = true;
	//if (resNameList.size() == 0)fullLoad = false;

	FileUtils* fileUtils = FileUtils::getInstance();
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	for (auto& var : resNameList)
	{
		//CCASSERT(!fileUtils->isFileExist(var.substr(var.find_last_of('/') + 1)), string("Texture [" + var + "] NOT found").c_str());
		CCASSERT(fileUtils->isFileExist(var), string("Texture [" + var + "] NOT found").c_str());
		frameCache->addSpriteFramesWithFile(var);
	}

	this->LoadExtraTexture();

	//plist = StringUtils::format("texture/scene_battle_%03d.plist", 0);
	//if (fileUtils->isFileExist(plist))

	//frameCache->getSpriteFrameByName("")->getTexture();
	//Label* l = Label::createWithCharMap("");

}

void TextureManager::LoadExtraTexture()
{
	FileUtils* fileUtils = FileUtils::getInstance();
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	bool flag = true;

	do{
		//1.���ļ�
		FileUtils* fin = FileUtils::getInstance();
		Data data = fin->getDataFromFile("data/ExtraTextures.json");
		if (data.isNull())
		{
			CCASSERT(false, "[ExtraTextures.json] Lost!");
			flag = false;
			break;
		}

		//2.����json
		string str = string((char*)data.getBytes(), data.getSize());
		rapidjson::Document root;
		root.Parse<0>(str.c_str());
		if(!(root.IsObject() && root.HasMember("ExtraTexture") && root["ExtraTexture"].IsArray()))
		{
			CCASSERT(false, "illegal [ExtraTexture.json]");
			flag = false;
			break;
		}

		//3.��ȡjson����
		int size = root["ExtraTexture"].Size();
		for (int i = 0; i < size; i++)
		{
			string var = root["ExtraTexture"][i].GetString();

			CCASSERT(fileUtils->isFileExist(var), string("Texture [" + var + "] NOT found").c_str());
			frameCache->addSpriteFramesWithFile(var);
		}

	} while (0);
}


void TextureManager::FreeAllResource()
{
	SpriteFrameCache::getInstance()->destroyInstance();
}

void TextureManager::FreeResource(const vector<Name>& resName)
{
	//std::string plist;
	//FileUtils* fileUtils = FileUtils::getInstance();
	//SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	//switch (type)
	//{
	//case Texture_Battle:
	//	for (int i = 0;; i++)
	//	{
	//		plist = StringUtils::format("scene_battle_%03d.plist", i);
	//		if (fileUtils->isFileExist(plist))
	//			frameCache->removeSpriteFramesFromFile(plist);
	//		else
	//			break;
	//	}
	//	break;
	//case Texture_UI:
	//	break;
	//default:
	//	break;
	//}
}






