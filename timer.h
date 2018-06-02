#pragma once
#include <stdint.h>
class timer
{
public:
	timer();
	~timer();
	void start();
	bool is_started();
	void stop();
	void restart();
	unsigned long elapsed();
private:
	unsigned long m_time;
	bool m_is_started;
};

