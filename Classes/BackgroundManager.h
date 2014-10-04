#pragma once

#include "AppMacro.h"

class BackgroundManager : public Ref {
public:
	static Texture2D * getBackgroundByIndex(int index);
};