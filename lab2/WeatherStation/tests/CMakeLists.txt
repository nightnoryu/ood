add_executable(WeatherStationTest
               ../Observer/IObserver.h
               ../Observer/IObservable.h
               ../Observer/CObservable.hpp
               ../WeatherData/CWeatherData.h
               ../WeatherData/CWeatherData.cpp
               WeatherStation.test.cpp)

target_link_libraries(WeatherStationTest PUBLIC catch2)
add_test(NAME WeatherStationTest COMMAND WeatherStationTest)
