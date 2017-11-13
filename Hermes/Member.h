#pragma once
#include "stdafx.h"

class Member
{
private:
	int64_t m_group;
	int64_t m_qq;
	string m_nickname;
	string m_group_card;
	int32_t m_sex;
	int32_t m_age;
	string m_region;
	int32_t m_join_time;
	int32_t m_last_chat_time;
	string m_level_name;
	int32_t m_privilege;
	string m_special_title;
	int32_t m_title_expire;
	bool m_is_violation;

public:
	Member(int64_t group_id, int64_t qq_id);
	Member(string b64text);
	~Member();
	document_ptr package();

private:
	void bin_struct(string struct_text);

};


typedef shared_ptr<Member> member_ptr;
