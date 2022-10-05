#pragma once

#include "../../OutputDataStream/IOutputDataStream.h"
#include "../COutputDataStreamDecorator.h"
#include <memory>

class CEncryptingOutputStream : public COutputDataStreamDecorator
{
public:
	explicit CEncryptingOutputStream(IOutputDataStreamPtr&& stream, int key);

	void WriteByte(std::uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;
};
