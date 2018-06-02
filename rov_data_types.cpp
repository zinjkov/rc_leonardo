//
// Created by zinjkov on 30.03.18.
//

#include "rov_data_types.hpp"

void rov_types::rov_leo_telimetry::data_serialize(binary_stream & bs)
{
	bs << secondary_manipulator;
	bs << flashlight;
	bs << esp;
	bs << esp_comm;
	bs << leo_comm;
}

void rov_types::rov_leo_telimetry::data_deserialize(binary_stream & bs)
{
	bs >> secondary_manipulator;
	bs >> flashlight;
	bs >> esp;
	bs >> esp_comm;
	bs >> leo_comm;
}

void rov_types::rov_leo_control::data_serialize(binary_stream & bs)
{
	bs << secondary_manipulator;
	bs << flashlight;
	bs << realease;

}

void rov_types::rov_leo_control::data_deserialize(binary_stream & bs)
{
	bs >> secondary_manipulator;
	bs >> flashlight;
	bs >> realease;
}
