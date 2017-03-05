#pragma once
#include "cocos2d.h"
#include <queue>


class LoadingScene : public cocos2d::Scene
{
public:
	LoadingScene();
	~LoadingScene();
	CREATE_FUNC(LoadingScene);
	static void replaceScene(LoadingScene* scene);

	virtual bool init();
	virtual void onEnterTransitionDidFinish();

	typedef std::function<void()> LoadingCallback;

	/*��ʼ������Դʱ��Ҫ���еĻص�*/
	void bindBeginFunction(LoadingCallback callback);

	/*�ڼ��ع�������Ҫ���еĻص�(ÿ����һ����Դ�ص�һ��)*/
	void bindLoadFunction(LoadingCallback callback);

	/*ȫ��������Ϻ���Ҫ���еĻص�*/
	void bindFinishFunction(LoadingCallback callback);

	/*������Ҫ�첽���ص�texture���б�*/
	void setTextureLoadList(std::queue<std::string> list);

	/*������Ҫ�첽���ص�plist���б�*/
	void setPlistLoadList(std::queue<std::string> list);

	/*������Ҫ���ص�audio���б�*/
	void setAudioLoadList(std::queue<std::string> list);

	/*������Ҫ�����lambda���б�*/
	void setLambdaLoadList(std::queue<LoadingCallback> list);

	/*
	�����Զ���ʼ������Դ
	Ĭ�Ͽ���
	*/
	void setAutoStartLoad(bool isAuto);

	/*��ȡ��Ҫ���ص���Դ����*/
	int getResCount();

	/*��ȡ�Ѽ��ص���Դ����*/
	int getLoadedCount();

	/*��ȡ���ؽ���*/
	float getLoadingProgress();

	/*
	�洢��ʱ����
	ע�⣺lambda�����в���ʹ��ǰһ�����еľֲ�������
	��Ϊ�������ڼ���;�б��ͷţ���˱��뽫���ݴ���buff data
	*/
	void setData(cocos2d::ValueMap data);

	/*
	��ȡ��ʱ����
	ע�⣺lambda�����в���ʹ��ǰһ�����еľֲ�������
	��Ϊ�������ڼ���;�б��ͷţ���˱��뽫���ݴ���buff data
	*/
	cocos2d::ValueMap getData();



	/*
	��ʼ������Դ
	Ĭ��ʱ��onEnterTransitionDidFinish�У�replaceScene���Զ���ʼ����
	*/
	void start();			

private:
	void doLoad(float dt);

	virtual void update(float dt);

	void callback_texture(cocos2d::Texture2D *texture);
	void callback_plist(cocos2d::Texture2D *texture);
	void callback_lambda();
	void callback_audio();

private:
	bool isLoading;
	bool isAutoStartLoad;

	int resCount;
	int loadedCount;

	cocos2d::ValueMap buffData;	// ��ʱ������ת,����ǰһ�����ı�Ҫ���ݣ�������һ�����ĳ�ʼ��

	LoadingCallback onBegan;	
	LoadingCallback onLoad;
	LoadingCallback onFinish;	

	std::queue<LoadingCallback> q_lambda;
	std::queue<std::string> q_texture;
	std::queue<std::string> q_plist;
	std::queue<std::string> q_audio;

};
