add_executable(WeatherStationDuoSignalsTest
               ../Observer/IObserver.h
               ../Observer/IObservable.h
               ../Observer/CObservable.hpp
               ../WeatherData/CWeatherData.h
               ../WeatherData/CWeatherData.cpp
               WeatherStationDuoSignals.test.cpp)

target_link_libraries(WeatherStationDuoSignalsTest PUBLIC catch2)
add_test(NAME WeatherStationDuoSignalsTest COMMAND WeatherStationDuoSignalsTest)
