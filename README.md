# EventScheduler
An event scheduler. Schedules and runs events. Uses no external dependencies other than a few C++ std functions. Can be used for embedded. Also includes a sunrise/sunset calculator.

I wrote this as part of a cleanup of Dusklight. Maybe it comes in handy for someone, so I separated it in its own repository.

The code is tested quite well. But this project is a bit of a mess because I added a ctest target, but then decided to just test in the main program. A lot of the code was tested as part of Dusklight, and the tests in main.cpp are really just the first tests I did before continuing the effors in Dusklight. If you have any questions, just ask.
