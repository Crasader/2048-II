#include "StartScene.h"
#include "utf_text.h"
#include "3rd/CustomParticleWidget.h"
#include "3rd/CustomParticleWidgetReader.h"

using namespace std::placeholders;

bool StartScene::init() {
	if (!Scene::init()) return false;

	auto layer = startLayerWithJsonFile();
	this->addChild(layer);

	playAnimation();
	
	return true;
}

Layer* StartScene::startLayerWithJsonFile() {
	auto l_reader = GUIReader::getInstance();
	l_reader->registerTypeAndCallBack("CustomParticleWidget",
		&CustomParticleWidget::createInstance,
		CustomParticleWidgetReader::getInstance(),
		parseselector(CustomParticleWidgetReader::setProperties));

	// CustomParticleWidget* custom = CustomParticleWidget::create();
	// custom->setParticlePlist("Particles/BoilingFoam.plist");

	auto layer = Layer::create();
	auto ui = GUIReader::getInstance()->widgetFromJsonFile(RES__START_SCENE_JOSN_PATH);
	layer->addChild(ui);

	auto bgImg = (ImageView *)ui->getChildByName(RES__UI_START_NAMES__BGIMG);
	randomBgTexture(bgImg);

	auto startBtn = (Button *)ui->getChildByName(RES__UI_START_NAMES__STARTBTN);
	startBtn->addTouchEventListener(std::bind(&StartScene::onClick, this, _1, _2));

	auto settingBtn = (Button *)ui->getChildByName(RES__UI_START_NAMES__SETTINGBTN);
	settingBtn->addTouchEventListener(std::bind(&StartScene::onClick, this, _1, _2));

	auto sinaSharedBtn = (Button *)ui->getChildByName(RES__UI_START_NAMES__SINASHAREDBTN);
	sinaSharedBtn->addTouchEventListener(std::bind(&StartScene::onClick, this, _1, _2));

	auto wechatSharedBtn = (Button *)ui->getChildByName(RES__UI_START_NAMES__WECHATSHAREDBTN);
	wechatSharedBtn->addTouchEventListener(std::bind(&StartScene::onClick, this, _1, _2));

	auto scoreImgLayout = (ImageView *)ui->getChildByName(RES__UI_START_NAMES__SCOREIMG);
	auto scoreTxt = (Text *)scoreImgLayout->getChildByName(RES__UI_START_NAMES__SCORETXT);
	auto timeuseTxt = (Text *)scoreImgLayout->getChildByName(RES__UI_START_NAMES__TIMEUSETXT);
	auto scoreLbl = (Text *)scoreImgLayout->getChildByName(RES__UI_START_NAMES__SCORELBL);
	scoreTxt->setFontName(FONT_NAME);
	scoreTxt->setString(StringUtils::format("%d", this->loadLastestScore()));
	timeuseTxt->setFontName(FONT_NAME);
	timeuseTxt->setString(this->loadLastestTimeuseFormat());
	scoreLbl->setFontName(FONT_NAME);

	return layer;
}

void StartScene::onClick(Ref* sender, Widget::TouchEventType type) {
	if (type == Widget::TouchEventType::ENDED) {
		auto btn = static_cast<Button *> (sender);
		auto name = btn->getName();
		if (name == RES__UI_START_NAMES__STARTBTN) {
			// auto scene = TransitionSlideInR::create(GameScene::create(indexOfBg));
			// Director::getInstance()->replaceScene(scene);
			d_log_0("pressed start button");
		} else if (name == RES__UI_START_NAMES__SETTINGBTN) {
			// showSettingPage();
			d_log_0("pressed setting button");
		} else if (name == RES__UI_START_NAMES__SINASHAREDBTN) {
			// doShareBySinaWeibo();
			d_log_0("pressed sina shared button");
		} else {	// RES__UI_START_NAMES__WECHATSHAREDBTN
			// doShareByWechat();
			d_log_0("pressed wechat shared button");
		}
	}
}

void StartScene::randomBgTexture(ImageView * bgImg) {
	m_indexOfBg = rand()%1234567%24 + 1;
	bgImg->loadTexture(StringUtils::format("background/%d.jpg", m_indexOfBg));
}

int StartScene::loadLastestScore() {
	return UserDefault::getInstance()->getIntegerForKey(KEY__LASTEST_SCORE, 0);
}

std::string StartScene::loadLastestTimeuseFormat() {
	return UserDefault::getInstance()->getStringForKey(KEY__LASTEST_TIMEUSE, DEFAULT__LASTEST_TIMEUSE);
}

void StartScene::playAnimation() {
	m_startAni = ActionManagerEx::getInstance()->getActionByName(RES__START_SCENE_JOSN_PATH, RES_START_SCENE_JSON_ACTIONNAME);
	if (m_startAni) {
		m_startAni->play();
	}
}

void StartScene::stopAnimation() {
	m_startAni->stop();
	ActionManagerEx::getInstance()->releaseActions();
}
