cmake_minimum_required(VERSION 3.14)
project(EventScheduler VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(event_scheduler src/EventScheduler.cpp)
target_include_directories(event_scheduler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(event_scheduler
  PRIVATE
    src/main.cpp
    src/EventScheduler.cpp
    src/SunriseCalculator.cpp
)

add_executable(event_scheduler_app src/main.cpp)
target_link_libraries(event_scheduler_app PRIVATE event_scheduler)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt)
    enable_testing()
    add_subdirectory(tests)
else()
    message(STATUS "No tests directory found; skipping tests")
endif()
