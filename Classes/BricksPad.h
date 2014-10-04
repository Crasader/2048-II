#pragma once

#include "AppMacro.h"
#include "Brick.h"

class IntegerVector {
private:
	std::vector<int> m_values;
public:
	int nextRandomInteger();
	IntegerVector(int * ints, int len);
};

class BricksPad : public Node {
private:
	bool m_isTouchEnabled;
	Brick* m_bricks[4][3];

	int m_indexes[12];

	std::function<void(Brick *)> m_touchCallback;
private:
	void addBricks();
	void registerTouchListener();
protected:
	bool init();
public:
	CREATE_FUNC(BricksPad);
	void setTouchCallback(std::function<void(Brick *)> callback);
	void setTouchEnabled(bool);

	/**
		re-arrange the pad numbers
	*/
	void rearrange();

	/**
		show a effect that obscured the pad
	*/
	void obscurePad();
};