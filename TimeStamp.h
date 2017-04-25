//
// Created by Christopher Irvine on 28/03/2017.
//

#include <cstdint>
#include <iostream>
#include <string>
#include <iomanip>
#ifndef PROG2_CWK3_TIMESTAMP_H
#define PROG2_CWK3_TIMESTAMP_H

namespace timestamp {
    class TimeStamp {
    public:
        /**
         * Default Constructor
         */
        inline TimeStamp() : TimeStamp(0, 0, 0, 0, 0, 0) {
        }

        inline TimeStamp(std::uint64_t grandTotalSeconds) {

        }

        /**
         * Customised constructor
         * @param year
         * @param month
         * @param day
         * @param hour
         * @param minute
         * @param second
         */
        TimeStamp(std::uint64_t year, std::uint64_t month, std::uint64_t day,
            std::uint64_t hour, std::uint64_t minute, std::uint64_t second);

        /**
         * Assignment overload to copy the TimeStamp object.
         * @param copyStamp
         * @return
         */
        TimeStamp& operator=(const TimeStamp copyStamp);

        /**
         * Copy Constructor
         * @param copyStamp
         */
        inline TimeStamp(const TimeStamp& copyStamp) :
                TimeStamp(copyStamp.year, copyStamp.month, copyStamp.day,
                copyStamp.hour, copyStamp.minute, copyStamp.second) {
        }

        /**
         * Destructor constructor
         */
        inline ~TimeStamp() { }

        //Year Getters and Setters
        inline std::uint64_t& getYear() {return this->year;}
        inline void setYear(std::uint64_t& newYear) {this->year = newYear;}

        //Month Getters and Setters
        inline std::uint64_t& getMonth() {return this->month;}
        inline void setMonth(std::uint64_t& newMonth) {this->month = newMonth;}

        //Day Getters and Setters
        inline std::uint64_t& getDay() {return this->day;}
        inline void setDay(std::uint64_t& newDay) {this->day = newDay;}

        //Hour Getters and Setters
        inline std::uint64_t& getHour() {return this->hour;}
        inline void setHour(std::uint64_t& newHour) {this->hour = newHour;}

        //Minute Getters and Setters
        inline std::uint64_t getMinute() {return this->minute;}
        inline void setMinute(std::uint64_t& newMinute) {
            this->minute = newMinute;
        }

        //Second Getters and Setters
        inline std::uint64_t getSecond() {return this->second;}
        inline void setSecond(std::uint64_t& newSecond) {
            this->second = newSecond;
        }

        std::uint64_t totalSeconds();

        //Using friend to allow access to private class variables.
        friend std::istream& operator>>(std::istream& istream, TimeStamp& timeStamp);
        friend std::ostream& operator<<(std::ostream& stream, TimeStamp& timeStamp);
        friend TimeStamp operator+(TimeStamp& t1, TimeStamp& t2);

    private:
        std::uint64_t year;
        std::uint64_t month;
        std::uint64_t day;
        std::uint64_t hour;
        std::uint64_t minute;
        std::uint64_t second;
    };

    std::istream& operator>>(std::istream& istream, TimeStamp& timeStamp);
    std::ostream& operator<<(std::ostream& ostream, TimeStamp& timeStamp);
    TimeStamp operator+(TimeStamp& t1, TimeStamp& t2);

    /**
     *
     * @param t1
     * @param t2
     * @return
     */
    inline bool operator<(TimeStamp& t1, TimeStamp& t2) {
        return t1.totalSeconds() < t2.totalSeconds();
    }
}
#endif //PROG2_CWK3_TIMESTAMP_H
