#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace ui;


#define FONT_NAME "Î¢ÈíÑÅºÚ"

#define VSIZE Size(320, 480)

#define DEFAULT_SCORE "20"
#define DEFAULT_SCORE_VALUE 20

#define BRICK_WIDTH 64
#define FIRST_BRICK_POS Vec2(92, 255)
#define BRICK_PAD_POS Vec2(160, 154)

/**
	Resource macros
*/
#define RES__START_SCENE_JOSN_PATH "ui_start.json"
#define RES__MAIN_SCENE_JOSN_PATH "ui_main.json"

#define RES_START_SCENE_JSON_ACTIONNAME "start_ani"

#define RES__UI_START_NAMES__BGIMG "bgImg"
#define RES__UI_START_NAMES__STARTBTN "startBtn"
#define RES__UI_START_NAMES__SETTINGBTN "settingBtn"
#define RES__UI_START_NAMES__SINASHAREDBTN "sinaSharedBtn"
#define RES__UI_START_NAMES__WECHATSHAREDBTN "wechatSharedBtn"
#define RES__UI_START_NAMES__SCOREIMG "scoreImg"
#define RES__UI_START_NAMES__SCORELBL "scoreLbl"
#define RES__UI_START_NAMES__SCORETXT "scoreTxt"
#define RES__UI_START_NAMES__TIMEUSETXT "timeuseTxt"

#define RES__UI_MAIN_NAMES__POS1IMG "pos1Img"
#define RES__UI_MAIN_NAMES__POS2IMG "pos2Img"
#define RES__UI_MAIN_NAMES__POS3IMG "pos3Img"
#define RES__UI_MAIN_NAMES__POS4IMG "pos4Img"
#define RES__UI_MAIN_NAMES__POS5IMG "pos5Img"
#define RES__UI_MAIN_NAMES__POS6IMG "pos6Img"
#define RES__UI_MAIN_NAMES__POS7IMG "pos7Img"
#define RES__UI_MAIN_NAMES__POS8IMG "pos8Img"
#define RES__UI_MAIN_NAMES__POS9IMG "pos9Img"
#define RES__UI_MAIN_NAMES__POS10IMG "pos10Img"
#define RES__UI_MAIN_NAMES__POS11IMG "pos11Img"
#define RES__UI_MAIN_NAMES__POS12IMG "pos12Img"
#define RES__UI_MAIN_NAMES__SCORELBL "scoreLbl"
#define RES__UI_MAIN_NAMES__NEEDCOUNTTXT "needCountTxt"
#define RES__UI_MAIN_NAMES__NEEDTIMETXT "needTimeTxt"
#define RES__UI_MAIN_NAMES__TIPSTRINGTXT "tipStringTxt"
#define RES__UI_MAIN_NAMES__BGIMG "bgImg"
#define RES__UI_MAIN_NAMES__CARDPNL "cardPnl"
#define RES__UI_MAIN_NAMES__VALUESOCKETIMG "valueSocketImg"
#define RES__UI_MAIN_NAMES__NUMBERLBL "numberLbl"
#define RES__UI_MAIN_NAMES__VALUEMASKIMG "valueMaskImg"

/**
	brick macro
*/
#define BRICK_1 "element\1.png"
#define BRICK_2 "element\2.png"
#define BRICK_3 "element\3.png"
#define BRICK_4 "element\4.png"
#define BRICK_5 "element\5.png"
#define BRICK_6 "element\6.png"
#define BRICK_7 "element\7.png"
#define BRICK_8 "element\8.png"
#define BRICK_9 "element\9.png"
#define BRICK_10 "element\+.png"
#define BRICK_11 "element\-.png"
#define BRICK_12 "element\=.png"

/**
	log function
*/
#ifndef __debug_mode_
#define __debug_mode_ true
#endif // !__debug_mode_

#define d_log(format, ...) if (__debug_mode_) {log(format, ...);}
#define d_log_0(format) if (__debug_mode_) {log(format);}

/**
	score macros
*/
#define KEY__LASTEST_SCORE "LASTEST_SCORE"
#define KEY__LASTEST_TIMEUSE "LASTEST_TIMEUSE"

#define DEFAULT__LASTEST_TIMEUSE "00' 00'' 00'''"


/**
	circle porperties
*/
#define CIRCLE_ROTATE_SPEED 110
#define CIRCLE_POSITION Vec2(92, 426)

/**
	game control message define
*/
#define MSG__GAME_OVER "msg__game_over"