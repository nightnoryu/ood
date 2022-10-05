#include "COutputDataStreamDecorator.h"

COutputDataStreamDecorator::COutputDataStreamDecorator(IOutputDataStreamPtr&& stream)
	: m_stream(std::move(stream))
{
}
