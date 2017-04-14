#pragma once
#include "GalaxyBase.h"
#include "CGameData.h"

namespace cocosgalaxy
{

	struct ActorData{
		std::string defaultanimate = "";
		std::map<Name, Name> maps;
	};


	class CActor : public CGameData
	{
	public:

		CActor();
		CActor(int id, ActorData data, Layer* parent);
		~CActor();

		CActor* clone();
		void bindSprite(Layer* parent);

		void setPos(Point pos);
		void setRotation(float rotation);
		void setDefaultAnimate(const Name& defaultAnimate);
		void setAnimateList(std::map<Name, Name> animateList);
		/*������ʾ�㼶��Խ�߾���Խ����*/
		void setLocalLevel(int level);

		/*�����Ƿ���ʾѪ����Ĭ�ϲ���ʾ*/
		void setShowHpBar(bool isShow, Rect rect = Rect::ZERO);
		/*����Ѫ���ٷֱ� [0,1]*/
		void setHpBarProgress(float progress);
		/*�����Ƿ���ʾռλ����*/
		void setShowUnitPos(bool isShow);

		void playDefaultAnimate();
		void playAction(const Name& actionName, float playtime = 0, Color3B color = Color3B::WHITE);
		void playEffect(const Name& animateName, float playtime = 0, Color3B color = Color3B::WHITE, Point offset = Point::ZERO, int localZOrder = 1, int tag = 0);

		void remove();
		void removeEffect(const Name& animateName, int tag = 0);

		enum Face : int{ FACE_TO_LEFT, FACE_TO_RIGHT };
		void changeFace(Face face);

		bool IsExistAnimate(const Name& animateName);
	private:
		Point m_pos;
		Layer* m_layer;
		Layer* m_parent;
		Layer* m_spriteLayer;
		int LocalLevel;

		Face m_face;
		Sprite* m_sprite;
		Sprite* m_unitPos;
		cocos2d::ui::Scale9Sprite* m_hpBar;
		Rect hpbarRect;

		Name m_defaultAnimate;
		std::map<Name, Name> m_animateList;
		std::map<Name, Sprite*> m_effectList;

	};

}