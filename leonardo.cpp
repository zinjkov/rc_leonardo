#include "leonardo.h"



leonardo::leonardo() {

}


leonardo::~leonardo() {

}

void leonardo::init() {
	Serial.begin(115200);
	m_manipulator.init();
	m_flashlight.init();
	m_esp.init();
	m_timer.start();
}

void leonardo::run() {

	m_manipulator.run(m_control.secondary_manipulator);
	m_flashlight.run(m_control.flashlight);
	m_esp.run(m_control.realease);
}

void leonardo::commit()
{
	m_manipulator.commit(m_telemetry);
	m_flashlight.commit(m_telemetry);
	m_esp.commit(m_telemetry);
	m_telemetry.leo_comm = m_comm;
	if (m_timer.elapsed() > 100) {
		uint8_t buf[30] = { 0 };
		int size = m_telemetry.serialize(buf);
		Serial.write(buf, size);
		m_timer.restart();
	}
}

void leonardo::nanopi_event() {
	delay(3);
	uint8_t buf[30] = { 0 };
	int i = 0;
	while (Serial.available()) {
		buf[i++] = Serial.read();
	}
	rov_types::rov_leo_control rlc;
	auto e = rlc.deserialize(buf, i);
	if (rov_types::serializable::check_for_success(e)) {
		m_control = rlc;
		m_comm++;
	}
}

void leonardo::esp_event() {
	delay(3);
	m_esp.read();
}
