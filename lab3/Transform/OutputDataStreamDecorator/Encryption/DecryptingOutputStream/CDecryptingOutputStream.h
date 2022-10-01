#pragma once

#include "../../../OutputDataStream/IOutputDataStream.h"
#include <memory>

class CDecryptingOutputStream : public IOutputDataStream
{
public:
	explicit CDecryptingOutputStream(std::unique_ptr<IOutputDataStream>&& stream);

	void WriteByte(std::uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	std::unique_ptr<IOutputDataStream> m_stream;
};
