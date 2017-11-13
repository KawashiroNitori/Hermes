#include "stdafx.h"
#include "ActivityFriendAdd.h"


ActivityFriendAdd::ActivityFriendAdd(int32_t subType, int32_t sendTime, int64_t fromQQ)
: Activity(subType, sendTime)
, m_from_qq(fromQQ)
{
}


ActivityFriendAdd::~ActivityFriendAdd()
{
}

const char* ActivityFriendAdd::get_type() const
{
	return "FRIEND_ADD";
}

document_ptr ActivityFriendAdd::package() const
{
	document_ptr doc = Activity::package(); 
	doc->AddMember("from_qq", m_from_qq, doc->GetAllocator());
	return doc;
}
