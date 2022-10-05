#include "CDecryptingInputStream.h"

CDecryptingInputStream::CDecryptingInputStream(IInputDataStreamPtr&& stream, int key)
	: CInputDataStreamDecorator(std::move(stream))
{
}

uint8_t CDecryptingInputStream::ReadByte()
{
	return m_stream->ReadByte();
}

std::streamsize CDecryptingInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	return m_stream->ReadBlock(dstBuffer, size);
}
