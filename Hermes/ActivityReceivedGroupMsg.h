#pragma once
#include "stdafx.h"
#include "ActivityReceivedMsg.h"
#include "Member.h"
#include <map>

using std::map;

class ActivityReceivedGroupMsg :
	public ActivityReceivedMsg
{
private:
	int64_t m_from_group;
	string m_from_anonymous;
	member_ptr m_member;
	map<int64_t, member_ptr> m_mention_info;

private:
	static map<int64_t, member_ptr> parse_mention(int64_t group_id, string text);

public:
	ActivityReceivedGroupMsg(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font);
	~ActivityReceivedGroupMsg();
public:
	virtual const char* get_type() const;
	virtual document_ptr package() const;
};

