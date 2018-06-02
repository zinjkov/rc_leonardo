#pragma once

namespace config {
	struct  flashlight {
		enum : uint8_t {
			PIN = 5,
		};
		enum : uint16_t {
			MIN = 1300,
		    MAX = 2000
		};
	};

	struct  manipulator {
		enum : uint8_t {
			PIN = 3,
		};
		enum : uint16_t {
			MIN = 0,
			MAX = 180
		};
	};

}
