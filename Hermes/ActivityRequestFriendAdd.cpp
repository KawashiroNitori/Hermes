#include "stdafx.h"
#include "ActivityRequestFriendAdd.h"


ActivityRequestFriendAdd::ActivityRequestFriendAdd(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, const char *responseFlag)
: Activity(subType, sendTime)
, m_from_qq(fromQQ)
, m_msg(msg)
, m_response_flag(responseFlag)
{
}


ActivityRequestFriendAdd::~ActivityRequestFriendAdd()
{
}

const char* ActivityRequestFriendAdd::get_type() const
{
	return "REQUEST_FRIEND_ADD";
}

document_ptr ActivityRequestFriendAdd::package() const
{
	document_ptr doc = Activity::package();
	doc->AddMember("from_qq", m_from_qq, doc->GetAllocator());
	doc->AddMember("msg", Value(m_msg.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("response_flag", Value(m_response_flag.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	return doc;
}
