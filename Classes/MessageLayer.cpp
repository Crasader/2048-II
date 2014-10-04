#include "MessageLayer.h"

void MessageLayer::addListeners() {
	this->getEventDispatcher()->addCustomEventListener(MSG__GAME_OVER, [=](EventCustom* a_pE){
		popGameOverMsg();
	});
}

void MessageLayer::popGameOverMsg() {
	
}

bool MessageLayer::init() {
	if (!Layer::init()) return false;

	addListeners();

	return true;
}

