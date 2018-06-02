#include "manipulator.h"
#include "config.h"
#include <Arduino.h>

manipulator::manipulator()
{
}


manipulator::~manipulator()
{
}

void manipulator::init()
{
	m_servo.attach(config::manipulator::PIN);
	m_timer.start();
	m_val = config::manipulator::MAX + config::manipulator::MIN / 2;
}

void manipulator::run(int8_t dir)
{
	if (m_timer.elapsed() > 20) {
		m_val = constrain(m_val + dir, config::manipulator::MIN, config::manipulator::MAX);
		m_servo.write(m_val);
		m_timer.restart();
	}
}

void manipulator::commit(rov_types::rov_leo_telimetry & t)
{
	t.secondary_manipulator = m_val;
}
