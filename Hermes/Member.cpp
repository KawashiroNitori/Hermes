#include "stdafx.h"
#include "Member.h"
#include <WinSock2.h>
#include <websocketpp/base64/base64.hpp>

using websocketpp::base64_decode;

Member::Member(int64_t group_id, int64_t qq_id)
{
	bin_struct(base64_decode(string(CQ_getGroupMemberInfoV2(Utils::AUTH_CODE, group_id, qq_id, true))));
}

Member::Member(string b64text)
{
	bin_struct(base64_decode(b64text));
}

Member::~Member()
{
}

document_ptr Member::package()
{
	document_ptr doc = make_shared<Document>(Type::kObjectType);
	doc->AddMember("group_id", m_group, doc->GetAllocator());
	doc->AddMember("qq_id", m_qq, doc->GetAllocator());
	doc->AddMember("nickname", Value(m_nickname.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("group_card", Value(m_group_card.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("sex", m_sex, doc->GetAllocator());
	doc->AddMember("age", m_age, doc->GetAllocator());
	doc->AddMember("region", Value(m_region.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("join_time", m_join_time, doc->GetAllocator());
	doc->AddMember("last_chat_time", m_last_chat_time, doc->GetAllocator());
	doc->AddMember("level_name", Value(m_level_name.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("privilege", m_privilege, doc->GetAllocator());
	doc->AddMember("special_title", Value(m_special_title.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("title_expire", m_title_expire, doc->GetAllocator());
	doc->AddMember("is_violation", m_is_violation, doc->GetAllocator());
	return doc;
}

void Member::bin_struct(string struct_text)
{
	int16_t size;
	int32_t pos = 0;
	const char* data = struct_text.data();

	this->m_group = Utils::ntohll(*((int64_t*)(data + pos)));
	pos += sizeof(int64_t);

	this->m_qq = Utils::ntohll(*((int64_t*)(data + pos)));
	pos += sizeof(int64_t);

	size = ntohs(*((int16_t*)(data + pos)));
	pos += sizeof(int16_t);
	Utils::copy_str(this->m_nickname, pos, size, data);
	pos += size;

	size = ntohs(*((int16_t*)(data + pos)));
	pos += sizeof(int16_t);
	Utils::copy_str(this->m_group_card, pos, size, data);
	pos += size;

	this->m_sex = ntohl(*((int32_t*)(data + pos)));
	pos += sizeof(int32_t);

	this->m_age = ntohl(*((int32_t*)(data + pos)));
	pos += sizeof(int32_t);

	size = ntohs(*((int16_t*)(data + pos)));
	pos += sizeof(int16_t);
	Utils::copy_str(this->m_region, pos, size, data);
	pos += size;

	this->m_join_time = ntohl(*((int32_t*)(data + pos)));
	pos += sizeof(int32_t);

	this->m_last_chat_time = ntohl(*((int32_t*)(data + pos)));
	pos += sizeof(int32_t);

	size = ntohs(*((int16_t*)(data + pos)));
	pos += sizeof(int16_t);
	Utils::copy_str(this->m_level_name, pos, size, data);
	pos += size;

	this->m_privilege = ntohl(*((int32_t*)(data + pos)));
	pos += sizeof(int32_t);

	size = ntohs(*((int16_t*)(data + pos)));
	pos += sizeof(int16_t);
	Utils::copy_str(this->m_special_title, pos, size, data);
	pos += size;

	this->m_is_violation = ntohl(*((int32_t*)(data + pos))) != 0;
	pos += sizeof(int32_t);

	if (this->m_group_card.length() == 0)
		this->m_group_card = this->m_nickname;
}
