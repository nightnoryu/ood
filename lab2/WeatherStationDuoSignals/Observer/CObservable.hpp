#pragma once

#include "IObservable.h"
#include <boost/signals2.hpp>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	using ObserverType = IObserver<T>;

	void RegisterObserver(ObserverType& observer, unsigned priority) override
	{
		auto connection = m_signal.connect(priority, boost::bind(&ObserverType::Update, &observer, _1, _2));
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
	using Signal = boost::signals2::signal<void(IObservable<T>&, T const&)>;
	using Connection = boost::signals2::connection;
	using ObserverConnections = std::unordered_map<ObserverType*, Connection>;

	Signal m_signal;
	ObserverConnections m_connections;
};
