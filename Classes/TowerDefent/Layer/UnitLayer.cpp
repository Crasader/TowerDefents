#include "UnitLayer.h"
#include "UnitManager.h"

UnitLayer::UnitLayer()
{
}

UnitLayer* UnitLayer::create()
{
	UnitLayer* layer = new UnitLayer();
	if (layer && layer->init())
	{
		layer->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(layer);
	}
	return layer;
}

bool UnitLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	bool flag = false;
	do{
		this->setAnchorPoint(Point::ZERO);
		//����UI
		//auto UI = GUIReader::getInstance()->widgetFromJsonFile("Editor/ui_Editor.ExportJson");
		//this->addChild(UI);

		//�ر�UI����
		//UI->setTouchEnabled(false);

		//��ȡUI�еĿؼ�
		//auto bt_output = (Button*)GalaxyHelper::seekWidgetByName(UI, "btn_output");

		//��Ӽ���
		//Button* bt_output = new Button();
		//bt_output->addTouchEventListener(this, toucheventselector(UnitTouchLayer::bt_output_onClick));

		//���ü���
		auto listener = EventListenerTouchOneByOne::create();
		listener->onTouchBegan = [](Touch* touch, Event* event){
			return true;
		};

		listener->onTouchEnded = [&](Touch* touch, Event* event){
			Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
			pos = pos / Director::getInstance()->getContentScaleFactor();
			if (onClick(pos))
			{
				event->stopPropagation();

			}

		};
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);



		flag = true;
	} while (0);

	return flag;
}

void UnitLayer::update(float dt){

}

bool UnitLayer::onClick(Point pos)
{

	vector<CUnit*> vec = UnitManager::getInstance()->findUnit(EUnitType::Unit_Unit);
	for (auto obj : vec)
	{
		if (obj->isClickMe(pos))
		{
			obj->onClick();
			return true;

		}
	}
	return false;
}




