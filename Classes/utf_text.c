#include "utf_text.h"
#include "..\cocos2d\external\win32-specific\icon\include\iconv.h"

const char* GBKToUTF8(const char *strChar) {
	iconv_t iconvH;
	iconvH = iconv_open("utf-8","gb2312");
	if (iconvH == 0)
	{
		return NULL;
	}
	size_t strLength = strlen(strChar);
	size_t outLength = strLength<<2;
	size_t copyLength = outLength;
	memset(g_GBKConvUTF8Buf, 0, 5000);

	char* outbuf = (char*) malloc(outLength);
	char* pBuff = outbuf;
	memset( outbuf, 0, outLength);

	if (-1 == iconv(iconvH, &strChar, &strLength, &outbuf, &outLength))
	{
		iconv_close(iconvH);
		return NULL;
	}
	memcpy(g_GBKConvUTF8Buf,pBuff,copyLength);
	free(pBuff);
	iconv_close(iconvH);
	return g_GBKConvUTF8Buf;
}