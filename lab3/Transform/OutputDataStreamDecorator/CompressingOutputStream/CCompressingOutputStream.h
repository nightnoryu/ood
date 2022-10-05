#pragma once

#include "../../OutputDataStream/IOutputDataStream.h"

class CCompressingOutputStream : public IOutputDataStream
{
public:
	explicit CCompressingOutputStream(IOutputDataStreamPtr&& stream);

	~CCompressingOutputStream() override;

	void WriteByte(std::uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	void Flush();

	struct Sequence
	{
		std::uint8_t byte = 0;
		std::streamsize size = 0;
	};

	Sequence m_currentSequence;
	IOutputDataStreamPtr m_stream;
};
