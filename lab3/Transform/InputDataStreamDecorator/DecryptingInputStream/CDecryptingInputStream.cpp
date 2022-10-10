#include "CDecryptingInputStream.h"
#include "../../EncryptionTableBuilder/CEncryptionTableBuilder.h"

CDecryptingInputStream::CDecryptingInputStream(IInputDataStreamPtr&& stream, int key)
	: CInputDataStreamDecorator(std::move(stream))
	, m_decryptionTable(CEncryptionTableBuilder::BuildDecryptionTable(key))
{
}

uint8_t CDecryptingInputStream::ReadByte()
{
	return DecryptByte(m_stream->ReadByte());
}

std::streamsize CDecryptingInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto readSize = m_stream->ReadBlock(dstBuffer, size);
	auto bytes = static_cast<std::uint8_t*>(dstBuffer);

	for (std::streamsize i = 0; i < readSize; ++i)
	{
		*bytes = DecryptByte(*(bytes + i));
	}

	return readSize;
}

std::uint8_t CDecryptingInputStream::DecryptByte(std::uint8_t byte) const
{
	return m_decryptionTable[static_cast<std::size_t>(byte)];
}
