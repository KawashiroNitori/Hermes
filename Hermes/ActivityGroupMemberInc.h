#pragma once
#include "Activity.h"
class ActivityGroupMemberInc :
	public Activity
{
private:
	int64_t m_from_group;
	int64_t m_from_qq;
	int64_t m_operate_qq;
public:
	ActivityGroupMemberInc(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ);
	~ActivityGroupMemberInc();
public:
	virtual const char* get_type() const;
	virtual document_ptr package() const;
};

