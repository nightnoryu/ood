#include "CEncryptingOutputStream.h"

CEncryptingOutputStream::CEncryptingOutputStream(IOutputDataStreamPtr&& stream)
	: COutputDataStreamDecorator(std::move(stream))
{
}

void CEncryptingOutputStream::WriteByte(std::uint8_t data)
{
	m_stream->WriteByte(data);
}

void CEncryptingOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	m_stream->WriteBlock(srcData, size);
}
