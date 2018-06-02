#pragma once

#include <Servo.h>
#include "timer.h"
#include "rov_data_types.hpp"

class flashlight {
public:
	flashlight();
	~flashlight();
	void init();
	void run(int8_t dir);
	void commit(rov_types::rov_leo_telimetry &t);
private:
	Servo m_flash;
	timer m_timer;
	int16_t m_val;
};

