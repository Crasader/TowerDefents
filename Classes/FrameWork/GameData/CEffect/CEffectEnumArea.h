#pragma once
#include "CEffectResponse.h"

namespace cocosgalaxy
{
	class CEffectEnumArea : public CEffectResponse
	{
	public:
		CEffectEnumArea();
		CEffectEnumArea(unsigned int filter, int areaRadius, string applyEffect, CEffect* effect = nullptr, int parentID = -1);
		~CEffectEnumArea();

		virtual CEffect* clone();
		virtual void execute();

		int areaRadius;		//��Χ
		string applyEffect;	//Ӧ��Ч����
		CEffect* effect;	//Ӧ��Ч��
		Point m_pos;		//Ӧ������
	private:
	};
}
