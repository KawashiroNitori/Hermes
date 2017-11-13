// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#include "targetver.h"

#define NOMINMAX

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <windows.h>
#include <WinDef.h>
#include <cstdint>
#include <string>
#include <memory>
#include <boost/format.hpp>
#include <rapidjson/document.h>

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "cqp.h"
#include "Utils.h"
#include "Logging.h"

using boost::format;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::error_code;
using rapidjson::Document;
using rapidjson::Value;
using rapidjson::Type;

typedef shared_ptr<Document> document_ptr;
typedef shared_ptr<Value> value_ptr;
