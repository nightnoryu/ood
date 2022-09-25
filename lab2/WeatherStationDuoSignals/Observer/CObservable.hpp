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
		// TODO prioritize observers with groups
		// https://www.boost.org/doc/libs/1_80_0/doc/html/signals2/tutorial.html#id-1.3.35.4.4.3
		auto connection = m_signal.connect(boost::bind(&ObserverType::Update, &observer, _1, _2));
		m_connections.emplace(&observer, connection);
	}

	void NotifyObservers() override
	{
		auto data = GetChangedData();
		m_signal(*this, data);
	}

	void RemoveObserver(ObserverType& observer) override
	{
		auto it = m_connections.find(&observer);
		if (it != m_connections.end())
		{
			it->second.disconnect();
		}
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	using SignalType = boost::signals2::signal<void(IObservable<T>&, T const&)>;

	SignalType m_signal;
	std::unordered_map<ObserverType*, boost::signals2::connection> m_connections;
};
