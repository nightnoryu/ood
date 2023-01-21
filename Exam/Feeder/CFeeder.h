#pragma once

#include "../Cat/CCat.h"

class CFeeder : public IObserver<CCatInfo>
{
public:
	explicit CFeeder(CCat& cat);

private:
	void Update(CCatInfo const& data) override;

	CCat& m_cat;
};
