#include "BattleScene.h"
#include "DebugDraw.h"

#include "GameMap.h"
#include "UnitManager.h"
#include "ActorManager.h"



BattleScene::BattleScene(){}

BattleScene::~BattleScene()
{

}

BattleScene* BattleScene::create(int wrold, int level)
{
	BattleScene* battleScene = new BattleScene();
	if (battleScene && battleScene->init(wrold, level))
	{
		battleScene->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(battleScene);
	}
	return battleScene;
}

bool BattleScene::init(int wrold, int level)
{
	if (!Scene::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->setContentSize(visibleSize);
	this->setScale(Director::getInstance()->getContentScaleFactor());
	this->setAnchorPoint(Point::ZERO);



	unitLayer = UnitLayer::create();
	this->addChild(unitLayer, 1);
	ActorManager::getInstance()->init(unitLayer);

	//init Map and Layer
	GameMap::getInstance()->init(wrold, level);

	towerSelectLayer = TowerSelectLayer::create();
	this->addChild(towerSelectLayer, 2);

	gameMapLayer = GameMapLayer::create();
	this->addChild(gameMapLayer, 0);

	towerInfoLayer = TowerInfoLayer::create();
	this->addChild(towerInfoLayer, 6000);

	//gameMapInfoLayer = GameMapInfoLayer::create();
	//this->addChild(gameMapInfoLayer, 5999);

	gameInfoLayer = GameInfoLayer::create();
	this->addChild(gameInfoLayer, 5999);


	if (DebugDraw::isDebug)
	{
		Node* layer;
		layer = DebugDraw::getInstance();
		this->addChild(layer, 999999);
	}

	this->scheduleUpdate();
	return true;
}

void BattleScene::update(float dt)
{
	GameMap::getInstance()->update(dt);

	towerInfoLayer->update(dt);
}

