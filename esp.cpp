#include "esp.h"



esp::esp() {
}


esp::~esp() {
}

void esp::init() {
	Serial1.begin(115200);
	m_response_recieved = true;
	m_is_find = false;
	m_state = 0;
	m_communication = 0;
	m_act = 0;
	m_last_response = "";
	//Serial.println(m_commands[0].c_str());
	request("AT+CWJAP=\"qqq\",\"\"");
	delay(1000);
	request(m_commands[0]);
	//m_timer.start();
	m_timeout = 10000;
}

void esp::read() {
	while (Serial1.available()) {
		m_last_response += Serial1.readString();
		//Serial.println(m_last_response);
	}
	m_communication++;
}

void esp::run(uint8_t act) {

	m_act = act;
	m_response_recieved = replay_check(m_last_response, m_state);
	should_step();
	request(m_commands[m_state]);

}

void esp::commit(rov_types::rov_leo_telimetry & t)
{
	t.esp = m_state + m_is_find;
	t.esp_comm = m_communication;
}

void esp::send_request(String request)
{
	//Serial.print("send req: ");
	//Serial.println(request.c_str());
	request += "\r\n";
	Serial1.write(request.c_str());
	m_last_response = "";
	m_response_recieved = false;
	m_timer.restart();
	m_timeout = 10000;
}

void esp::request(const String & cmd)
{
	if (m_response_recieved) {
		//Serial.println("request");
		send_request(cmd);
	}
}

void esp::should_step()
{

	if (m_response_recieved) {
		if (m_act == 1) {
			if (!m_is_connected) {
				next(true);
			}
		}		
	}
	if (m_timer.elapsed() > m_timeout) {
		next(false);
	}
}

void esp::next(bool flag)
{
	if (flag) {
		m_state = m_state_mach[m_state][0];
		
	}
	else {
		m_state = m_state_mach[m_state][1];
	}
	m_response_recieved = true;
}

bool esp::replay_check(const String & str, int idx)
{
	for (int i = 0; i < 3; i++) {
		if (str.indexOf(state_rep[idx][i]) == -1) {
			if (idx == 0) {
				m_is_connected = false;
			}
			return false;
		}
	}
	if (idx == 0) {
		m_is_find = true;
	}
	if (idx == 1) {
		m_is_connected = true;
	}
	return true;
}
