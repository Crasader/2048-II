#pragma once

#include "AppMacro.h"

class BrickTextureCache : public Ref {
private:
	static BrickTextureCache* instance;
	TextureCache* m_cache;
	BrickTextureCache() {}
public:
	~BrickTextureCache() {}
	static BrickTextureCache* getCache();
	
	/**
		get a brick texture by index
	*/
	Texture2D* getBrickTextureByIndex(int index);
};