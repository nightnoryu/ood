#pragma once

#include "../Shapes/CShape.h"
#include <boost/iterator/indirect_iterator.hpp>
#include <vector>

class CPictureDraft
{
public:
	using Storage = std::vector<CShapePtr>;

	void AddShape(CShapePtr&& shape);
	bool IsEmpty() const;

	Storage::const_iterator begin() const;
	Storage::const_iterator end() const;

private:
	Storage m_shapes;
};
