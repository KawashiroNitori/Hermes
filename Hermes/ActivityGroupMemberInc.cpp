#include "stdafx.h"
#include "ActivityGroupMemberInc.h"


ActivityGroupMemberInc::ActivityGroupMemberInc(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ)
: Activity(subType, sendTime)
, m_from_group(fromGroup)
, m_from_qq(fromQQ)
, m_operate_qq(beingOperateQQ)
{
}


ActivityGroupMemberInc::~ActivityGroupMemberInc()
{
}

const char* ActivityGroupMemberInc::get_type() const
{
	return "GROUP_MEMBER_INCREASE";
}

document_ptr ActivityGroupMemberInc::package() const
{
	document_ptr doc = Activity::package();
	doc->AddMember("from_group", m_from_group, doc->GetAllocator());
	doc->AddMember("operate_qq", m_operate_qq, doc->GetAllocator());
	doc->AddMember("from_qq", m_from_qq, doc->GetAllocator());
	return doc;
}
