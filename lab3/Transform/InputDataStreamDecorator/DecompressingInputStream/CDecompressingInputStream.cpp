#include "CDecompressingInputStream.h"

CDecompressingInputStream::CDecompressingInputStream(std::unique_ptr<IInputDataStream>&& stream)
	: m_stream(std::move(stream))
{
}

bool CDecompressingInputStream::IsEOF() const
{
	return m_stream->IsEOF();
}

uint8_t CDecompressingInputStream::ReadByte()
{
	return m_stream->ReadByte();
}

std::streamsize CDecompressingInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	return m_stream->ReadBlock(dstBuffer, size);
}
