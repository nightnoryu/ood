#pragma once

#include "IObservable.h"
#include <map>

template <typename T>
class CObservable : public IObservable<T>
{
public:
	using Priority = unsigned;
	using ObserverType = IObserver<T>;

	void RegisterObserver(ObserverType& observer, Priority priority) override
	{
		m_observers.emplace(priority, &observer);
	}

	void NotifyObservers() override
	{
		auto data = GetChangedData();
		auto observersCopy = m_observers;

		for (auto& observer : observersCopy)
		{
			if (observer.second != nullptr)
			{
				observer.second->Update(data);
			}
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{
		typename std::multimap<Priority, ObserverType*>::iterator it;
		for (it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			if (it->second == &observer)
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
	std::multimap<Priority, ObserverType*> m_observers;
};
