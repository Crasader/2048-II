#pragma once

#include "AppMacro.h"

class MessageLayer : public Layer {
private:
	/**
		register handler
	*/
	void addListeners();

	/**
		pop game over message
	*/
	void popGameOverMsg();
protected:
	virtual bool init();
public:
	CREATE_FUNC(MessageLayer);
};