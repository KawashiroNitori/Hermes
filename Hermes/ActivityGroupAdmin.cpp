#include "stdafx.h"
#include "ActivityGroupAdmin.h"


ActivityGroupAdmin::ActivityGroupAdmin(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t beingOperateQQ)
: Activity(subType, sendTime)
, m_from_group(fromGroup)
, m_operate_qq(beingOperateQQ)
{
}


ActivityGroupAdmin::~ActivityGroupAdmin()
{
}

const char* ActivityGroupAdmin::get_type() const
{
	return "GROUP_ADMIN";
}

document_ptr ActivityGroupAdmin::package() const
{
	document_ptr doc = Activity::package();
	doc->AddMember("from_group", m_from_group, doc->GetAllocator());
	doc->AddMember("operate_qq", m_operate_qq, doc->GetAllocator());
	return doc;
}
