#pragma once

#include "../Shapes/CShape.h"
#include <boost/iterator/indirect_iterator.hpp>
#include <vector>

class CPictureDraft
{
public:
	using Storage = std::vector<CShapePtr>;
	using ConstIterator = boost::indirect_iterator<Storage::const_iterator, CShape const&>;

	CPictureDraft() = default;

	CPictureDraft(CPictureDraft&&) = default;
	CPictureDraft& operator=(CPictureDraft&&) = default;

	CPictureDraft(CPictureDraft const&) = delete;
	CPictureDraft& operator=(CPictureDraft const&) = delete;

	bool IsEmpty() const;

	void AddShape(CShapePtr&& shape);

	ConstIterator begin() const;

	ConstIterator end() const;

private:
	Storage m_shapes;
};
