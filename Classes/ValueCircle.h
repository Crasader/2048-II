#pragma once

#include "AppMacro.h"

class ValueCircle : public Node {
private:
	ImageView *m_valueSocketImg;
	ImageView *m_valueMaskImg;
	TextAtlas *m_numberLbl;
protected:
	virtual bool init(int a_originalValue);
	void addComponents();
public:
	static ValueCircle* create(int a_originalValue);

	/**
		show a effect that obscured the pad
		it will call set the value to m_numberLbl
	*/
	void obscureCircle(int a_value);

	/**
		let mast image run a circle action in a_dt time
		@param float a_dt
	*/
	void runCircleAction(float a_dt);
};