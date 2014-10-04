#include "ValueCircle.h"
#include "Resources.h"

bool ValueCircle::init(int a_originalValue) {
	if (!Node::init()) return false;

	addComponents();
	auto l_value = StringUtils::format("%d", a_originalValue);
	m_numberLbl->setProperty(l_value, "GUI/labelatlasimg.png", 24, 32, "");
	
	return true;
}

void ValueCircle::obscureCircle(int a_value) {
	auto l_scaleHalf = ScaleTo::create(0.5f, 0, 1);
	auto l_cal = CallFunc::create([=](){
		this->m_numberLbl->setString(StringUtils::format("%d", a_value));
	});
	auto l_scaleHalf_rev = ScaleTo::create(0.5f, 1, 1);
	this->runAction(Sequence::create(l_scaleHalf, l_cal, l_scaleHalf_rev, NULL));
}

void ValueCircle::runCircleAction(float a_dt) {
	m_valueMaskImg->stopAllActions();
	auto l_rotate = RotateBy::create(a_dt, a_dt * CIRCLE_ROTATE_SPEED);
	m_valueMaskImg->runAction(l_rotate);
}

void ValueCircle::addComponents() {
	m_valueSocketImg = ImageView::create(MAIN_SCENE__VALUE_SOCKET_IMG);
	m_valueMaskImg = ImageView::create(MAIN_SCENE__VALUE_MASK_IMG);
	m_numberLbl = TextAtlas::create();

	m_valueSocketImg->setPosition(Vec2::ZERO);
	m_valueMaskImg->setPosition(Vec2::ZERO);
	m_numberLbl->setPosition(Vec2::ZERO);

	this->addChild(m_valueSocketImg);
	this->addChild(m_numberLbl);
	this->addChild(m_valueMaskImg);
}

ValueCircle* ValueCircle::create(int a_originalValue) {
	auto l_circle = new ValueCircle();
	if (l_circle && l_circle->init(a_originalValue)) {
		l_circle->autorelease();
		return l_circle;
	}
	CC_SAFE_DELETE(l_circle);
	return nullptr;
}
