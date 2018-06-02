//
// Created by zinjkov on 30.03.18.
//

#include "binary_stream.hpp"

namespace rov_types {

    binary_stream::binary_stream():
            m_counter(0),
			m_len(0) {
        unsigned short x = 1; /* 0x0001 */
        m_system_type = (*((unsigned char *) &x) == 0) ? byte_ordering::big_endian : byte_ordering::little_endian;
        m_ordering = byte_ordering::big_endian;
    }

    binary_stream::binary_stream(const uint8_t *byte_array, uint8_t size) :
            m_counter(0),
            m_len(size)
    {
        unsigned short x = 1; /* 0x0001 */
        m_system_type = (*((unsigned char *) &x) == 0) ? byte_ordering::big_endian : byte_ordering::little_endian;
        m_ordering = byte_ordering::big_endian;
		for (int i = 0; i < size; i++) {
			m_data[i] = byte_array[i];
		}
    }

    binary_stream::~binary_stream() {

    }

    void binary_stream::data(uint8_t *byte_array, uint8_t *size) {
		for (int i = 0; i < m_len; i++) {
			byte_array[i] = m_data[i];
		}
		*size = m_len;
    }

	const uint8_t *binary_stream::data_ptr() {
		return m_data;
	}

    void binary_stream::change_byte_ordering(binary_stream::byte_ordering ordering) {
        if (m_ordering != ordering) {
            for (int i = 0; i < m_len; i++) {
                m_data[i] = swap_endian<int16_t>(m_data[i]);
            }
            m_ordering = ordering;
        }
    }


    binary_stream &binary_stream::operator>>(uint8_t &val) {
        if ((m_len - m_counter) >= sizeof(uint8_t))
            read<uint8_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(int8_t &val) {
        if ((m_len - m_counter) >= sizeof(int8_t))
            read<int8_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(uint16_t &val) {
        if ((m_len - m_counter) >= sizeof(uint16_t))
            read<uint16_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(int16_t &val) {
        if ((m_len - m_counter) >= sizeof(int16_t))
            read<int16_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(uint32_t &val) {
        if ((m_len - m_counter) >= sizeof(uint32_t))
            read<uint32_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(int32_t &val) {
        if ((m_len - m_counter) >= sizeof(int32_t))
            read<int32_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(uint64_t &val) {
        if ((m_len - m_counter) >= sizeof(uint64_t))
            read<uint64_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(int64_t &val) {
        if ((m_len - m_counter) >= sizeof(int64_t))
            read<int64_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(float &val) {
        if ((m_len - m_counter) >= sizeof(float))
            read<float>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(double &val) {
        if ((m_len - m_counter) >= sizeof(double))
            read<double>(val);
        return *this;
    }

    binary_stream &binary_stream::operator>>(long double &val) {
        if ((m_len - m_counter) >= sizeof(long double))
            read<long double>(val);
        return *this;
    }



    binary_stream &binary_stream::operator<<(uint8_t &val) {
        write<uint8_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(int8_t &val) {
        write<int8_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(uint16_t &val) {
        write<uint16_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(int16_t &val) {
        write<int16_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(uint32_t &val) {
        write<uint32_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(int32_t &val) {
        write<int32_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(uint64_t &val) {
        write<uint64_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(int64_t &val) {
        write<int64_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(float &val) {
        write<float>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(double &val) {
        write<double>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(long double &val) {
        write<long double>(val);
        return *this;
    }



    binary_stream &binary_stream::operator<<(const uint8_t &val) {
        write<uint8_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const int8_t &val) {
        write<int8_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const uint16_t &val) {
        write<uint16_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const int16_t &val) {
        write<int16_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const uint32_t &val) {
        write<uint32_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const int32_t &val) {
        write<int32_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const uint64_t &val) {
        write<uint64_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const int64_t &val) {
        write<int64_t>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const float &val) {
        write<float>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const double &val) {
        write<double>(val);
        return *this;
    }

    binary_stream &binary_stream::operator<<(const long double &val) {
        write<long double>(val);
        return *this;
    }
}