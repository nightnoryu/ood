#include "CMemoryOutputStream.h"

void CMemoryOutputStream::WriteByte(std::uint8_t data)
{
	m_data.push_back(data);
}

void CMemoryOutputStream::WriteBlock(void const* srcData, std::streamsize size)
{
	std::copy(
		static_cast<std::uint8_t const*>(srcData),
		static_cast<std::uint8_t const*>(srcData) + size,
		std::back_inserter(m_data));
}
