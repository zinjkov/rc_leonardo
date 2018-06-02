#include "flashlight.h"
#include "config.h"
#include <Arduino.h>

flashlight::flashlight()
{
}

flashlight::~flashlight()
{
}

void flashlight::init() {
	m_flash.attach(config::flashlight::PIN);
	m_timer.start();
	m_val = config::flashlight::MIN;
}

void flashlight::run(int8_t dir) {
	if (m_timer.elapsed() > 40) {
		m_val = constrain(m_val + dir, config::flashlight::MIN, config::flashlight::MAX);
		m_flash.writeMicroseconds(m_val);
		m_timer.restart();
		
	}
}
