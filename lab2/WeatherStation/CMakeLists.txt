add_executable(WeatherStation
               Observer/IObserver.h
               Observer/IObservable.h
               Observer/CObservable.hpp
               WeatherData/CWeatherData.h
               WeatherData/CWeatherData.cpp
               Displays/CurrentConditionsDisplay/CCurrentConditionsDisplay.h
               Displays/CurrentConditionsDisplay/CCurrentConditionsDisplay.cpp
               Displays/StatsDisplay/CStatsDisplay.h
               Displays/StatsDisplay/CStatsDisplay.cpp
               Displays/StatsDisplay/StatsCalculator/CStatsMonitor.h
               Displays/StatsDisplay/StatsCalculator/CStatsMonitor.cpp
               main.cpp)

add_subdirectory(tests)
