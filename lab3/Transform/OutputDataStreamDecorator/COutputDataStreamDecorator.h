#pragma once

#include "../OutputDataStream/IOutputDataStream.h"
#include <memory>

using IOutputDataStreamPtr = std::unique_ptr<IOutputDataStream>;

class COutputDataStreamDecorator : IOutputDataStream
{
protected:
	explicit COutputDataStreamDecorator(IOutputDataStreamPtr&& stream);

	IOutputDataStreamPtr m_stream;
};
