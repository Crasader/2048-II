#include "AppDelegate.h"
#include "StartScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
	srand(time(0));
}

AppDelegate::~AppDelegate() {

}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
	glview->setFrameSize(VSIZE.width, VSIZE.height);
	glview->setDesignResolutionSize(VSIZE.width, VSIZE.height, ResolutionPolicy::EXACT_FIT);

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 30);

    // create a scene. it's an autorelease object
    // auto scene = StartScene::create();
	auto scene = Scene::create();
	auto layer = StartScene::create();
	scene->addChild(layer);

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
