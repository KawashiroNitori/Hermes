#include "stdafx.h"
#include "ActivityReceivedMsg.h"
#include <regex>


ActivityReceivedMsg::ActivityReceivedMsg(int32_t subType, int32_t sendTime, int64_t fromQQ, string msg, int32_t font)
: Activity(subType, sendTime)
, m_sender_id(fromQQ)
, m_msg(msg)
, m_font(font)
, m_images(parse_images(msg))
{
}


ActivityReceivedMsg::~ActivityReceivedMsg()
{
}


map<string, image_ptr> ActivityReceivedMsg::parse_images(string text)
{
	map<string, image_ptr> images;
	string filename;
	std::regex image_regex("\\[CQ:image,file=([0-9a-fA-F]{32}\\.[a-zA-Z]+)\\]");
	std::smatch base_match;
	std::ssub_match file_match;
	while (std::regex_search(text, base_match, image_regex)) {
		if (base_match.size() == 2) {
			file_match = base_match[1];
			filename = file_match.str();
			images[filename] = make_shared<Image>(filename);
		}
		text = base_match.suffix();
	}
	return images;
}


document_ptr ActivityReceivedMsg::package() const
{
	document_ptr doc = Activity::package();
	doc->AddMember("from_qq", m_sender_id, doc->GetAllocator());
	doc->AddMember("msg", Value().SetString(m_msg.c_str(), doc->GetAllocator()).Move(), doc->GetAllocator());
	doc->AddMember("font", m_font, doc->GetAllocator());
	if (m_images.size()) {
		Value images(kObjectType);
		for (const auto& image : m_images) {
			auto& image_doc = *image.second->package();
			Value tmp_image(image_doc, image_doc.GetAllocator());
			images.AddMember(Value().SetString(image.first.c_str(), image_doc.GetAllocator()).Move(), tmp_image, image_doc.GetAllocator());
		}
		doc->AddMember("images", images, doc->GetAllocator());
	}
	return doc;
}
