#pragma once
#include "Activity.h"
class ActivityRequestFriendAdd :
	public Activity
{
private:
	int64_t m_from_qq;
	string m_msg;
	string m_response_flag;
public:
	ActivityRequestFriendAdd(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, const char *responseFlag);
	~ActivityRequestFriendAdd();
public:
	virtual const char* get_type() const;
	virtual document_ptr package() const;
};

