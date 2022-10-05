#pragma once

#include "../InputDataStream/IInputDataStream.h"
#include <memory>

class CInputDataStreamDecorator : public IInputDataStream
{
public:
	bool IsEOF() const override;

protected:
	explicit CInputDataStreamDecorator(IInputDataStreamPtr&& stream);

	IInputDataStreamPtr m_stream;
};
