#pragma once

#include "../../OutputDataStream/IOutputDataStream.h"
#include <memory>

class CEncryptingOutputStream : public IOutputDataStream
{
public:
	explicit CEncryptingOutputStream(std::unique_ptr<IOutputDataStream>&& stream, int key);

	void WriteByte(std::uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	std::unique_ptr<IOutputDataStream> m_stream;
};
