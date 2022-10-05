#include "CFileInputStream.h"

CFileInputStream::CFileInputStream(const std::string& filename)
	: m_file(filename, std::ios_base::in | std::ios_base::binary)
{
}

bool CFileInputStream::IsEOF() const
{
	return m_file.eof();
}

uint8_t CFileInputStream::ReadByte()
{
	char byte;

	if (!m_file.get(byte))
	{
		throw std::ios_base::failure("failed to read from file");
	}

	return static_cast<std::uint8_t>(byte);
}

std::streamsize CFileInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	if (!m_file.read(static_cast<char*>(dstBuffer), size))
	{
		throw std::ios_base::failure("failed to read from file");
	}

	return m_file.gcount();
}
