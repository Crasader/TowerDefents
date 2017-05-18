#pragma once
#include "GridView.h"

NS_CC_BEGIN
namespace ui {
	class GridScrollView :
		public GridView,
		public cocos2d::ui::ScrollView
	{
	public:
		GridScrollView();
		~GridScrollView();

		static GridScrollView* create(const Size& viewsize, const Size& itemsize, GridView::Direction direction);
		virtual bool init(
			const Size& viewsize,
			const Size& itemsize = Size(100, 100),
			GridView::Direction direction = GridView::Direction::VERTICAL);

		/*����һ��item*/
		virtual void addItem(GridItem* item);

		/*����Item*/
		virtual void insertItem(int index, GridItem* item);

		/*ȡitem*/
		virtual GridItem* getItem(int index);

		/*ɾ��item*/
		virtual void removeItem(int index);

		/*����ÿ��item�Ĵ�С*/
		virtual void setItemSize(const Size& itemsize);

		/*�����ڱ߾�*/
		virtual void setPadding(const Padding& padding);

		/*���ù�������*/
		virtual void setDirection(GridView::Direction direction);

		/*����֮��ļ��*/
		virtual void setSpacing(float horizontalSpacing, float verticalSpacing);

		/*ˢ��girdλ��*/
		void resetInnerSize();

		/*��ȡitem����*/
		virtual int getItemCounnt();

	protected:
		Layout* m_page;
		Vector<GridItem*> m_Items;

		Point clickpos;
		bool isMoved;
		Size m_itemSize;
		int m_numColumns, m_numRows;
		Padding m_padding;
		float horizontalSpacing, verticalSpacing;

		virtual void onSizeChanged() override;
		virtual void setItemPosition(int index, GridItem* item);

		virtual bool onTouchBegan(Touch* touch, Event* event);
		virtual void onTouchMoved(Touch* touch, Event* event);
		virtual void onTouchEnded(Touch* touch, Event* event);
		virtual void onTouchCancelled(Touch* touch, Event* event);

	};
}


NS_CC_END