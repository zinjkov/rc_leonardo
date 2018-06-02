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
}

void leonardo::run() {
	m_manipulator.run(m_control.secondary_manipulator);
	m_flashlight.run(m_control.flashlight);
	m_esp.run(m_control.realease);
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
	}
}

void leonardo::esp_event() {
	delay(3);
	m_esp.read();
}
