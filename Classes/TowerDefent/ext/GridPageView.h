#pragma once
#include "GridView.h"


NS_CC_BEGIN
namespace ui {
	class GridPageView :
		public GridView,
		public cocos2d::ui::PageView
	{
	public:
		GridPageView();
		~GridPageView();

		static GridPageView* create(const Size& viewsize, const Size& itemsize, GridView::Direction direction);
		virtual bool init(
			const Size& viewsize,
			const Size& itemsize = Size(100, 100),
			GridView::Direction direction = GridView::Direction::HORIZONTAL);

		/*����һ��item*/
		virtual void addItem(GridItem* item);

		/*����Item*/
		virtual void insertItem(int index, GridItem* item);

		/*ȡitem*/
		virtual GridItem* getItem(int index);

		/*����ÿ��item�Ĵ�С*/
		virtual void setItemSize(const Size& itemsize);

		/*�����ڱ߾�*/
		virtual void setPadding(const Padding& padding);

		/*���ù�������*/
		virtual void setDirection(GridView::Direction direction);

		/*����֮��ļ��*/
		virtual void setSpacing(float horizontalSpacing, float verticalSpacing);

	protected:
		Vector<Layout*> m_pages;
		Vector<GridItem*> m_Items;

		bool isMoved;
		Size m_itemSize;
		int m_numColumns, m_numRows;
		Padding m_padding;
		float horizontalSpacing, verticalSpacing;

		virtual void onSizeChanged() override;
		virtual void doLayout() override;
		void updateAllPagesPosition();

		virtual void setItemPosition(int index, GridItem* item);

		virtual bool onTouchBegan(Touch* touch, Event* event);
		virtual void onTouchMoved(Touch* touch, Event* event);
		virtual void onTouchEnded(Touch* touch, Event* event);
		virtual void onTouchCancelled(Touch* touch, Event* event);


	};
}
NS_CC_END