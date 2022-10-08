#include "CMemoryInputStream.h"

CMemoryInputStream::CMemoryInputStream(std::vector<std::uint8_t>& data)
	: m_data(data)
{
}

bool CMemoryInputStream::IsEOF() const
{
	return m_currentPosition == m_data.size();
}

uint8_t CMemoryInputStream::ReadByte()
{
	if (IsEOF())
	{
		throw std::ios_base::failure("can not read past EOF");
	}

	return m_data[m_currentPosition++];
}

std::streamsize CMemoryInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto readSize = std::min(static_cast<std::size_t>(size), m_data.size() - m_currentPosition);
	auto charBuffer = static_cast<std::uint8_t*>(dstBuffer);

	for (std::size_t i = 0; i < readSize; ++i)
	{
		*charBuffer = m_data[m_currentPosition];
		++charBuffer;
		++m_currentPosition;
	}

	return static_cast<std::streamsize>(readSize);
}
