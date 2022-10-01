#include "CCompressingOutputStream.h"

CCompressingOutputStream::CCompressingOutputStream(std::unique_ptr<IOutputDataStream>&& stream)
	: m_stream(std::move(stream))
{
}

void CCompressingOutputStream::WriteByte(std::uint8_t data)
{
	m_stream->WriteByte(data);
}

void CCompressingOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	m_stream->WriteBlock(srcData, size);
}
