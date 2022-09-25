#pragma once

#include "IObservable.h"
#include <boost/signals2.hpp>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	using ObserverType = IObserver<T>;

	void RegisterObserver(ObserverType& observer) override
	{
		m_signal.connect(boost::bind(&ObserverType::Update, &observer, _1, _2));
	}

	void NotifyObservers() override
	{
		auto data = GetChangedData();
		m_signal(*this, data);
	}

	void RemoveObserver(ObserverType& observer) override
	{
		// TODO
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	using SignalType = boost::signals2::signal<void(IObservable<T>&, T const&)>;

	SignalType m_signal;
};
