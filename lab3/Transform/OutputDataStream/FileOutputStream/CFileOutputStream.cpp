#include "CFileOutputStream.h"

CFileOutputStream::CFileOutputStream(std::string const& filename)
	: m_file(filename, std::ios::out | std::ios::binary)
{
}

void CFileOutputStream::WriteByte(std::uint8_t data)
{
	try
	{
		m_file.write(reinterpret_cast<char const*>(&data), 1);
	}
	catch (std::exception&)
	{
		throw std::ios_base::failure("failed to write byte");
	}
}

void CFileOutputStream::WriteBlock(void const* srcData, std::streamsize size)
{
	try
	{
		m_file.write(static_cast<char const*>(srcData), size);
	}
	catch (std::exception&)
	{
		throw std::ios_base::failure("failed to write block");
	}
}
