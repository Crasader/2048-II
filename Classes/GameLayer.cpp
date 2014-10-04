#include "GameLayer.h"
#include "FlowWord.h"

GameLayer* GameLayer::create(int indexOfBg) {
	auto l = new GameLayer();
	if (l && l->init(indexOfBg)) {
		l->autorelease();
		return l;
	}
	CC_SAFE_DELETE(l);
	return nullptr;
}

GameLayer::~GameLayer() {
	CC_SAFE_RELEASE(m_model);
}

bool GameLayer::init(int indexOfBg) {
	if (!Layer::init()) return false;

	addModel();

	addUiFromJsonFile();
	addPad();
	addCircle();
	addForeground(indexOfBg);

	m_stopped = false;

	return true;
}

void GameLayer::addUiFromJsonFile() {
	auto ui = GUIReader::getInstance()->widgetFromJsonFile(RES__MAIN_SCENE_JOSN_PATH);
	this->addChild(ui);

	m_tipStringTxt = (Text *)ui->getChildByName(RES__UI_MAIN_NAMES__TIPSTRINGTXT);
	m_tipStringTxt->setFontName(FONT_NAME);
	
	m_scoreLbl = (TextAtlas *)ui->getChildByName(RES__UI_MAIN_NAMES__SCORELBL);
	m_scoreLbl->setString(DEFAULT_SCORE);

	m_needTimeTxt = (Text *)ui->getChildByName(RES__UI_MAIN_NAMES__NEEDTIMETXT);
	m_needTimeTxt->setFontName(FONT_NAME);

	m_needCountTxt= (Text *)ui->getChildByName(RES__UI_MAIN_NAMES__NEEDCOUNTTXT);
	m_needCountTxt->setFontName(FONT_NAME);
}

void GameLayer::addPad() {
	m_pad = BricksPad::create();
	m_pad->setPosition(BRICK_PAD_POS);
	m_pad->setTouchCallback(std::bind(&GameLayer::onClickBrick, this, std::placeholders::_1));
	this->addChild(m_pad);
}

void GameLayer::addModel() {
	m_model = new Arithmetic();
}

void GameLayer::addFlowScore( int a_add ) {
	auto l_word = FlowWord::create(StringUtils::format("+%d", a_add), 0.5f, Color3B::GREEN);
	l_word->flow(FlowWord::EFFECT_TYPE::FLOW, [=](){
		auto l_score = StringUtils::format("%d", this->m_model->getCurrentScore());
		this->m_scoreLbl->setString(l_score);
	});
	l_word->setPosition(m_scoreLbl->getPosition() + Vec2(70, 0));
	this->addChild(l_word);
}

void GameLayer::subFlowScore( int a_sub ) {
	auto l_word = FlowWord::create(StringUtils::format("-%d", a_sub), 0.5f);
	l_word->flow(FlowWord::EFFECT_TYPE::FLOW, [=](){
		auto l_score = StringUtils::format("%d", this->m_model->getCurrentScore());
		this->m_scoreLbl->setString(l_score);
	});
	l_word->setPosition(m_scoreLbl->getPosition() + Vec2(70, 0));
	this->addChild(l_word);
}

void GameLayer::addForeground(int indexOfFg) {
	auto l_foreground = ImageView::create();
	l_foreground->loadTexture(StringUtils::format("background/%d.jpg", indexOfFg));
	l_foreground->setOpacity(100);
	l_foreground->setAnchorPoint(Vec2::ZERO);
	this->addChild(l_foreground);
}

void GameLayer::onClickBrick(Brick * a_brick) {
	if (m_stopped) return;	// if stopped  then no touch

	bool l_operateSuccess = false;
	switch (a_brick->getBrickType()) {
	case BrickType::kAdd: {
		l_operateSuccess = this->m_model->addOperator(ADD_CHAR_OPERATER);
	} break;
	case BrickType::kIs: {
		l_operateSuccess = this->m_model->doResult();
		if (l_operateSuccess) {
			this->addFlowScore(this->m_model->getThisValue());
			this->nextTurn();
		}
	} break;
	case BrickType::kNumber: {
		l_operateSuccess = this->m_model->addNumber(a_brick->getValue());
							 } break;
	case BrickType::kSub: {
		l_operateSuccess = this->m_model->addOperator(SUB_CHAR_OPERATER);
	} break;
	default:
		break;
	}

	if (l_operateSuccess) {
		a_brick->disappearWithAnimation(0.5f);
	} else {	// if false then sub the score
		this->subFlowScore(this->m_model->getThisValue());
		this->nextTurn();
	}
}

void GameLayer::addCircle() {
	m_circle = ValueCircle::create(m_model->getThisValue());
	m_circle->setPosition(CIRCLE_POSITION);
	this->addChild(m_circle);
}

void GameLayer::nextTurn() {
	if (!gameGoingOver()) {
		m_model->reset();
		m_circle->obscureCircle(m_model->nextValue());
		m_pad->obscurePad();
		m_tipStringTxt->setString(m_model->tipString());
		m_needCountTxt->setString(StringUtils::format("%d", m_model->needCount()));
		m_needTimeTxt->setString(StringUtils::format("need %0.3f", m_model->needTime()));
	} else {
		this->getEventDispatcher()->dispatchCustomEvent(MSG__GAME_OVER);
		this->stop();
	}
}

bool GameLayer::gameGoingOver() {
	if (m_model->getCurrentScore() <= 0) {
		return true;
	}
	return false;
}

void GameLayer::stop() {
	m_stopped = true;
}
