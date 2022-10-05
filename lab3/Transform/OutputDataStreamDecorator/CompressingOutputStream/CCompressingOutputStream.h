#pragma once

#include "../../OutputDataStream/IOutputDataStream.h"

class CCompressingOutputStream : public IOutputDataStream
{
public:
	explicit CCompressingOutputStream(IOutputDataStreamPtr&& stream);

	void WriteByte(std::uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	IOutputDataStreamPtr m_stream;
};
