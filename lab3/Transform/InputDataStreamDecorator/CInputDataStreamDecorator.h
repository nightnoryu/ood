#pragma once

#include "../InputDataStream/IInputDataStream.h"
#include <memory>

using IInputDataStreamPtr = std::unique_ptr<IInputDataStream>;

class CInputDataStreamDecorator : IInputDataStream
{
public:
	bool IsEOF() const override;

protected:
	explicit CInputDataStreamDecorator(IInputDataStreamPtr&& stream);

	IInputDataStreamPtr m_stream;
};
