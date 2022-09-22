#pragma once

#include "../Beverages/IBeverage.h"
#include <memory>

class CCondimentDecorator : public IBeverage
{
public:
	std::string GetDescription() const final;
	double GetCost() const final;

	virtual std::string GetCondimentDescription() const = 0;
	virtual double GetCondimentCost() const = 0;

protected:
	explicit CCondimentDecorator(IBeveragePtr&& beverage)
		: m_beverage(std::move(beverage))
	{
	}

private:
	IBeveragePtr m_beverage;
};

template <typename Condiment, typename... Args>
auto MakeCondiment(Args const&... args)
{
	return [=](auto&& b) {
		return std::make_unique<Condiment>(std::forward<decltype(b)>(b), args...);
	};
}

template <typename Component, typename Decorator>
auto operator<<(Component&& component, Decorator const& decorate)
{
	return decorate(std::forward<Component>(component));
}
