#include "stdafx.h"
#include "Utils.h"
#include <locale>
#include <codecvt>
#include <vector>

using namespace std;

int Utils::AUTH_CODE = -1;
bool Utils::isEnabled = false;

void Utils::copy_str(string& dest, int32_t start, int32_t size, const char* data)
{
	dest.resize(size);
	copy(data + start, data + start + size, dest.begin());
}

int64_t Utils::ntohll(int64_t value)
{
	int64_t out;
	for (int i = 0; i < sizeof(int64_t); i++)
		*(&out + i) = *(&value + sizeof(int64_t) - 1 - i);
	return out;
}

size_t Utils::copyDataCallback(void* ptr, size_t size, size_t nmemb, void* stream)
{
	size_t nsize = nmemb*size;
	string* strdata = (string*)stream;
	if (strdata)
	{
		strdata->append((const char*)ptr, nsize);
	}
	return nsize;
}

std::string Utils::convertGBKtoUTF8(string str)
{
	const char GBK_LOCALE_NAME[] = ".936";
	wstring_convert<codecvt_byname<wchar_t, char, mbstate_t>> cv1(new codecvt_byname<wchar_t, char, mbstate_t>(GBK_LOCALE_NAME));
	wstring tmp_wstr = cv1.from_bytes(str);

	wstring_convert<codecvt_utf8<wchar_t>> cv2;
	string utf8_str = cv2.to_bytes(tmp_wstr);
	return utf8_str;
}

std::string Utils::convertUTF8toGBK(string str)
{
	const char GBK_LOCALE_NAME[] = ".54936";
	const char UTF8_LOCALE_NAME[] = "";
	wstring_convert<codecvt_byname<wchar_t, char, mbstate_t>> cv1(new codecvt_byname<wchar_t, char, mbstate_t>(GBK_LOCALE_NAME));
	wstring_convert<codecvt_utf8<wchar_t>> cv2;
	wstring tmp_wstr = cv2.from_bytes(str);
	std::vector<char> buff(tmp_wstr.size() * 2);
	std::locale loc("zh-CN");
	mbstate_t state = {};
	const wchar_t* pwszNext = nullptr;
	char* pszNext = nullptr;
	int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t> >
		(loc).out(state,
		tmp_wstr.data(), tmp_wstr.data() + tmp_wstr.size(), pwszNext,
		buff.data(), buff.data() + buff.size(), pszNext);
	return string(buff.data(), pszNext);
}
