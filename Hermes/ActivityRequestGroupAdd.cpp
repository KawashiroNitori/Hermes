#include "stdafx.h"
#include "ActivityRequestGroupAdd.h"


ActivityRequestGroupAdd::ActivityRequestGroupAdd(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, const char *responseFlag)
: Activity(subType, sendTime)
, m_from_group(fromGroup)
, m_from_qq(fromQQ)
, m_msg(msg)
, m_response_flag(responseFlag)
{
}


ActivityRequestGroupAdd::~ActivityRequestGroupAdd()
{
}

const char* ActivityRequestGroupAdd::get_type() const
{
	return "REQUEST_GROUP_ADD";
}

document_ptr ActivityRequestGroupAdd::package() const
{
	document_ptr doc = Activity::package();
	doc->AddMember("from_group", m_from_group, doc->GetAllocator());
	doc->AddMember("from_qq", m_from_qq, doc->GetAllocator());
	doc->AddMember("msg", Value(m_msg.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("response_flag", Value(m_response_flag.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	return doc;
}
