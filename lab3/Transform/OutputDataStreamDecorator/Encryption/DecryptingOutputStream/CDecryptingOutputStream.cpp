#include "CDecryptingOutputStream.h"

CDecryptingOutputStream::CDecryptingOutputStream(std::unique_ptr<IOutputDataStream>&& stream)
	: m_stream(std::move(stream))
{
}

void CDecryptingOutputStream::WriteByte(std::uint8_t data)
{
	m_stream->WriteByte(data);
}

void CDecryptingOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	m_stream->WriteBlock(srcData, size);
}
