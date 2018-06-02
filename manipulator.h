#pragma once
#include "timer.h"
#include <Servo.h>
#include "rov_data_types.hpp"
class manipulator
{
public:
	manipulator();
	~manipulator();
	void init();
	void run(int8_t dir);
	void commit(rov_types::rov_leo_telimetry &t);
private:
	Servo m_servo;
	timer m_timer;
	int m_val;
};

