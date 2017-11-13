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
	// �� Activity ��������Դ��Ϊ json������ʵ�֡�
	virtual document_ptr package() const;

	// ���� Activity �������ַ���������ʵ�֡�
	virtual const char* get_type() const = 0;

	// ��ȡ json �ַ�����
	virtual string to_string() const;

	// ����� Activity��Ĭ����Ϊ�ǽ������� json �������ӡ�
	virtual error_code process();
private:

};

typedef shared_ptr<Activity> activity_ptr;
