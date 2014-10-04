#include "BackgroundManager.h"

Texture2D* BackgroundManager::getBackgroundByIndex(int index) {
	return Director::getInstance()->getTextureCache()->addImage(StringUtils::format("%d.png", index));
}