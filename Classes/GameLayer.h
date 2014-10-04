#pragma once

#include "AppMacro.h"
#include "BricksPad.h"
#include "Arithmetic.h"
#include "ValueCircle.h"

class GameLayer : public Layer {
private:
	BricksPad * m_pad;
	ValueCircle * m_circle;
	Text * m_needCountTxt;
	Text * m_needTimeTxt;
	TextAtlas * m_scoreLbl;
	Text * m_tipStringTxt;

	Arithmetic * m_model;

	bool m_stopped;
private:
	void addUiFromJsonFile();
	void addPad();
	void addCircle();
	void addModel();
	void addForeground(int indexOfFg);
	
	/**
		click handler
	*/
	void onClickBrick(Brick * a_brick);
	
	/**
		sub to the score and with a flow world effect
		@param int a_sub
	*/
	void subFlowScore(int a_sub);

	/**
		add to the score and with a flow world effect
		@param int a_add
	*/
	void addFlowScore(int a_add);

	/**
		next turn,
		if score is equal only 2048, you win
	*/
	void nextTurn();

	/**
		test the score
		if score <= 0 then game goes over
	*/
	bool gameGoingOver();

	/**
		stop all animations, all actions and game logic
	*/
	void stop();
protected:
	virtual bool init(int indexOfBg);
public:
	~GameLayer();
	static GameLayer* create(int indexOfBg);
};