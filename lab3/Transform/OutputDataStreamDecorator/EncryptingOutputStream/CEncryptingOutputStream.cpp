#include "CEncryptingOutputStream.h"
#include <random>
#include <algorithm>

CEncryptingOutputStream::CEncryptingOutputStream(IOutputDataStreamPtr&& stream, int key)
	: m_stream(std::move(stream))
{
	InitializeEncryptionTable(key);
}

void CEncryptingOutputStream::WriteByte(std::uint8_t data)
{
	m_stream->WriteByte(EncryptByte(data));
}

void CEncryptingOutputStream::WriteBlock(void const* srcData, std::streamsize size)
{
	for (std::streamsize i = 0; i < size; ++i)
	{
		WriteByte(*(static_cast<std::uint8_t const*>(srcData) + i));
	}

	m_stream->WriteBlock(srcData, size);
}

void CEncryptingOutputStream::InitializeEncryptionTable(int key)
{
	m_encryptionTable.resize(256);
	for (std::size_t i = 0; i <= 255; ++i)
	{
		m_encryptionTable[i] = static_cast<std::uint8_t>(i);
	}

	std::shuffle(m_encryptionTable.begin(), m_encryptionTable.end(), std::mt19937(key));
}

std::uint8_t CEncryptingOutputStream::EncryptByte(std::uint8_t byte) const
{
	return m_encryptionTable[static_cast<std::size_t>(byte)];
}
