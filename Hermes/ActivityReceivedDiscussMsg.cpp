#include "stdafx.h"
#include "ActivityReceivedDiscussMsg.h"


ActivityReceivedDiscussMsg::ActivityReceivedDiscussMsg(int32_t subType, int32_t sendTime, int64_t fromDiscuss, int64_t fromQQ, const char *msg, int32_t font)
: ActivityReceivedMsg(subType, sendTime, fromQQ, msg, font)
, m_from_discuss(fromDiscuss)
{
}


ActivityReceivedDiscussMsg::~ActivityReceivedDiscussMsg()
{
}

const char* ActivityReceivedDiscussMsg::get_type() const
{
	return "DISCUSS_MESSAGE";
}

document_ptr ActivityReceivedDiscussMsg::package() const
{
	document_ptr doc = ActivityReceivedMsg::package();
	doc->AddMember("from_discuss", m_from_discuss, doc->GetAllocator());
	return doc;
}
