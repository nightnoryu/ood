add_executable(WeatherStation
               Observer/IObserver.h
               Observer/IObservable.h
               Observer/CObservable.hpp
               Weather/CWeatherData.h
               Weather/CWeatherData.cpp
               Displays/CurrentConditionsDisplay/CCurrentConditionsDisplay.h
               Displays/CurrentConditionsDisplay/CCurrentConditionsDisplay.cpp
               Displays/StatsDisplay/CStatsDisplay.h
               Displays/StatsDisplay/CStatsDisplay.cpp
               main.cpp Displays/StatsDisplay/StatsCalculator/CStatsMonitor.cpp Displays/StatsDisplay/StatsCalculator/CStatsMonitor.h)
