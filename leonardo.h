#pragma once

#include "manipulator.h"
#include "flashlight.h"
#include "rov_data_types.hpp"
#include "esp.h"
#include "timer.h"
class leonardo
{
public:
	leonardo();
	~leonardo();

	void init();
	void run();
	void commit();
	void nanopi_event();
	void esp_event();

private:
	flashlight m_flashlight;
	manipulator m_manipulator;
	esp m_esp;
	rov_types::rov_leo_control m_control;
	rov_types::rov_leo_telimetry m_telemetry;
	timer m_timer;
	uint8_t m_comm = 0;
};

