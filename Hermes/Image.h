#pragma once
#include "stdafx.h"


class Image
{
private:
	int32_t m_width;
	int32_t m_height;
	int32_t m_size;
	int64_t m_time;
	string m_md5;
	string m_url;
	string m_filename;
public:
	Image(int32_t width, int32_t height, int32_t size, int64_t time, string md5, string url, string filename);
	Image(string filename);
	~Image();
	string to_string() const;
	string get_filename() const { return m_filename; }
public:
	document_ptr package() const;
};

typedef shared_ptr<Image> image_ptr;
