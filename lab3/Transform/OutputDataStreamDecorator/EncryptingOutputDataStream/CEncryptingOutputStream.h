#pragma once

#include "../../OutputDataStream/IOutputDataStream.h"
#include "../COutputDataStreamDecorator.h"
#include <memory>
#include <vector>

class CEncryptingOutputStream : public COutputDataStreamDecorator
{
public:
	explicit CEncryptingOutputStream(IOutputDataStreamPtr&& stream, int key);

	void WriteByte(std::uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	void InitializeEncryptionTable(int key);
	std::uint8_t EncryptByte(std::uint8_t byte) const;

	std::vector<std::uint8_t> m_encryptionTable;
};
