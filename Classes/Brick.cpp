#include "Brick.h"
#include "BrickTextureCache.h"

bool Brick::init() {
	if (!Node::init()) return false;

	m_type = kNone;
	m_value = 0;
	m_textureSpr = Sprite::create();
	m_textureSpr->retain();
	this->addChild(m_textureSpr);
	
	return true;
}

void Brick::setIndex(int index) {
	CCAssert(index >=0 && index <= 12, "image index must between 1 and 12");
	if (index >= 1 && index <= 9) {
		m_value = index;
		m_type = kNumber;
	} else if (index == 10) {
		m_type = kAdd;
	} else if (index == 11) {
		m_type = kSub;
	} else if (index == 12) {
		m_type = kIs;
	}
	auto key = StringUtils::format("element\\%d.png", index);
	m_textureSpr->setTexture(key);
}

Brick::Brick() {
	m_textureSpr = nullptr;
}

Brick::~Brick() {
	CC_SAFE_RELEASE(m_textureSpr);
}

Rect Brick::getBoundingBox() const {
	return m_textureSpr->getBoundingBox();
}

void Brick::disappearWithAnimation(float a_dt) {
	auto l_scale0 = ScaleTo::create(a_dt, 0.0f);
	auto l_rotate720 = RotateTo::create(a_dt, 720.0f);
	auto l_cal = CallFunc::create([=](){
		this->setVisible(false);
	});
	this->runAction(Sequence::create(Spawn::create(l_scale0, l_rotate720, NULL), l_cal, NULL));
}

void Brick::toOriginal() {
	this->setVisible(true);
	this->setScale(1.0f);
	this->setRotation(0.0f);
}

BrickType Brick::getBrickType() {
	return m_type;
}

int Brick::getValue() {
	return m_value;
}