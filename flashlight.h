#pragma once

#include <Servo.h>
#include "timer.h"
class flashlight {
public:
	flashlight();
	~flashlight();
	void init();
	void run(int8_t dir);
private:
	Servo m_flash;
	timer m_timer;
	int16_t m_val;
};

