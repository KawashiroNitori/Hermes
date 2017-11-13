#pragma once
#include "ActivityReceivedMsg.h"
class ActivityReceivedPrivateMsg :
	public ActivityReceivedMsg
{
public:
	ActivityReceivedPrivateMsg(int32_t subType, int32_t sendTime, int64_t fromQQ, string msg, int32_t font);
	~ActivityReceivedPrivateMsg();
public:
	virtual const char* get_type() const;
	virtual document_ptr package() const;
};

