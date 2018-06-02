#pragma once
#include "timer.h"
#include <Servo.h>

class manipulator
{
public:
	manipulator();
	~manipulator();
	void init();
	void run(int8_t dir);
private:
	Servo m_servo;
	timer m_timer;
	uint8_t m_val;
};

