#include "stdafx.h"
#include "Activity.h"
#include "Main.h"


Activity::Activity(int32_t subType, int32_t sendTime)
: m_sub_type(subType)
, m_send_time(sendTime)
{
}


Activity::~Activity()
{
}

document_ptr Activity::package() const
{
	document_ptr doc = make_shared<Document>(kObjectType);
	doc->AddMember("type", StringRef(get_type()), doc->GetAllocator());
	doc->AddMember("sub_type", m_sub_type, doc->GetAllocator());
	doc->AddMember("send_time", m_send_time, doc->GetAllocator());
	return doc;
}

string Activity::to_string() const
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	this->package()->Accept(writer);
	return buffer.GetString();
}

error_code Activity::process()
{
	error_code ec;
	string msg = Utils::convertGBKtoUTF8(to_string());
	Main::send(msg);
	return ec;
}
