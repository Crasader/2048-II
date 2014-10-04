#pragma once

#include "AppMacro.h"

class StartScene : public Scene {
private:
	/**
		Index of background like 1,2,3...
	*/
	int m_indexOfBg;
	ActionObject * m_startAni;
private:
	Layer* startLayerWithJsonFile();

	/*
		randomize a index to indexOfBg and load the [index].png 
		then set it as the texture of param bgImg
	*/
	void randomBgTexture(ImageView * bgImg);

	/**
		click event handler
	*/
	void onClick(Ref* sender, Widget::TouchEventType type);

	/**
		load lastest score by UserDefault
	*/
	int loadLastestScore();

	/**
		load lastest timeuse formatted[01' 22'' 33''] by UserDefault
	*/
	std::string loadLastestTimeuseFormat();

	/**
		play the cocostudio ui animation
	*/
	void playAnimation();
	void stopAnimation();
protected:
	virtual bool init();
public:
	CREATE_FUNC(StartScene);
};