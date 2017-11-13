#include "stdafx.h"
#include "Connection.h"
#include <thread>


Connection::Connection() : cli(), connected(false), connecting(false), initative_close(false)
{
	cli.set_open_handler(bind(&Connection::on_open, this, ::_1));
	cli.set_fail_handler(bind(&Connection::on_fail, this, ::_1));
	cli.set_message_handler(bind(&Connection::on_message, this, ::_1, ::_2));
	cli.set_close_handler(bind(&Connection::on_close, this, ::_1));

	cli.init_asio();
	cli.start_perpetual();

	this->m_thread = std::make_shared<std::thread>(&client::run, &cli);
}

Connection::~Connection()
{
	error_code ec;
	cli.stop_perpetual();
	if (connected) {
		close();
	}
	m_thread->join();
}

void Connection::on_open(websocketpp::connection_hdl hdl)
{
	Logging::info("���ӳɹ���");
	connected = true;
	connecting = false;
	initative_close = false;
}

void Connection::on_fail(websocketpp::connection_hdl hdl)
{
	Logging::error(str(format("����ʧ�ܣ�%1%") % conn->get_ec().message()));
	connected = false;
	connecting = false;
}

void Connection::on_message(websocketpp::connection_hdl hdl, message_ptr msg)
{
	string msg_payload = Utils::convertUTF8toGBK(msg->get_payload());
	Logging::info(str(format("�յ�����Ϣ��%1%") % msg_payload));
	CQ_sendPrivateMsg(Utils::AUTH_CODE, 648166418, msg_payload.c_str());
}

void Connection::on_close(websocketpp::connection_hdl hdl)
{
	connected = false;
	connecting = false;
	if (!initative_close) {
		// �������ر�
		Logging::info(str(format("���ӱ��رգ�%1%") % conn->get_remote_close_reason()));
	}
}

error_code Connection::connect(string uri)
{
	error_code ec;
	Logging::info("�������ӡ���");
	connecting = true;
	conn = cli.get_connection(uri, ec);
	if (ec) {
		Logging::error(str(format("���ӳ�ʼ��ʧ�ܣ�%1%") % ec.message()));
		return ec;
	}
	cli.connect(conn);
	connected_uri = uri;
	return ec;
}

error_code Connection::send(string msg)
{
	error_code ec;
	cli.send(conn->get_handle(), msg, websocketpp::frame::opcode::text, ec);
	if (ec) {
		Logging::warn(str(format("������Ϣʧ�ܣ�%1%") % ec.message()));
	}
	return ec;
}

bool Connection::is_connected()
{
	return connected;
}

bool Connection::is_connecting()
{
	return connecting;
}

bool Connection::waiting_for_connect()
{
	if (is_connected()) {
		return true;
	}
	for (int i = 0; i < 10e8; ++i) {
		if (!is_connecting() && is_connected()) {
			return true;
		}
	}
	return false;
}

error_code Connection::close()
{
	error_code ec;
	if (!connected) {
		return ec;
	}
	Logging::info("���ڹر����ӡ���");
	cli.close(conn->get_handle(), websocketpp::close::status::going_away, "");
	if (ec) {
		Logging::error(str(format("�ر�����ʱ����%1%") % ec.message()));
	}
	else {
		initative_close = true;
		Logging::info("�����ѹرա�");
	}
	return ec;
}
