#include <iostream>
#include <unistd.h>

#include "EventScheduler.hpp"
#include "SunriseCalculator.hpp"
#include "DebugStuff.hpp"

void doSunriseCalculationTests();
void doEventSchedulerTests();
void scheduleLoopTester();

CEventSchedulerItem testItems[] = {
    {CEventSchedulerDayNumber_Sunday, CEventSchedulerItemType_Sunset, 0, 30, 30, 1},                // sunset [-30,30]
    {CEventSchedulerDayNumber_Monday, CEventSchedulerItemType_Time, 60, 60, 60, 0},                // 1:00 [-60,60]

    {CEventSchedulerDayNumber_Monday, CEventSchedulerItemType_Sunset, 0, 30, 30, 1},                // sunset [-30,30]
    // {CEventSchedulerDayNumber_Monday, CEventSchedulerItemType_Time, 1380, 30, 90, 0},               // 23:00 [-30,90]
    {CEventSchedulerDayNumber_Monday, CEventSchedulerItemType_Time, 1085, 0, 0, 0},               // 18:52 [0,0]

    {CEventSchedulerDayNumber_Tuesday, CEventSchedulerItemType_Sunset, 0, 30, 30, 1},               // sunset [-30,30]
    {CEventSchedulerDayNumber_Tuesday, CEventSchedulerItemType_Time, 1380, 30, 90, 0},              // 23:00 [-3,90]

    {CEventSchedulerDayNumber_Wednesday, CEventSchedulerItemType_Sunset, 0, 30, 30, 1},             // sunset [-30,30]
    {CEventSchedulerDayNumber_Wednesday, CEventSchedulerItemType_Time, 1380, 30, 90, 0},            // 23:00 [-3,90]

    {CEventSchedulerDayNumber_Thursday, CEventSchedulerItemType_Sunset, 0, 30, 30, 1},              // sunset [-30,30]
    {CEventSchedulerDayNumber_Thursday, CEventSchedulerItemType_Time, 1380, 30, 90, 0},             // 23:00 [-3,90]

    {CEventSchedulerDayNumber_Friday, CEventSchedulerItemType_Sunset, 0, 30, 30, 1},                // sunset [-30,30]
    {CEventSchedulerDayNumber_Friday, CEventSchedulerItemType_Time, 1380, 30, 90, 0},               // 23:00 [-3,90]

    {CEventSchedulerDayNumber_Saturday, CEventSchedulerItemType_Sunset, 0, 30, 30, 1},              // sunset [-30,30]
    {CEventSchedulerDayNumber_Sunday, CEventSchedulerItemType_Time, 60, 60, 60, 0},                // 1:00 [-60,60]
};

const double latitude = 52.303713;      // Netherlands
const double longitude = 5.259310;

int main() {
    
    doSunriseCalculationTests();

    doEventSchedulerTests();

    scheduleLoopTester();

    return 0;
}

void doSunriseCalculationTests() {
    time_t sunriseTime, sunsetTime; 
    // time_t currentTime = 1770573242; // time(nullptr);
    time_t currentTime = 1770508800; // time(nullptr);

    std::cout << "Sunrise Calculator Example\n\n";

    std::cout << "Current time: " << std::fixed << currentTime << " " << asctime(gmtime(&currentTime));
    std::cout << "Latitude: " << latitude << " Longitude: " << longitude << "\n\n";
    
    CSunriseCalculator sunrise(latitude, longitude);
    
    std::cout << "---------------------------------------------------------------\n";

    currentTime = 1770508800;
    std::cout << "Time: " << (int)currentTime << " " << asctime(gmtime(&currentTime));
    sunrise.sunRiseAndSetForTimestamp(currentTime, 3600, sunriseTime, sunsetTime);
    std::cout << "Sunrise: " << asctime(gmtime(&sunriseTime));
    std::cout << "Sunset: " << asctime(gmtime(&sunsetTime));

    std::cout << "\n";

    currentTime = 1770595200;
    std::cout << "Time: " << (int)currentTime << " " << asctime(gmtime(&currentTime));
    sunrise.sunRiseAndSetForTimestamp(currentTime, 3600, sunriseTime, sunsetTime);
    std::cout << "Sunrise: " << asctime(gmtime(&sunriseTime));
    std::cout << "Sunset: " << asctime(gmtime(&sunsetTime));

    std::cout << "\n";

    currentTime = 1770681600;
    std::cout << "Time: " << (int)currentTime << " " << asctime(gmtime(&currentTime));
    sunrise.sunRiseAndSetForTimestamp(currentTime, 3600, sunriseTime, sunsetTime);
    std::cout << "Sunrise: " << asctime(gmtime(&sunriseTime));
    std::cout << "Sunset: " << asctime(gmtime(&sunsetTime));

    std::cout << "\n";

    currentTime = 1770768000;
    std::cout << "Time: " << (int)currentTime << " " << asctime(gmtime(&currentTime));
    sunrise.sunRiseAndSetForTimestamp(currentTime, 3600, sunriseTime, sunsetTime);
    std::cout << "Sunrise: " << asctime(gmtime(&sunriseTime));
    std::cout << "Sunset: " << asctime(gmtime(&sunsetTime));

    std::cout << "\n";

    currentTime = 1770854400;
    std::cout << "Time: " << (int)currentTime << " " << asctime(gmtime(&currentTime));
    sunrise.sunRiseAndSetForTimestamp(currentTime, 3600, sunriseTime, sunsetTime);
    std::cout << "Sunrise: " << asctime(gmtime(&sunriseTime));
    std::cout << "Sunset: " << asctime(gmtime(&sunsetTime));

    std::cout << "\n";

    currentTime = 1770940800;
    std::cout << "Time: " << (int)currentTime << " " << asctime(gmtime(&currentTime));
    sunrise.sunRiseAndSetForTimestamp(currentTime, 3600, sunriseTime, sunsetTime);
    std::cout << "Sunrise: " << asctime(gmtime(&sunriseTime));
    std::cout << "Sunset: " << asctime(gmtime(&sunsetTime));

    std::cout << "\n";

    currentTime = 1771027200;
    std::cout << "Time: " << (int)currentTime << " " << asctime(gmtime(&currentTime));
    sunrise.sunRiseAndSetForTimestamp(currentTime, 3600, sunriseTime, sunsetTime);
    std::cout << "Sunrise: " << asctime(gmtime(&sunriseTime));
    std::cout << "Sunset: " << asctime(gmtime(&sunsetTime));

    std::cout << "---------------------------------------------------------------\n";
}

void doEventSchedulerTests() {
    
    std::cout << "Event Scheduler Example\n";

    time_t secondsFromGMT = 3600;

    CEventScheduler scheduler(latitude, longitude, secondsFromGMT, [](){ return time(nullptr); });

    std::cout << "Adding test items...\n";
    for (const auto& item : testItems) {
        scheduler.addItem(item);
    }

    bool isValid = false;
    CEventSchedulerItem foundItem;

    std::cout << "---------------------------------------------------------------\n";

    std::cout << "Finding: "; testItems[2].debugPrint();
    foundItem = scheduler.findItem(testItems[2]) ;
    std::cout << (foundItem == testItems[2] ? "Found" : "Not Found") << "\n";

    std::cout << "---------------------------------------------------------------\n";

    std::cout << "Finding: "; testItems[1].debugPrint();
    foundItem = scheduler.findItem(testItems[1]) ;
    std::cout << (foundItem == testItems[1] ? "Found" : "Not Found") << "\n";

    std::cout << "---------------------------------------------------------------\n";

    std::cout << "Removing: "; testItems[5].debugPrint();
    scheduler.removeItem(testItems[5]) ;

    std::cout << "---------------------------------------------------------------\n";

    std::cout << "Finding: "; testItems[5].debugPrint();
    foundItem = scheduler.findItem(testItems[5]) ;
    std::cout << (foundItem == testItems[5] ? "Found" : "Not Found") << "\n";

    std::cout << "---------------------------------------------------------------\n";

    scheduler.debugPrint();

    std::cout << "---------------------------------------------------------------\n";

    std::cout << "Adding: "; testItems[5].debugPrint();
    scheduler.addItem(testItems[5]) ;

    std::cout << "---------------------------------------------------------------\n";

    std::cout << "Finding: "; testItems[5].debugPrint();
    foundItem = scheduler.findItem(testItems[5]) ;
    std::cout << (foundItem == testItems[5] ? "Found" : "Not Found") << "\n";

    std::cout << "---------------------------------------------------------------\n";

    scheduler.debugPrint();

    time_t testTime = 0; // In GMT

    CEventSchedulerItem activeItem;
    CEventSchedulerItem nextActiveItem;

    std::cout << "---------------------------------------------------------------\n";

    // Epoch timestamp: 1770206400
    // Timestamp in milliseconds: 1770206400000
    // Date and time (GMT): Wednesday, February 4, 2026 12:00:00 PM
    // Date and time (your time zone): Wednesday, February 4, 2026 1:00:00 PM GMT+01:00
    testTime = 1770206400;  // Wednesday, February 4, 2026 12:00:00 PM GMT/
    std::cout << "Finding current and next active item with time " << asctime(gmtime(&testTime)) << " timestampGMT=" << testTime << " secondsFromGMT=" << secondsFromGMT << "\n";
    activeItem = scheduler.getActiveItem(testTime);
    nextActiveItem = scheduler.getNextActiveItem(testTime);
    std::cout << "  Current activate item: "; activeItem.debugPrint();
    std::cout << "  Next item to activate: "; nextActiveItem.debugPrint();

    std::cout << "---------------------------------------------------------------\n";

    testTime = 1770236345;  // Wednesday, February 4, 2026 7:59:05 PM GMT
    std::cout << "Finding current and next active item with time " << asctime(gmtime(&testTime)) << " timestampGMT=" << testTime << " secondsFromGMT=" << secondsFromGMT << "\n";
    activeItem = scheduler.getActiveItem(testTime);
    nextActiveItem = scheduler.getNextActiveItem(testTime);
    std::cout << "  Current activate item: "; activeItem.debugPrint();
    std::cout << "  Next item to activate: "; nextActiveItem.debugPrint();

    std::cout << "---------------------------------------------------------------\n";

    // // Epoch timestamp: 1770020345
    // // Timestamp in milliseconds: 1770020345000
    // // Date and time (GMT): Monday, February 2, 2026 8:19:05 AM
    // // Date and time (your time zone): Monday, February 2, 2026 9:19:05 AM GMT+01:00
    testTime = 1770020345;  // Monday, February 2, 2026 8:19:05 AM GMT
    std::cout << "Finding current and next active item with time " << asctime(gmtime(&testTime)) << " timestampGMT=" << testTime << " secondsFromGMT=" << secondsFromGMT << "\n";
    activeItem = scheduler.getActiveItem(testTime);
    nextActiveItem = scheduler.getNextActiveItem(testTime);
    std::cout << "  Current activate item: "; activeItem.debugPrint();
    std::cout << "  Next item to activate: "; nextActiveItem.debugPrint();

    std::cout << "---------------------------------------------------------------\n";

    // //  Epoch timestamp: 1770014114
    // // Timestamp in milliseconds: 1770014114000
    // // Date and time (GMT): Monday, February 2, 2026 6:35:14 AM
    // // Date and time (your time zone): Monday, February 2, 2026 7:35:14 AM GMT+01:00    testTime = 1770020345;  // Monday, February 2, 2026 8:19:05 AM GMT
    testTime = 1770014114;  // Monday, February 2, 2026 6:35:14 AM GMT
    std::cout << "Finding current and next active item with time " << asctime(gmtime(&testTime)) << " timestampGMT=" << testTime << " secondsFromGMT=" << secondsFromGMT << "\n";
    activeItem = scheduler.getActiveItem(testTime);
    nextActiveItem = scheduler.getNextActiveItem(testTime);
    std::cout << "  Current activate item: "; activeItem.debugPrint();
    std::cout << "  Next item to activate: "; nextActiveItem.debugPrint();

    std::cout << "---------------------------------------------------------------\n";

    testTime = time(nullptr);  // now
    std::cout << "Finding current and next active item with time " << asctime(gmtime(&testTime)) << " timestampGMT=" << testTime << " secondsFromGMT=" << secondsFromGMT << "\n";
    activeItem = scheduler.getActiveItem(testTime);
    nextActiveItem = scheduler.getNextActiveItem(testTime);
    std::cout << "  Current activate item: "; activeItem.debugPrint();
    std::cout << "  Next item to activate: "; nextActiveItem.debugPrint();

    std::cout << "---------------------------------------------------------------\n";
}

void scheduleLoopTester() {

    time_t secondsFromGMT = 3600;

    CEventScheduler scheduler(latitude, longitude, secondsFromGMT, [](){ return time(nullptr); });

    std::cout << "Adding test items...\n";
    for (const auto& item : testItems) {
        scheduler.addItem(item);
    }

    scheduler.debugPrint();
    
    std::cout << "---------------------------------------------------------------\n";

    time_t timestampGMT = time(nullptr);

    // TODO: Do we actually need to pass a secondsFromGMT to the sunrise calculator?
    // TODO: The scheduler basically does not work with the real time, but works with week days and
    // TODO: minutes from the start of a week day. The timezone is possibly necessary to calculate the
    // TODO: proper week day from the current time + timezone.
    // TODO: The timezone does also matter for the scheduler. 30 minutes into the start of the GMT
    // TODO: day is still 30 minutes before the start of the CET day, if daylight saving is off.
    // TODO: Need to make some use cases for this.

    time_t sunrise = scheduler.sunrise(timestampGMT) + secondsFromGMT;
    std::cout << "Sunrise today (local): " << asctime(gmtime(&sunrise)) << " timestampGMT=" << sunrise << " secondsFromGMT=" << secondsFromGMT << "\n";
    time_t sunset = scheduler.sunset(timestampGMT) + secondsFromGMT;
    std::cout << "Sunset today (local):  " << asctime(gmtime(&sunset)) << " timestampGMT=" << sunset << " secondsFromGMT=" << secondsFromGMT << "\n";

    std::cout << "---------------------------------------------------------------\n";

    CEventSchedulerItem prevActiveItem;
    CEventSchedulerItem prevNextActiveItem;

    while (true) {

        time_t timestampGMT = time(nullptr);
        time_t secondsFromGMT = scheduler.getSecondsFromGMT();

        CEventSchedulerItem activeItem = scheduler.getActiveItem(timestampGMT);
        CEventSchedulerItem nextActiveItem = scheduler.getNextActiveItem(timestampGMT);

        if (!(activeItem == prevActiveItem)) {
            std::cout << "[" << asctime(gmtime(&timestampGMT)) << "] " << "New item was activated: ";
            activeItem.debugPrint();
            std::cout << "[" << asctime(gmtime(&timestampGMT)) << "] " << "Next item to activate: ";
            nextActiveItem.debugPrint();

            prevActiveItem = activeItem;
            prevNextActiveItem = nextActiveItem;
        }
        else {
            std::cout << "[" << asctime(gmtime(&timestampGMT)) << "] " << ". still active\n";
        }

        sleep(10);
    }
}