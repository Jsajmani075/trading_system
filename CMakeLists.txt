cmake_minimum_required(VERSION 3.10)
project(goquant_trading_system)

set(CMAKE_CXX_STANDARD 17)

find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE cpr::cpr nlohmann_json::nlohmann_json)
