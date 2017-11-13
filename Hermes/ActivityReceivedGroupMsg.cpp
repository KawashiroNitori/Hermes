#include "stdafx.h"
#include "ActivityReceivedGroupMsg.h"
#include <regex>
#include <boost/lexical_cast.hpp>


ActivityReceivedGroupMsg::ActivityReceivedGroupMsg(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font)
: ActivityReceivedMsg(subType, sendTime, fromQQ, msg, font)
, m_from_group(fromGroup)
, m_from_anonymous(fromAnonymous)
, m_member(make_shared<Member>(fromGroup, fromQQ))
, m_mention_info(parse_mention(fromGroup, msg))
{
}


ActivityReceivedGroupMsg::~ActivityReceivedGroupMsg()
{
}


map<int64_t, member_ptr> ActivityReceivedGroupMsg::parse_mention(int64_t group_id, string text)
{
	map<int64_t, member_ptr> mention_map;
	std::regex mention_regex("\\[CQ:at,qq=([0-9]+)\\]");
	int64_t mentioned_id;
	std::smatch base_match;
	std::ssub_match mention_match;
	while (std::regex_search(text, base_match, mention_regex)) {
		if (base_match.size() == 2) {
			mention_match = base_match[1];
			mentioned_id = boost::lexical_cast<int64_t>(mention_match.str());
			mention_map[mentioned_id] = make_shared<Member>(group_id, mentioned_id);
		}
		text = base_match.suffix();
	}
	return mention_map;
}


const char* ActivityReceivedGroupMsg::get_type() const
{
	return "GROUP_MESSAGE";
}

document_ptr ActivityReceivedGroupMsg::package() const
{
	document_ptr doc = ActivityReceivedMsg::package();
	doc->AddMember("from_group", m_from_group, doc->GetAllocator());
	doc->AddMember("from_anonymous", Value().SetString(m_from_anonymous.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("member", *m_member->package(), doc->GetAllocator());
	if (m_mention_info.size()) {
		Value mentions(Type::kObjectType);
		for (const auto& member : m_mention_info) {
			auto& member_doc = *member.second->package();
			Value tmp_member(member_doc, member_doc.GetAllocator());
			mentions.AddMember(Value(boost::lexical_cast<string>(member.first).c_str(), member_doc.GetAllocator()).Move(), tmp_member, member_doc.GetAllocator());
		}
		doc->AddMember("mention_info", mentions, doc->GetAllocator());
	}
	return doc;
}
