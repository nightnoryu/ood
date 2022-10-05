#include "CDecompressingInputStream.h"

CDecompressingInputStream::CDecompressingInputStream(IInputDataStreamPtr&& stream)
	: CInputDataStreamDecorator(std::move(stream))
{
}

uint8_t CDecompressingInputStream::ReadByte()
{
	if (m_currentSequence.size == 0)
	{
		m_currentSequence.size = m_stream->ReadByte();
		m_currentSequence.byte = m_stream->ReadByte();
	}

	--m_currentSequence.size;
	return m_currentSequence.byte;
}

std::streamsize CDecompressingInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto dstBufferByte = static_cast<std::uint8_t*>(dstBuffer);

	for (std::streamsize i = 0; i < size; ++i)
	{
		try
		{
			*(dstBufferByte + i) = ReadByte();
		}
		catch (std::exception const&)
		{
			continue;
		}
	}

	return size;
}
