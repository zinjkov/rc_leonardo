//
// Created by zinjkov on 30.03.18.
//

#ifndef RC_ROV_SERVER_CRC_HPP
#define RC_ROV_SERVER_CRC_HPP

#include <stdint.h>
namespace rov_types {
    namespace crc {
        int16_t calculateCRC(const uint8_t *data, long len);
    };
};


#endif //RC_ROV_SERVER_CRC_HPP
