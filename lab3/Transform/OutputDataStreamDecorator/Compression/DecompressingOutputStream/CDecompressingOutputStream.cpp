#include "CDecompressingOutputStream.h"

CDecompressingOutputStream::CDecompressingOutputStream(std::unique_ptr<IOutputDataStream>&& stream)
	: m_stream(std::move(stream))
{
}

void CDecompressingOutputStream::WriteByte(std::uint8_t data)
{
	m_stream->WriteByte(data);
}

void CDecompressingOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	m_stream->WriteBlock(srcData, size);
}
