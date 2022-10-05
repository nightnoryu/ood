#pragma once

#include "../CInputDataStreamDecorator.h"

class CDecompressingInputStream : public CInputDataStreamDecorator
{
public:
	explicit CDecompressingInputStream(IInputDataStreamPtr&& stream);

	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	struct Sequence
	{
		std::uint8_t byte = 0;
		std::streamsize size = 0;
	};

	Sequence m_currentSequence;
};
