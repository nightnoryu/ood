#pragma once

#include "../../InputDataStream/IInputDataStream.h"
#include "../CInputDataStreamDecorator.h"
#include <memory>

class CDecryptingInputStream : public CInputDataStreamDecorator
{
public:
	explicit CDecryptingInputStream(IInputDataStreamPtr&& stream);

	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;
};
