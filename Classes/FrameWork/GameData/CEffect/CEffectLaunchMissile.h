#pragma once
#include "CEffectResponse.h"

namespace cocosgalaxy
{
	class CEffectLaunchMissile : public CEffectResponse
	{
	public:
		CEffectLaunchMissile();
		CEffectLaunchMissile(string className, string typeName);
		~CEffectLaunchMissile();

		virtual CEffect* clone();
		virtual void execute();

		string className;	//����
		string typeName;	//�����ǩ(����)
	private:
	};
}
