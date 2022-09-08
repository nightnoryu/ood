#define CATCH_CONFIG_MAIN
#include "../WeatherData/CWeatherData.h"
#include "catch.hpp"
#include <sstream>

TEST_CASE("safe observer deletion")
{
	GIVEN("an observable weather station")
	{
		CWeatherData observable;

		AND_GIVEN("a suicidal observer")
		{
			class CSuicidalObserver : public IObserver<WeatherInfo>
			{
			public:
				CSuicidalObserver(IObservable<WeatherInfo>& observable, std::ostream& out)
					: m_observable(observable)
					, m_out(out)
				{
				}

			private:
				void Update(const WeatherInfo& data) override
				{
					m_observable.RemoveObserver(*this);
					m_out << "I was called and survived!";
				}

				IObservable<WeatherInfo>& m_observable;
				std::ostream& m_out;
			};

			std::ostringstream out;
			CSuicidalObserver observer(observable, out);
			observable.RegisterObserver(observer, 0);

			WHEN("notifying observers")
			{
				observable.NotifyObservers();

				THEN("it doesn't crash and produces output")
				{
					REQUIRE(out.str() == "I was called and survived!");
				}
			}
		}
	}
}

TEST_CASE("observers with priority")
{
	// TODO
}
