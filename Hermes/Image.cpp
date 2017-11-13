#include "stdafx.h"
#include "Image.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/ini_parser.hpp"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using rapidjson::Writer;
using rapidjson::StringBuffer;


Image::Image(int32_t width, int32_t height, int32_t size, int64_t time, string md5, string url, string filename)
: m_width(width)
, m_height(height)
, m_size(size)
, m_time(time)
, m_md5(md5)
, m_url(url)
, m_filename(filename)
{

}

Image::Image(string filename)
: m_filename(filename)
{
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(str(format("data\\image\\%1%.cqimg") % filename), pt);
	m_width = pt.get<int32_t>("image.width");
	m_height = pt.get<int32_t>("image.height");
	m_size = pt.get<int32_t>("image.size");
	m_time = pt.get<int64_t>("image.addtime");
	m_md5 = pt.get<string>("image.md5");
	m_url = pt.get<string>("image.url");
}

Image::~Image()
{
}


string Image::to_string() const
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	this->package()->Accept(writer);
	return buffer.GetString();
}


document_ptr Image::package() const
{
	document_ptr doc = make_shared<Document>(Type::kObjectType);
	doc->AddMember("width", m_width, doc->GetAllocator());
	doc->AddMember("height", m_height, doc->GetAllocator());
	doc->AddMember("size", m_size, doc->GetAllocator());
	doc->AddMember("time", m_time, doc->GetAllocator());
	doc->AddMember("md5", Value().SetString(m_md5.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("url", Value().SetString(m_url.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("filename", Value().SetString(get_filename().c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	return doc;
}
