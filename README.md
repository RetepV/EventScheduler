# EventScheduler
An event scheduler. Schedules and runs events. Uses no external dependencies other than a few C++ std functions. Can be used for embedded. Also includes a sunrise/sunset calculator.

I wrote this as part of a cleanup of Dusklight. Maybe it comes in handy for someone, so I separated it in its own repository.

The code is tested quite well. But this project is a bit of a mess because I added a ctest target, but then decided to just test in the main program. A lot of the code was tested as part of Dusklight, and the tests in main.cpp are really just the first tests I did before continuing the effors in Dusklight. If you have any questions, just ask.

# EventScheduler

Simple C++ event scheduler example.

## Build (with CMake)

mkdir -p build && cd build
cmake ..
cmake --build .

# To run tests (Catch2 will be fetched automatically):
ctest --output-on-failure

## Notes
- Targets:
  - `event_scheduler_app` - demo app
  - `event_scheduler` - library
  - `test_event_scheduler` - unit tests (when `tests/` exists)


clear;make event_scheduler_app;./event_scheduler_app
