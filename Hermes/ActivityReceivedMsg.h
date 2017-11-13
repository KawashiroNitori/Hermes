#pragma once
#include "Activity.h"
#include "Image.h"
#include <map>

using std::map;

class ActivityReceivedMsg :
	public Activity
{
protected:
	int64_t m_sender_id;
	string m_msg;
	int32_t m_font;
	map<string, image_ptr> m_images;

protected:
	static map<string, image_ptr> parse_images(string text);
public:
	ActivityReceivedMsg(int32_t subType, int32_t sendTime, int64_t fromQQ, string msg, int32_t font);
	virtual ~ActivityReceivedMsg();
public:
	virtual document_ptr package() const;
};

