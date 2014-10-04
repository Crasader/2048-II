#pragma once

#include "AppMacro.h"
#include "Brick.h"

class MainScene : public Scene {
private:
	float m_startedTime;		// counting the time
	int m_currentScore;
	int m_currentNumber;
	ValueVector m_current_values;
	ValueVector m_current_operators;	// operators

	LabelAtlas* m_numberLbl;
	ImageView* m_tipSocketImg;
	ImageView* m_tipMaskImg;
	Text* m_tipPadTxt;
	LabelAtlas* m_resultLbl;
	Text* m_needTimeTxt;
	Text* m_timerTxt;

	ImageView* m_34TexturePad[4][3];	// bricks texture

	Vector<Brick *> m_bricksPadData;	// pad vector
private:
	void initBricksPadData();

	/**
		create game layer from json file via index of bg
	*/
	Layer* gameLayerWithBgIndex(int indexOfBg);
	
	/**
		calculate the next tip string
	*/
	std::string nextTipString(int nextCardValue);

	/**
		calculate the next need time string
	*/
	std::string nextNeedTimeString();

	/**
		
	*/
	float nextTimerSeconds();

	/**
		next card value
	*/
	int nextCardValue();

	/**
		go next time
	*/
	void next();

	/**
		re-arrange the 3*4 pad
	*/
	void rearrange34Pad();
protected:
	bool init(int indexOfBg);
public:
	static MainScene* create(int indexOfBg);
};