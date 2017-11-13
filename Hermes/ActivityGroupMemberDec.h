#pragma once
#include "Activity.h"
class ActivityGroupMemberDec :
	public Activity
{
private:
	int64_t m_from_group;
	int64_t m_from_qq;
	int64_t m_operate_qq;
public:
	ActivityGroupMemberDec(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ);
	~ActivityGroupMemberDec();
public:
	virtual const char* get_type() const;
	virtual document_ptr package() const;
};

