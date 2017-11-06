#include "stdafx.h"
#include "Utils.h"
#include <string>

using namespace std;


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
