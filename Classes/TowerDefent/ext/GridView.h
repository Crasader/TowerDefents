#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio\CocoStudio.h"
#include "GridItem.h"

NS_CC_BEGIN
namespace ui {
	class Padding
	{
	public:
		Padding();
		Padding(float top, float left);
		Padding(float top, float left, float right, float bottom);
		~Padding();

		float top, left, right, bottom;
		static const Padding ZERO;
	};



	class GridView
	{
	public:
		GridView();
		~GridView();

		enum class Direction
		{
			VERTICAL,
			HORIZONTAL,
		};


		/*����һ��item*/
		virtual void addItem(GridItem* item) = 0;

		/*����Item*/
		virtual void insertItem(int index, GridItem* item) = 0;

		/*ȡitem*/
		virtual GridItem* getItem(int index) = 0;

		/*����ÿ��item�Ĵ�С*/
		virtual void setItemSize(const Size& itemsize) = 0;

		/*�����ڱ߾�*/
		virtual void setPadding(const Padding& padding) = 0;

		/*���ù�������*/
		virtual void setDirection(GridView::Direction direction) = 0;

		/*����֮��ļ��*/
		virtual void setSpacing(float horizontalSpacing, float verticalSpacing) = 0;

	protected:
		virtual void onSizeChanged() = 0;
		virtual void setItemPosition(int index, GridItem* item) = 0;

		virtual bool onTouchBegan(Touch* touch, Event* event) = 0;
		virtual void onTouchMoved(Touch* touch, Event* event) = 0;
		virtual void onTouchEnded(Touch* touch, Event* event) = 0;
		virtual void onTouchCancelled(Touch* touch, Event* event) = 0;


	};
}
NS_CC_END