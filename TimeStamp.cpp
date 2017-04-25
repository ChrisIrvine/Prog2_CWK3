/**
 *
 */

#include <cstdint>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "TimeStamp.h"

namespace timestamp {
    TimeStamp::TimeStamp(std::uint64_t year, std::uint64_t month,
                         std::uint64_t day, std::uint64_t hour,
                         std::uint64_t minute, std::uint64_t second) {
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    TimeStamp &TimeStamp::operator=(const TimeStamp copyStamp) {
        this->year = copyStamp.year;
        this->month = copyStamp.month;
        this->day = copyStamp.day;
        this->hour = copyStamp.hour;
        this->minute = copyStamp.minute;
        this->second = copyStamp.second;
        return *this;
    }

    std::uint64_t TimeStamp::totalSeconds() {
        std::uint64_t yearSeconds = year*60*60*24*365;
        std::uint64_t monthSeconds = month*60*60*24*31;
        std::uint64_t daySeconds = day*60*60*24;
        std::uint64_t hourSeconds = hour*60*60;
        std::uint64_t minuteSeconds = minute*60;

        return yearSeconds + monthSeconds + daySeconds + hourSeconds
               + minuteSeconds + second;
    }

    std::istream& operator>>(std::istream &istream, TimeStamp &timeStamp) {
        istream >> timeStamp.day; //Scrape the day data
        istream.get(); // Get rid of the /

        istream >> timeStamp.month; //Scrape the month data
        istream.get(); // Get rid of the /

        istream >> timeStamp.year; //Scrape the year data
        istream.get(); //Get rid of the T

        istream >> timeStamp.hour; //Scrape the hour data
        istream.get(); //Get rid of the :

        istream >> timeStamp.minute; //Scrape the minute data
        istream.get(); //Get rid of the :

        istream >> timeStamp.second; //Scrape the second data
        istream.get(); //Get rid of the Z

        return istream;
    }

    std::ostream& operator<<(std::ostream &ostream, TimeStamp &timeStamp) {
        ostream << std::setfill('0') << std::setw(2);
        ostream << timeStamp.day << "/" << std::setfill('0') << std::setw(2)
                << timeStamp.month << "/";

        ostream << std::setw(4) << std::setfill('0') << timeStamp.year << "T";

        ostream << std::setw(2) << std::setfill('0') << timeStamp.hour << ":"
                << std::setw(2) << std::setfill('0') << timeStamp.minute << ":"
                << std::setw(2) << std::setfill('0')
                << timeStamp.second << "Z";

        return ostream;
    }

    TimeStamp operator+(TimeStamp &t1, TimeStamp &t2) {
        std::uint64_t grandTotalSeconds = t1.totalSeconds() + t2.totalSeconds();
        TimeStamp timeStamp(grandTotalSeconds);
        return timeStamp;
    }
}
