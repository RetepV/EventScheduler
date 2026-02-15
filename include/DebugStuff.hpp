#pragma once

#include "EventScheduler.hpp"

class CDebugStuff {
public:
    static const char * const toString(CEventSchedulerWeekDay day) {
        switch (day) {
            case CEventSchedulerDayNumber_Uninitialized: return "Uninitialized";
            case CEventSchedulerDayNumber_Sunday: return "Sunday";
            case CEventSchedulerDayNumber_Monday: return "Monday";
            case CEventSchedulerDayNumber_Tuesday: return "Tuesday";
            case CEventSchedulerDayNumber_Wednesday: return "Wednesday";
            case CEventSchedulerDayNumber_Thursday: return "Thursday";
            case CEventSchedulerDayNumber_Friday: return "Friday";
            case CEventSchedulerDayNumber_Saturday: return "Saturday";
            default: return "Unknown";
        }
    }

    static const char * const toString(CEventSchedulerItemType type) {
        switch (type) {
            case CEventSchedulerItemType_Spare: return "Spare";
            case CEventSchedulerItemType_Time: return "Time";
            case CEventSchedulerItemType_Sunrise: return "Sunrise";
            case CEventSchedulerItemType_Sunset: return "Sunset";
            default: return "Unknown";
        }
    }

    
};