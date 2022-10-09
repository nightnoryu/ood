#include "CPictureDraft.h"

bool CPictureDraft::IsEmpty() const
{
	return m_shapes.empty();
}

CPictureDraft::ConstIterator CPictureDraft::begin() const
{
	return m_shapes.begin();
}

CPictureDraft::ConstIterator CPictureDraft::end() const
{
	return m_shapes.end();
}

void CPictureDraft::AddShape(CShapePtr&& shape)
{
	m_shapes.push_back(std::move(shape));
}

CPictureDraft::ConstIterator begin(CPictureDraft const& draft)
{
	return draft.begin();
}

CPictureDraft::ConstIterator end(CPictureDraft const& draft)
{
	return draft.end();
}
