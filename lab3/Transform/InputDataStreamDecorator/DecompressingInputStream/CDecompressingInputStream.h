#pragma once

#include "../../InputDataStream/IInputDataStream.h"
#include <memory>

class CDecompressingInputStream : public IInputDataStream
{
public:
	explicit CDecompressingInputStream(std::unique_ptr<IInputDataStream>&& stream);

	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	std::unique_ptr<IInputDataStream> m_stream;
};
