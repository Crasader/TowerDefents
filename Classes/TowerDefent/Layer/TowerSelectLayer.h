#pragma once
#include "stdfax.h"
#include "TowerDefentShare.h"
#include "GridPos.h"
#include "Message\MessageListener.h"

class TowerSelectLayer : public Layer, MessageListener
{
public:
	TowerSelectLayer();
	~TowerSelectLayer();

	static TowerSelectLayer* create();
	virtual bool init();
	virtual void update(float dt);
	virtual void receive(const Message* message);

	void cancel();

private:
	enum ETowerSelectLayerState{
		UnShow,
		ShowFor_EmptyPos,
		ShowFor_TowerPos,
		ShowFor_SpellPos,
		ShowFor_BuildTower,
		ShowFor_BuildSpellPos,
		ShowFor_BuildSpellTower
	};
	ETowerSelectLayerState m_state;
	GridPos* m_gridPos;

	Layer* selectLayer;
	Sprite* bg_circle;		//����Ȧ
	Layer*  a_layer[9];		//��Χ��ť��
	Sprite* a_bt[9];		//��Χ��ť
	Sprite* a_bg[9];		//��Χ��ť�·���ʾ��Ϣ����
	Label* a_number[9];		//��Χ��ť�·���ʾ��Ϣ����
	CCostPlayer price[8];	//�۸�
	Sprite* bg_weaponRange;	//������ΧȦ


	void initSprite();
	void initListener();
	void hideAllButton();

	void show();
	void receiveMsg(Ref* pData);
	void showFor_EmptyPos(const NotificationMsg& msg);
	void showFor_TowerPos(const NotificationMsg& msg);
	void showFor_SpellPos(const NotificationMsg& msg);
	void showFor_BuildTower();
	void showFor_BuildSpellPos();
	void showFor_BuildSpellTower(const NotificationMsg& msg);

	bool onClick(Point pos);
	void clickEvent_showLayerFor_TowerInfo();
	void clickEvent_showLayerFor_BuildTower();
	void clickEvent_showLayerFor_BuildSpellPos();
	void clickEvent_buildTower(Direction dir);
	void clickEvent_buildSpellPos(Direction dir);
	void clickEvent_buildSpellTower(Direction dir);
	void clickEvent_sellTower();
	void clickEvent_sellSpellPos();
	void clickEvent_sellSpellTower();

	void updateMoney();

};
