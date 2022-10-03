#include "CDecompressingInputStream.h"

CDecompressingInputStream::CDecompressingInputStream(IInputDataStreamPtr&& stream)
	: CInputDataStreamDecorator(std::move(stream))
{
}

uint8_t CDecompressingInputStream::ReadByte()
{
	return m_stream->ReadByte();
}

std::streamsize CDecompressingInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	return m_stream->ReadBlock(dstBuffer, size);
}
