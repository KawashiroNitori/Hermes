#pragma once
class Logging
{
public:
	static void info(string str);
	static void debug(string str);
	static void warn(string str);
	static void error(string str);
	static void fatal(string str);
	static void success(string str);
};

