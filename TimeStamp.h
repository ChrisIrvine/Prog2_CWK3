/**
 * File:        TimeStamp.h
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Header file for TimeStamp.cpp, that contains the definitions
 *              and inline methods as well as the overloaded comparison
 *              operator method.
 *
 * Version:     v1.0 - created
 *              v2.0 - overloaded operators added
 *              v3.0 - reworked overloaded input operator
 *              v3.1 - polished and commented
 */

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
         * Procedure:   TimeStamp(0, 0, 0, 0, 0, 0)
         *
         * Description: Defined Default Constructor method that returns a blank
         *              TimeStamp object.
         *
         * Returns:     Blank TimeStamp object
         *
         * Parameters:  N/A
         */
        inline TimeStamp() : TimeStamp(0, 0, 0, 0, 0, 0) { }

        /**
         * Procedure:   TimeStamp(std::uint64_t year, std::uint64_t month,
         *              std::uint64_t day, std::uint64_t hour, std::uint64_t
         *              minute, std::uint64_t second)
         *
         * Description: Customised constructor that returns a user/program
         *              defined TimeStamp object.
         *
         * Returns:     User/Program defined TimeStamp Object
         *
         * Parameters:
         * @param year - year of review
         * @param month - month of review
         * @param day - day of review
         * @param hour - hour of review
         * @param minute - minute of review
         * @param second - second of review
         */
        TimeStamp(std::uint64_t year, std::uint64_t month, std::uint64_t day,
            std::uint64_t hour, std::uint64_t minute, std::uint64_t second);

        /**
         * Procedure:   operator=(const TimeStamp copyStamp)
         *
         * Description: Overload the assignment operator to act as a copy
         *              constructor.
         *
         * Returns:     Duplicate TimeStamp Object.
         *
         * Parameters:
         * @param copyStamp
         * @return - Duplicated TimeStamp Object
         */
        TimeStamp& operator=(const TimeStamp copyStamp);

        /**
         * Procedure:   TimeStamp(const TimeStamp& copyStamp)
         *
         * Description: Copy Constructor. Uses the customised constructor.
         *
         * Returns:     Duplicated TimeStamp Object (based off copyStamp)
         *
         * Parameters:
         * @param copyStamp - TimeStamp to copy
         */
        inline TimeStamp(const TimeStamp& copyStamp) :
                TimeStamp(copyStamp.year, copyStamp.month, copyStamp.day,
                copyStamp.hour, copyStamp.minute, copyStamp.second) {
        }

        /**
         * Procedure:   ~TimeStamp()
         *
         * Description: Destructor Method, but is not needed as project is
         *              stack not heap.
         *
         * Returns:     N/A
         *
         * Parameters:  N/A
         */
        inline ~TimeStamp() { }

        /**
         * Procedure:   TimeStamp(std::uint64_t grandTotalSeconds)
         *
         * Description: Constructor that takes seconds and breaks that down
         *              into the correct amount of years, months, days, hours,
         *              minutes and seconds during object construction.
         *
         * Returns:     new TimeStamp object
         *
         * Parameters:
         * @param grandTotalSeconds - grand total number of seconds of the TS.
         */
        inline TimeStamp(std::uint64_t grandTotalSeconds) { }


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
     * Procedure:   operator<(TimeStamp& t1, TimeStamp& t2)
     *
     * Description: Overload the comparison operator so that TimeStamp objects
     *              are compared only using the total number of seconds.
     *
     * Returns:     true is t1 is smaller than t2, false otherwise.
     *
     * Parameters:
     * @param t1 - the first TimeStamp object to compare
     * @param t2 - the second TimeStamp object to compare
     * @return - true if t1 is smaller, false if otherwise
     */
    inline bool operator<(TimeStamp& t1, TimeStamp& t2) {
        return t1.totalSeconds() < t2.totalSeconds();
    }
}
#endif //PROG2_CWK3_TIMESTAMP_H
