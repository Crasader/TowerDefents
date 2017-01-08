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
		int ID;

		CActor();
		CActor(int id, ActorData data, Layer* parent);
		~CActor();

		CActor* clone();
		void bindSprite(Layer* parent);

		void setPos(Point pos);
		void setRotation(float rotation);
		void setDefaultAnimate(const Name& defaultAnimate);
		void setAnimateList(std::map<Name, Name> animateList);

		/*�����Ƿ���ʾѪ����Ĭ�ϲ���ʾ*/
		void setShowHpBar(bool isShow, Point pos = Point::ZERO, Size size = Size::ZERO);
		/*����Ѫ���ٷֱ� [0,1]*/
		void setHpBarProgress(float progress);
		/*�����Ƿ���ʾռλ����*/
		void setShowUnitPos(bool isShow);

		void playDefaultAnimate();
		void playAction(const Name& actionName, float playtime = 0, Color3B color = Color3B::WHITE);
		void playEffect(const Name& animateName, float playtime = 0, Color3B color = Color3B::WHITE, Point offset = Point::ZERO, int localZOrder = 1);

		void remove();

		enum Face : int{ FACE_TO_LEFT, FACE_TO_RIGHT };
		void changeFace(Face face);

		bool IsExistAnimate(const Name& animateName);
	private:
		Layer* m_layer;
		Point m_pos;
		Layer* m_parent;

		Face m_face;
		Sprite* m_sprite;
		cocos2d::ui::Scale9Sprite* m_hpBar;
		Sprite* m_unitPos;

		Name m_defaultAnimate;
		std::map<Name, Name> m_animateList;


	};

}