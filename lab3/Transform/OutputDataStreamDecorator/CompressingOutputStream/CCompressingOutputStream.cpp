#include "CCompressingOutputStream.h"

CCompressingOutputStream::CCompressingOutputStream(IOutputDataStreamPtr&& stream)
	: m_stream(std::move(stream))
{
}

CCompressingOutputStream::~CCompressingOutputStream()
{
	Flush();
}

void CCompressingOutputStream::WriteByte(std::uint8_t data)
{
	if (m_currentSequence.size == 0)
	{
		m_currentSequence = {
			.byte = data,
			.size = 1,
		};
		return;
	}

	if (m_currentSequence.byte == data)
	{
		++m_currentSequence.size;
		return;
	}

	Flush();
	m_currentSequence = {
		.byte = data,
		.size = 1,
	};
}

void CCompressingOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	for (std::streamsize i = 0; i < size; ++i)
	{
		WriteByte(*(static_cast<std::uint8_t const*>(srcData) + i));
	}

	m_stream->WriteBlock(srcData, size);
}

void CCompressingOutputStream::Flush()
{
	m_stream->WriteByte(m_currentSequence.size);
	m_stream->WriteByte(m_currentSequence.byte);

	m_currentSequence = {
		.byte = 0,
		.size = 0,
	};
}
