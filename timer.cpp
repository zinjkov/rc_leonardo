#include "timer.h"
#include <Arduino.h>


timer::timer() : m_time(0), m_is_started(false)
{
}


timer::~timer()
{
}

void timer::start()
{
	m_is_started = true;
	m_time = millis();
}

bool timer::is_started()
{
	return m_is_started;
}

void timer::stop()
{
	m_is_started = false;
}

void timer::restart()
{
	stop();
	start();
}

unsigned long timer::elapsed()
{
	return m_is_started ? (millis() - m_time) : 0;
}
