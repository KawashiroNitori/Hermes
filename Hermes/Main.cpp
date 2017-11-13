#include "stdafx.h"
#include "Main.h"
#include <thread>

string Main::REMOTE_URI = "ws://127.0.0.1:8080/push";

std::shared_ptr<Connection> Main::connection_ptr;

void Main::start()
{
	if (!connection_ptr) {
		connection_ptr = std::make_shared<Connection>();
		connect();
	}
}

void Main::connect()
{
	if (!is_started()) {
		return;
	}
	if (!is_connected()) {
		connection_ptr->connect(REMOTE_URI);
	}
}

bool Main::is_connected()
{
	return connection_ptr && connection_ptr->is_connected();
}

bool Main::is_started()
{
	return (bool)connection_ptr;
}

error_code Main::send(string msg)
{
	error_code ec;
	if (connection_ptr->waiting_for_connect()) {
		ec = connection_ptr->send(msg);
	}
	return ec;
}

bool Main::check()
{
	if (!Utils::isEnabled) {
		return false;
	}

	if (!is_started()) {
		start();
	}
	else if (!is_connected()) {
		connect();
	}
	return true;
}

void Main::stop()
{
	connection_ptr.reset();
}

