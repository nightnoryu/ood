#include "CFileInputStream.h"

CFileInputStream::CFileInputStream(const std::string& filename)
	: m_file(filename, std::ios_base::in | std::ios_base::binary)
{
	if (!m_file.is_open())
	{
		throw std::runtime_error("failed to open file for reading");
	}
}

bool CFileInputStream::IsEOF() const
{
	return m_file.eof();
}

uint8_t CFileInputStream::ReadByte()
{
	char byte;
	m_file.get(byte);

	if (m_file.bad())
	{
		throw std::ios_base::failure("failed to read from file");
	}

	return static_cast<std::uint8_t>(byte);
}

std::streamsize CFileInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	m_file.read(static_cast<char*>(dstBuffer), size);

	if (m_file.bad())
	{
		throw std::ios_base::failure("failed to read from file");
	}

	return m_file.gcount();
}
