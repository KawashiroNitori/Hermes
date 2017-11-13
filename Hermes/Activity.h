#pragma once
#include "stdafx.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace rapidjson;

class Activity
{
protected:
	int32_t m_sub_type;
	int32_t m_send_time;

public:
	Activity(int32_t subType, int32_t sendTime);
	virtual ~Activity();
public:
	// 将 Activity 自身的属性打包为 json，必须实现。
	virtual document_ptr package() const;

	// 返回 Activity 的类型字符串，必须实现。
	virtual const char* get_type() const = 0;

	// 获取 json 字符串。
	virtual string to_string() const;

	// 处理该 Activity，默认行为是将打包后的 json 送入连接。
	virtual error_code process();
private:

};

typedef shared_ptr<Activity> activity_ptr;
