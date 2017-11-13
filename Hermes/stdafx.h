// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
#include "targetver.h"

#define NOMINMAX

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件: 
#include <windows.h>
#include <WinDef.h>
#include <cstdint>
#include <string>
#include <memory>
#include <boost/format.hpp>
#include <rapidjson/document.h>

// TODO:  在此处引用程序需要的其他头文件
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
