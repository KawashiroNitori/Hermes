#pragma once
#include "Activity.h"
class ActivityFriendAdd :
	public Activity
{
public:
	int64_t m_from_qq;
public:
	ActivityFriendAdd(int32_t subType, int32_t sendTime, int64_t fromQQ);
	~ActivityFriendAdd();
public:
	virtual const char* get_type() const;
	virtual document_ptr package() const;
};

