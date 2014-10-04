#pragma once

#include "BrickTextureCache.h"

BrickTextureCache* BrickTextureCache::instance = nullptr;

BrickTextureCache* BrickTextureCache::getCache() {
	if (instance == nullptr) {
		instance = new BrickTextureCache();
		instance->m_cache = Director::getInstance()->getTextureCache();
	}
	return instance;
}

Texture2D* BrickTextureCache::getBrickTextureByIndex(int index) {
	auto key = StringUtils::format("element\\%d.png", index);
	return m_cache->addImage(key);
}
