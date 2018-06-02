//
// Created by zinjkov on 30.03.18.
//

#ifndef RC_ROV_SERVER_SERIALAZER_HPP
#define RC_ROV_SERVER_SERIALAZER_HPP


#include "binary_stream.hpp"
namespace rov_types {

    struct serializable {
        enum error_code : uint8_t {
            success,
            success_size_greater,
            size_less,
            crc_mismatch,
            wrong_size,
            wrong_id
        };

        static bool check_for_success(error_code err);

        virtual uint8_t serialize(uint8_t *output) = 0;

        virtual error_code deserialize(uint8_t *output, uint8_t size) = 0;

        static String error_to_string(error_code err);
    };

};

#endif //RC_ROV_SERVER_SERIALAZER_HPP
