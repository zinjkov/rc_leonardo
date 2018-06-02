//
// Created by zinjkov on 30.03.18.
//

#ifndef RC_ROV_SERVER_ROV_DATA_TYPES_HPP
#define RC_ROV_SERVER_ROV_DATA_TYPES_HPP

#include <stdint.h>
#include "base_packet_t.hpp"


namespace rov_types {
	struct rov_leo_telimetry : public base_packet_t<0x1D, 7, 9> {
		int8_t secondary_manipulator = 0;
		int16_t flashlight = 0;
		uint8_t esp = 0;
		int8_t esp_comm = 0;
		int8_t leo_comm = 0;
	private:
		void data_serialize(binary_stream &bs) override final;

		void data_deserialize(binary_stream &bs) override final;
	};

	struct rov_leo_control : public base_packet_t<0x2D, 4, 6> {
		int8_t secondary_manipulator = 0;
		int8_t flashlight = 0;
		int8_t realease = 0;

	private:
		void data_serialize(binary_stream &bs) override final;

		void data_deserialize(binary_stream &bs) override final;
	};


	
};
#endif //RC_ROV_SERVER_ROV_DATA_TYPES_HPP
