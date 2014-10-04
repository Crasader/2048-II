#include "BricksPad.h"

IntegerVector::IntegerVector(int * ints, int len) {
	for (int i = 0; i < len; i++) {
		m_values.push_back(ints[i]);
	}
}

int IntegerVector::nextRandomInteger() {
	if (!m_values.empty()) {
		ssize_t randIdx = rand() % m_values.size();
		auto v = (m_values.begin() + randIdx);
		int retVal = *v;
		m_values.erase(v);
		return retVal;
	}
	return 0;
}

bool BricksPad::init() {
	if (!Node::init()) return false;

	for (int i = 0; i < 12; i++) {
		m_indexes[i] = i+1;
	}
	this->setAnchorPoint(Vec2(0.5f, 0.5f));

	addBricks();
	setTouchEnabled(true);
	registerTouchListener();

	return true;
}

void BricksPad::addBricks() {
	IntegerVector array(m_indexes, 12);

	Vec2 pos = FIRST_BRICK_POS - BRICK_PAD_POS;
	for (int i = 0; i < 4; i++)	{
		for (int j = 0; j < 3; j++) {
			m_bricks[i][j] = Brick::create();
			m_bricks[i][j]->retain();
			m_bricks[i][j]->setIndex(array.nextRandomInteger());
			m_bricks[i][j]->setPosition(pos.x + j*(BRICK_WIDTH + 4),
				pos.y - i*(BRICK_WIDTH + 4));
			this->addChild(m_bricks[i][j]);
		}
	}
}

void BricksPad::rearrange() {
	IntegerVector array(m_indexes, 12);

	for (int i = 0; i < 4; i++)	{
		for (int j = 0; j < 3; j++) {
			m_bricks[i][j]->setIndex(array.nextRandomInteger());
			m_bricks[i][j]->toOriginal();
		}
	}
}

void BricksPad::setTouchCallback(std::function<void(Brick *)> callback) {
	m_touchCallback = callback;
}

void BricksPad::setTouchEnabled(bool enable) {
	m_isTouchEnabled = enable;
}

void BricksPad::registerTouchListener() {
	auto l_lis = EventListenerTouchOneByOne::create();
	l_lis->onTouchBegan = [=](Touch* a_pt, Event* a_pe)->bool {
		if (this->m_isTouchEnabled) {
			for (auto l_node : this->getChildren()) {
				auto l_pos = l_node->convertTouchToNodeSpaceAR(a_pt);
				if (l_node->getBoundingBox().containsPoint(l_pos)) {
					auto l_brick = dynamic_cast<Brick *> (l_node);
					if (l_brick == nullptr) return false;
					if (m_touchCallback != NULL) {
						m_touchCallback(l_brick);
					}
				}
			}
		}
		return false;
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(l_lis, this);
}

void BricksPad::obscurePad() {
	auto outAct1 = ScaleTo::create(0.1f, 1.2f);
	auto outAct2 = ScaleTo::create(0.2f, 0.7f);
	auto outAct3 = ScaleTo::create(0.2f, 0.0f);
	auto calAct = CallFunc::create(std::bind(&BricksPad::rearrange, this));
	auto inAct1 = ScaleTo::create(0.2f, 0.7f);
	auto inAct2 = ScaleTo::create(0.2f, 1.2f);
	auto inAct3 = ScaleTo::create(0.1f, 1.0f);
	this->runAction(Sequence::create(outAct1, outAct2, outAct3, calAct, inAct1, inAct2, inAct3, NULL));
}