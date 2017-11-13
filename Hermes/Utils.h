#pragma once
#include "stdafx.h"

using std::string;

class Utils
{
public:
	static int32_t AUTH_CODE;
	static bool isEnabled;

	static void copy_str(string& dest, int32_t start, int32_t size, const char* data);
	static int64_t ntohll(int64_t value);
	static size_t copyDataCallback(void* ptr, size_t size, size_t nmemb, void* stream);
	static std::string convertGBKtoUTF8(string str);
	static std::string convertUTF8toGBK(string str);
};

