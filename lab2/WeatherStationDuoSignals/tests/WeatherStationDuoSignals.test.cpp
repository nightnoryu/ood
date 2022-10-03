#define CATCH_CONFIG_MAIN
#include "../WeatherData/CWeatherData.h"
#include "catch.hpp"
#include <sstream>

TEST_CASE("several observables in the same observers")
{
	GIVEN("a few observables")
	{
		CWeatherData observable1;
		CWeatherData observable2;

		AND_GIVEN("an observer")
		{
			class CDummyObserver : public IObserver<WeatherInfo>
			{
			public:
				explicit CDummyObserver(std::ostream& out)
					: m_out(out)
				{
				}

				void SetObservableName(IObservable<WeatherInfo>& observable, std::string const& name)
				{
					m_observableNames[&observable] = name;
				}

				void RemoveObservable(IObservable<WeatherInfo>& observable)
				{
					m_observableNames.erase(&observable);
				}

			private:
				void Update(IObservable<WeatherInfo>& observable, WeatherInfo const& data) override
				{
					auto name = m_observableNames.find(&observable);
					if (name != m_observableNames.end())
					{
						m_out << name->second;
					}
					else
					{
						m_out << "unknown";
					}

					m_out << '\n';
				}

				std::map<IObservable<WeatherInfo>*, std::string> m_observableNames;
				std::ostream& m_out;
			};

			std::ostringstream out;
			CDummyObserver observer(out);

			observable1.RegisterObserver(observer, 0);
			observable2.RegisterObserver(observer, 0);

			WHEN("notifying from both observables")
			{
				observable1.NotifyObservers();
				observable2.NotifyObservers();

				THEN("both of them are unknown")
				{
					REQUIRE(out.str() == "unknown\nunknown\n");
				}
			}

			WHEN("settings names for observables")
			{
				observer.SetObservableName(observable1, "1");
				observer.SetObservableName(observable2, "2");

				AND_WHEN("notifying from both observables")
				{
					observable1.NotifyObservers();
					observable2.NotifyObservers();

					THEN("they have different names")
					{
						REQUIRE(out.str() == "1\n2\n");
					}
				}

				AND_WHEN("removing info about first observable")
				{
					observer.RemoveObservable(observable1);

					AND_WHEN("notifying from both observables")
					{
						observable1.NotifyObservers();
						observable2.NotifyObservers();

						THEN("first one is unknown")
						{
							REQUIRE(out.str() == "unknown\n2\n");
						}
					}
				}
			}
		}
	}
}

TEST_CASE("observers with priority")
{
	GIVEN("an observable")
	{
		CWeatherData observable;

		AND_GIVEN("observers #1 and #2")
		{
			class CObserver : public IObserver<WeatherInfo>
			{
			public:
				CObserver(std::ostream& out, int number)
					: m_out(out)
					, m_number(number)
				{
				}

			private:
				void Update(IObservable<WeatherInfo>& /* observable */, WeatherInfo const& /* data */) override
				{
					m_out << "Observer #" << m_number << "\n";
				}

				std::ostream& m_out;
				int m_number;
			};

			std::ostringstream out;
			CObserver observer1(out, 1);
			CObserver observer2(out, 2);

			WHEN("adding #1 with priority 1 and #2 with priority 2 and notifying them")
			{
				observable.RegisterObserver(observer1, 1);
				observable.RegisterObserver(observer2, 2);
				observable.NotifyObservers();

				THEN("#1 gets called first, then #2")
				{
					REQUIRE(out.str() == "Observer #1\nObserver #2\n");
				}
			}

			WHEN("adding #1 with priority 5 and #2 with priority 1 and notifying them")
			{
				observable.RegisterObserver(observer1, 5);
				observable.RegisterObserver(observer2, 1);
				observable.NotifyObservers();

				THEN("#2 gets called first, then #1")
				{
					REQUIRE(out.str() == "Observer #2\nObserver #1\n");
				}
			}

			WHEN("adding both observers with the same priority (#1 first) and notifying them")
			{
				observable.RegisterObserver(observer1, 1);
				observable.RegisterObserver(observer2, 1);
				observable.NotifyObservers();

				THEN("they are called in the order of registering: #1 gets called first, then #2")
				{
					REQUIRE(out.str() == "Observer #1\nObserver #2\n");
				}
			}

			WHEN("adding both observers with the same priority (#2 first) and notifying them")
			{
				observable.RegisterObserver(observer2, 1);
				observable.RegisterObserver(observer1, 1);
				observable.NotifyObservers();

				THEN("they are called in the order of registering: #2 gets called first, then #1")
				{
					REQUIRE(out.str() == "Observer #2\nObserver #1\n");
				}
			}
		}
	}
}
