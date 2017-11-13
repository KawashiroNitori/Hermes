#include "stdafx.h"
#include "ActivityReceivedPrivateMsg.h"


ActivityReceivedPrivateMsg::ActivityReceivedPrivateMsg(int32_t subType, int32_t sendTime, int64_t fromQQ, string msg, int32_t font)
: ActivityReceivedMsg(subType, sendTime, fromQQ, msg, font)
{

}

ActivityReceivedPrivateMsg::~ActivityReceivedPrivateMsg()
{
}


const char* ActivityReceivedPrivateMsg::get_type() const
{
	return "PRIVATE_MESSAGE";
}

document_ptr ActivityReceivedPrivateMsg::package() const
{
	document_ptr doc = ActivityReceivedMsg::package();
	return doc;
}
