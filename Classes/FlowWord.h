#pragma once

#include "AppMacro.h"

class FlowWord : public Label {
public:
	typedef enum {
		SCALE = 0,
		FLOW
	} EFFECT_TYPE;
private:
	float m_duration;
private:
	~FlowWord() {};
protected:
	virtual bool init(std::string a_word, float a_dt, Color3B a_color);
public:
	static FlowWord* create(std::string a_word, float a_dt, Color3B a_color = Color3B::RED);
	void flow(EFFECT_TYPE a_type, std::function<void(void)> a_callback);
};