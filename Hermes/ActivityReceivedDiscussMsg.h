#pragma once
#include "ActivityReceivedMsg.h"
class ActivityReceivedDiscussMsg :
	public ActivityReceivedMsg
{
private:
	int64_t m_from_discuss;
public:
	ActivityReceivedDiscussMsg(int32_t subType, int32_t sendTime, int64_t fromDiscuss, int64_t fromQQ, const char *msg, int32_t font);
	~ActivityReceivedDiscussMsg();
public:
	virtual const char* get_type() const;
	virtual document_ptr package() const;
};

