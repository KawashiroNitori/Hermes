#pragma once
#include "stdafx.h"
#include "websocketpp/config/asio_no_tls_client.hpp"
#include "websocketpp/client.hpp"

typedef websocketpp::client<websocketpp::config::asio_client> client;
typedef websocketpp::config::asio_client::message_type::ptr message_ptr;
typedef websocketpp::lib::error_code error_code;

using std::thread;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

class Connection
{
private:
	bool connected;
	bool connecting;
	bool initative_close;
	string connected_uri;
	client cli;
	client::connection_ptr conn;
	std::shared_ptr<std::thread> m_thread;

private:
	void on_open(websocketpp::connection_hdl hdl);
	void on_fail(websocketpp::connection_hdl hdl);
	void on_message(websocketpp::connection_hdl hdl, message_ptr msg);
	void on_close(websocketpp::connection_hdl hdl);

public:
	Connection();
	~Connection();
	error_code connect(string uri);
	error_code send(string msg);
	bool is_connected();
	bool is_connecting();
	bool waiting_for_connect();
	error_code close();
};

