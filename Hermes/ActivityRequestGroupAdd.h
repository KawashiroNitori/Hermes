#pragma once
#include "Activity.h"
class ActivityRequestGroupAdd :
	public Activity
{
private:
	int64_t m_from_qq;
	int64_t m_from_group;
	string m_msg;
	string m_response_flag;
public:
	ActivityRequestGroupAdd(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, const char *responseFlag);
	~ActivityRequestGroupAdd();
public:
	virtual const char* get_type() const;
	virtual document_ptr package() const;
};

