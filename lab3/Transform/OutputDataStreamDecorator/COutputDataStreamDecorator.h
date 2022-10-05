#pragma once

#include "../OutputDataStream/IOutputDataStream.h"
#include <memory>

class COutputDataStreamDecorator : public IOutputDataStream
{
protected:
	explicit COutputDataStreamDecorator(IOutputDataStreamPtr&& stream);

	IOutputDataStreamPtr m_stream;
};
