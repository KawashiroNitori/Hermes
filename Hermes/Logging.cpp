#include "stdafx.h"
#include "Logging.h"
#include <cstdarg>
#include <boost/format.hpp>


void Logging::info(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_INFO, "��Ϣ", str.c_str());
}

void Logging::debug(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_DEBUG, "����", str.c_str());
}

 
void Logging::warn(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_WARNING, "����", str.c_str());
}

void Logging::error(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_ERROR, "����", str.c_str());
}

void Logging::fatal(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_FATAL, "��������", str.c_str());
}

void Logging::success(string str)
{
	CQ_addLog(Utils::AUTH_CODE, CQLOG_INFOSUCCESS, "�ɹ�", str.c_str());
}
