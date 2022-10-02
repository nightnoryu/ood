#include "CDecryptingInputStream.h"

CDecryptingInputStream::CDecryptingInputStream(std::unique_ptr<IInputDataStream>&& stream)
	: m_stream(std::move(stream))
{
}

bool CDecryptingInputStream::IsEOF() const
{
	return m_stream->IsEOF();
}

uint8_t CDecryptingInputStream::ReadByte()
{
	return m_stream->ReadByte();
}

std::streamsize CDecryptingInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	return m_stream->ReadBlock(dstBuffer, size);
}
