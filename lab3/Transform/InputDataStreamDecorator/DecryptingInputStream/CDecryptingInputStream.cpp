#include "CDecryptingInputStream.h"
#include <random>
#include <algorithm>

CDecryptingInputStream::CDecryptingInputStream(IInputDataStreamPtr&& stream, int key)
	: CInputDataStreamDecorator(std::move(stream))
{
	InitializeDecryptionTable(key);
}

uint8_t CDecryptingInputStream::ReadByte()
{
	return DecryptByte(m_stream->ReadByte());
}

std::streamsize CDecryptingInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto readSize = m_stream->ReadBlock(dstBuffer, size);
	for (std::streamsize i = 0; i < readSize; ++i)
	{
		auto dstBufferByte = static_cast<std::uint8_t*>(dstBuffer);
		*dstBufferByte = DecryptByte(*dstBufferByte);
	}

	return readSize;
}

void CDecryptingInputStream::InitializeDecryptionTable(int key)
{
	std::vector<std::uint8_t> encryptionTable(256);

	for (std::size_t i = 0; i <= 255; ++i)
	{
		encryptionTable[i] = static_cast<std::uint8_t>(i);
	}

	std::shuffle(encryptionTable.begin(), encryptionTable.end(), std::mt19937(key));

	m_decryptionTable.resize(256);
	for (std::size_t i = 0; i <= 255; ++i)
	{
		m_decryptionTable[static_cast<std::size_t>(encryptionTable[i])] = static_cast<std::uint8_t>(i);
	}
}

std::uint8_t CDecryptingInputStream::DecryptByte(std::uint8_t byte) const
{
	return m_decryptionTable[byte];
}