#pragma once
#include <Arduino.h>
#include "timer.h"
#include "rov_data_types.hpp"
class esp
{
public:
	esp();
	~esp();
	void init();
	void read();
	void run(uint8_t act);
	void commit(rov_types::rov_leo_telimetry &t);

private:
	bool m_is_connected = false;
	bool m_is_find = false;
	String m_last_response;
	uint8_t m_act = 0;
	bool m_response_recieved;
	timer m_timer;
	long long m_timeout;
	uint8_t m_state = 0;
	uint8_t m_communication = 0;

	const String m_commands[2] = {
		"AT+CWLAP=\"RCROV_LIFTER\"",
		"AT+CWJAP=\"RCROV_LIFTER\",\"00000000\"",
	};

	const uint8_t m_state_mach[2][2] = {
		{ 1, 0 },
		{ 0, 0 },
	};

	const String state_rep[2][3] = {
		{ "OK", "+CWLAP:", "RCROV_LIFTER" },
		{ "WIFI CONNECTED", "WIFI GOT IP", "OK" },
	};

	void send_request(String request);

	void request(const String & cmd);

	void should_step();

	void next(bool flag);

	bool replay_check(const String & str, int idx);
	

};

