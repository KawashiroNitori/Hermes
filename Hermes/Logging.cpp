#include "stdafx.h"
#include "Logging.h"
#include <cstdarg>
#include <boost/format.hpp>


void Logging::info(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_INFO, "信息", str.c_str());
}

void Logging::debug(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_DEBUG, "调试", str.c_str());
}

 
void Logging::warn(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_WARNING, "警告", str.c_str());
}

void Logging::error(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_ERROR, "错误", str.c_str());
}

void Logging::fatal(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_FATAL, "致命错误", str.c_str());
}

void Logging::success(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_INFOSUCCESS, "成功", str.c_str());
}
