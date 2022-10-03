#pragma once

#include "../../InputDataStream/IInputDataStream.h"
#include "../CInputDataStreamDecorator.h"
#include <memory>

class CDecompressingInputStream : public CInputDataStreamDecorator
{
public:
	explicit CDecompressingInputStream(IInputDataStreamPtr&& stream);

	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;
};
