#pragma once

#include "IObservable.h"
#include <set>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	using ObserverType = IObserver<T>;

	void RegisterObserver(ObserverType& observer, unsigned priority) override
	{
		m_observers.insert({
			.observer = &observer,
			.priority = priority,
		});
	}

	void NotifyObservers() override
	{
		auto data = GetChangedData();
		auto observersCopy = m_observers;

		for (auto& priorityObserver : observersCopy)
		{
			priorityObserver.observer->Update(data);
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{
		typename std::set<PriorityObserver>::iterator it;
		for (it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			if (it->observer == &observer)
			{
				break;
			}
		}

		if (it != m_observers.end())
		{
			m_observers.erase(it);
		}
	}

protected:
	virtual T GetChangedData() const = 0;

private:
	struct PriorityObserver
	{
		ObserverType* observer;
		unsigned priority;

		bool operator<(PriorityObserver const& other) const
		{
			return priority < other.priority;
		}
	};

	std::set<PriorityObserver> m_observers;
};
