#include "FlowWord.h"

FlowWord* FlowWord::create(std::string a_word, float a_dt, Color3B a_color /* = Color3B::RED */) {
	auto l_word = new FlowWord();
	if (l_word && l_word->init(a_word, a_dt, a_color)) {
		l_word->autorelease();
		return l_word;
	}
	CC_SAFE_DELETE(l_word);
	return nullptr;
}

bool FlowWord::init(std::string a_word, float a_dt, Color3B a_color) {
	if (!Label::init()) return false;

	this->setString(a_word);
	this->setSystemFontName(FONT_NAME);
	this->setSystemFontSize(20);
	this->setColor(a_color);
	this->m_duration = a_dt;

	return true;
}

void FlowWord::flow(EFFECT_TYPE a_type, std::function<void(void)> a_callback) {
	FiniteTimeAction *l_cal = CallFunc::create([=](){
		CCAssert(this->getParent() != nullptr, "_parent cannot be null");
		this->removeFromParent();
		if (a_callback != NULL) {
			a_callback();
		}
	});
	FiniteTimeAction *l_act = nullptr;
	auto l_fade = FadeTo::create(1.0f, 0);
	if (a_type == EFFECT_TYPE::SCALE) {
		auto l_scale = ScaleTo::create(1.0f, 2.0f);
		l_act = Spawn::create(l_scale, l_fade, NULL);
	} else {
		auto l_move = MoveBy::create(1.0f, Vec2(0, 20));
		l_act = Spawn::create(l_move, l_fade, NULL);
	}
	this->runAction(Sequence::create(l_act, l_cal, NULL));
}
