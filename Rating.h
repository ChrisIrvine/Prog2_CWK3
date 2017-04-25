//
// Created by Christopher Irvine on 28/03/2017.
//

#ifndef PROG2_CWK3_RATING_H
#define PROG2_CWK3_RATING_H
#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include "TimeStamp.h"

namespace rating {
    class Rating {
    public:
        /**
         * Default Constructor
         */
        inline Rating() {
        }

        /**
         * Destructor
         */
        inline ~Rating() {
        }

        /**
         * Customisable constructor
         * @param movie
         * @param user
         * @param timeStamp
         * @param score
         */
        inline Rating(std::string& movie, std::string& user
                , timestamp::TimeStamp ts, int& score) {
            this->movie = movie;
            this->user = user;
            this->ts = ts;
            this->score = score;
        }

        inline Rating(const Rating& rating) {
            this->movie = rating.movie;
            this->user = rating.user;
            this->ts = rating.ts;
            this->score = rating.score;
        }

        /**
         * Overload assignment operator
         * @param rating
         * @return
         */
        inline Rating& operator=(const Rating& rating) {
            this->movie = rating.movie;
            this->user = rating.user;
            this->ts = rating.ts;
            this->score = rating.score;
        }

        //Movie getters and setters
        inline std::string& getMovie() {return this->movie;}
        inline void setMovie(std::string& newMovie) {this->movie = newMovie;}

        //User getters and setters
        inline std::string& getUser() {return this->user;}
        inline void setUser(std::string& newUser) {this->user = newUser;}

        //TimeStamp getters and setters
        inline timestamp::TimeStamp & getTS() {return this->ts;}
        inline void setTS(timestamp::TimeStamp newTS) {this->ts = newTS;}

        //Score getters and setters
        inline int getScore() {return this->score;}
        inline void setScore(int newScore) {this->score = newScore;}

        friend std::ostream& operator<<(std::ostream& ostream, Rating& rating);
        friend std::istream& operator>>(std::istream& istream, Rating& rating);
    private:
        std::string movie;
        std::string user;
        timestamp::TimeStamp ts;
        int score;
    };

    inline std::istream& operator>>(std::istream& istream, Rating& rating) {
        istream >> rating.ts;
        istream.get();
        istream.get();

        std::getline(istream, rating.user, '"');
        istream.get();
        istream.get();

        std::getline(istream, rating.movie, '"');
        istream.get();

        istream >> rating.score;
        return istream;
    }

    inline std::ostream& operator<<(std::ostream& ostream, Rating& rating) {
        ostream << rating.ts << ",\"" << rating.user << "\",\""
                << rating.movie << "\"," << rating.score;

        return ostream;
    }

    class RatingDB {
    public:
        /**
         * Default Constructor
         */
        inline RatingDB() {}

        /**
         * Destructor
         */
        inline ~RatingDB() {}

        /**
         * Copy Constructor
         * @param rating
         */
        inline RatingDB(const RatingDB& rDB) {
            this->ratingDB = rDB.ratingDB;
        }

        /**
         * Overload assignment operator
         * @param rating
         * @return
         */
        inline RatingDB& operator=(const RatingDB& rDB) {
            this->ratingDB = rDB.ratingDB;
            return *this;
        }

        inline size_t size() {
            return ratingDB.size();
        }

        inline void add(Rating& rDB) {
            ratingDB.push_back(Rating(rDB));
        }

        inline Rating& operator[](size_t index) {
            return ratingDB.at(index);
        }

        inline void sort(std::function<bool(Rating&, Rating&) > comparator) {
            std::sort(ratingDB.begin(), ratingDB.end(), comparator);
        }

        inline RatingDB find(std::function<bool(Rating&) > mustAdd) {
            RatingDB newRDB;

            for(std::vector<Rating>::iterator i = ratingDB.begin();
                i != ratingDB.end(); ++i) {
                if(mustAdd(*i)) newRDB.add(*i);
            }
            return newRDB;
        }

        friend std::ostream& operator<<(std::ostream& ostream, RatingDB& rDB);

        RatingDB readFile();

    private:
        std::vector<Rating> ratingDB;
    };

    inline std::ostream& operator<<(std::ostream& ostream, RatingDB& rDB) {
        for (std::vector<Rating>::iterator i = rDB.ratingDB.begin();
                i != rDB.ratingDB.end(); ++i) {
            ostream << *i << std::endl;
        }
        return ostream;
    }
}


#endif //PROG2_CWK3_RATING_H
