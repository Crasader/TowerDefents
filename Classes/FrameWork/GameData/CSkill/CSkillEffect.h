#pragma once
#include "CSkillGeneric.h"



namespace cocosgalaxy
{
	class CSkillEffect : public CSkillGeneric
	{
	public:

		/*��ȴʱ��*/
		float ColdDown;
		/*��ȴʱ��ʣ��*/
		float ColdDowning;

		/*
			��
			�ӽ��贈������
			��
			׼���贈������׼������/Ч��
			��׼��ʱ��
			ǰҡ�贈������ǰҡ����
			��ǰҡʱ��
			ʩ�ũ贈������ʩ�Ŷ���/Ч��
			������ʱ��
			��ҡ�贈��������ҡ����/Ч��
			����ҡʱ��
			��ȴ�贈������
			��CDʱ��

			*/

		/*׼������*/
		string preparing_Animate;
		/*ǰҡ����*/
		string beforing_Animate;
		/*ʩ�Ŷ���*/
		string using_Animate;
		/*��ҡ����*/
		string aftering_Animate;

		/*׼��Ч��*/
		string preparing_Effect;
		/*ʩ��Ч��*/
		string using_Effect;
		/*����Ч��*/
		string aftering_Effect;

		/*׼��ʱ��*/
		float preparing_Delay;
		/*ǰҡʱ��*/
		float beforing_Delay;
		/*����ʱ��*/
		float using_Delay;
		/*��ҡʱ��*/
		float aftering_Delay;


		/* ----����---- */
		CSkillEffect();
		~CSkillEffect();

		virtual void update(float dt);
		virtual bool IsCanExecute();

	};
}
