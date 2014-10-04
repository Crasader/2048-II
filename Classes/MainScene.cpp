#include "MainScene.h"

MainScene* MainScene::create(int indexOfBg) {
	auto s = new MainScene();
	if (s && s->init(indexOfBg)) {
		s->autorelease();
		return s;
	}
	CC_SAFE_DELETE(s);
	return s;
}

bool MainScene::init(int indexOfBg) {
	if (!Scene::init()) return false;

	auto layer = gameLayerWithBgIndex(indexOfBg);

	return true;
}

Layer* MainScene::gameLayerWithBgIndex(int indexOfBg) {
	auto layer = Layer::create();
	auto ui = GUIReader::getInstance()->widgetFromJsonFile(RES__MAIN_SCENE_JOSN_PATH);
	layer->addChild(ui);
	/*
	auto bgImg = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__BGIMG);
	bgImg->loadTexture(StringUtils::format("background/%d.jpg", indexOfBg));

	m_tipSocketImg = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__TIPSOCKETIMG);
	m_numberLbl = (LabelAtlas *)m_tipSocketImg->getChildByName(RES__UI_MAIN_NAMES__NUMBERLBL);
	m_tipMaskImg = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__TIPMASKIMG);
	
	m_tipPadTxt = (Text *)ui->getChildByName(RES__UI_MAIN_NAMES__TIPPADTXT);
	m_tipPadTxt->setFontName(FONT_NAME);
	
	m_resultLbl = (LabelAtlas *)ui->getChildByName(RES__UI_MAIN_NAMES__RESULTLBL);
	m_resultLbl->setString(DEFAULT_SCORE);

	m_needTimeTxt = (Text *)ui->getChildByName(RES__UI_MAIN_NAMES__NEEDTIMETXT);
	m_needTimeTxt->setFontName(FONT_NAME);

	m_timerTxt = (Text *)ui->getChildByName(RES__UI_MAIN_NAMES__TIMERTXT);
	m_timerTxt->setFontName(FONT_NAME);

	m_34TexturePad[0][0] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS1IMG);
	m_34TexturePad[0][1] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS2IMG);
	m_34TexturePad[0][2] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS3IMG);
	m_34TexturePad[1][0] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS4IMG);
	m_34TexturePad[1][1] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS5IMG);
	m_34TexturePad[1][2] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS6IMG);
	m_34TexturePad[2][0] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS7IMG);
	m_34TexturePad[2][1] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS8IMG);
	m_34TexturePad[2][2] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS9IMG);
	m_34TexturePad[3][0] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS10IMG);
	m_34TexturePad[3][1] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS11IMG);
	m_34TexturePad[3][2] = (ImageView *)ui->getChildByName(RES__UI_MAIN_NAMES__POS12IMG);
	*/
	return layer;
}

std::string MainScene::nextTipString(int nextCardValue) {
	std::string tip;
	switch (nextCardValue) {
		case 1: {
			int i = rand()%10;
			if (i==0) {
				tip = StringUtils::format("? = %d", nextCardValue);
			} else if (i>0 && i<6) {
				tip = StringUtils::format("", nextCardValue);
			} else if (i>5) {
				
			}
		} break;
		case 2: {

		} break;
		case 3: {

		} break;
		case 4: {

		} break;
		case 5: {

		} break;
		case 6: {

		} break;
		case 7: {

		} break;
		case 8: {

		} break;
		case 9: {

		} break;
		default:
			break;
	}
	return "";
}

void MainScene::rearrange34Pad() {

}

void MainScene::initBricksPadData() {
	
}