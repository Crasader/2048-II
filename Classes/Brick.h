#pragma once

#include "AppMacro.h"

typedef enum {
	kNumber = 0,	// number	1-9
	kAdd,			// add		+
	kSub,			// sub		-
	kIs,			// is		=
	kNone
} BrickType;

class Brick : public Node {
private:
	Sprite* m_textureSpr;
	BrickType m_type;
	int m_value;	// 1-9
protected:
	bool init();
public:
	CREATE_FUNC(Brick);
	Brick();
	~Brick();

	/**
		set the index of value between 1-12
		@param index
	*/
	void setIndex(int index);

	/**
		override the bounding box method by calling the m_textureSpr.getBoundingBox()
	*/
	Rect getBoundingBox() const override;

	/**
		scale and rotate to none
		@param float dt the duration for this action
	*/
	void disappearWithAnimation(float dt);

	/**
		the reverse action of @disappearWithAnimation,
		but there is no animation
	*/
	void toOriginal();

	/**
		getter of m_type
		@return BrickType
	*/
	BrickType getBrickType();

	/**
		getter of m_value, if BrickType is not kNumber, it will be -1
		@return int
	*/
	int getValue();
};