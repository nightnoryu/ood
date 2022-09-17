#pragma once

#include <string>

template <typename T>
class IObservable;

template <typename T>
class IObserver
{
public:
	virtual void Update(IObservable<T>& observable, T const& data) = 0;
	virtual void SetObservableName(IObservable<T> &observable, std::string const& name) = 0;

	virtual ~IObserver() = default;
};
