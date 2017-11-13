#pragma once
#include "stdafx.h"
#include "Connection.h"

class Main
{
private:
	static string REMOTE_URI;
	static std::shared_ptr<Connection> connection_ptr;
public:
	static void start(); 
	static void stop();
	static void connect();
	static bool is_connected();
	static bool is_started();
	static bool check();
	static error_code send(string msg);
};

