/**
 * File:        Rating.h
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Header file for Rating.cpp, that contains the inline methods
 *              for the Rating and RatingDB classes. Including constructors,
 *              overload and navigatory methods.
 *
 * Version:     v1.0 - created
 *              v2.0 - Rating class added and populated with basic methods
 *              v2.1 - copy constructor defined
 *              v3.0 - operator overloading for Rating class added
 *              v4.0 - RatingDB class added, basic methods added.
 *              v4.1 - readFile and navigatory methods added
 *              v4.2 - operator overloading added
 *              v5.0 - polished and commented.
 */

#ifndef PROG2_CWK3_RATING_H
#define PROG2_CWK3_RATING_H
#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include "TimeStamp.h"

namespace rating {
    /**
     * Class:       Rating
     *
     * Description: Core component of the Rating Database, functions in a
     *              similar manner to the Movie Object.
     */
    class Rating {
    public:
        /**
         * Procedure:   Rating()
         *
         * Description: Default Constructor that returns an empty Rating Object
         *
         * Returns:     Empty Rating Object
         *
         * Parameters:  N/A
         */
        inline Rating() { }

        /**
         * Procedure:   ~Rating()
         *
         * Description: Destructor method for memory management, but not needed
         *              as project is heap not stack.
         *
         * Returns:     N/A
         *
         * Parameters:  N/A
         */
        inline ~Rating() { }

        /**
         * Procedure:   Rating(std::string& movie, std::string& user,
         *                      timestamp::TimeStamp ts, int& score)
         *
         * Description: Customised Constructor that creates a user/program
         *              defined Rating object.
         *
         * Returns:     Full Rating Object as defined by user/program
         *
         * Parameters:
         * @param movie - movie title
         * @param user - name of the user who gave the rating
         * @param timeStamp - time of the review
         * @param score - score the user gave
         */
        inline Rating(std::string& movie, std::string& user
                , timestamp::TimeStamp ts, int& score) {
            this->movie = movie;
            this->user = user;
            this->ts = ts;
            this->score = score;
        }

        /**
         * Procedure:   Rating(cost Rating& rating)
         *
         * Description: Copy Constructor that duplicates an existing Rating
         *              Object.
         *
         * Returns:     Duplicated Rating Object
         *
         * Parameters:
         * @param rating - Rating Object to be duplicated
         */
        inline Rating(const Rating& rating) {
            this->movie = rating.movie;
            this->user = rating.user;
            this->ts = rating.ts;
            this->score = rating.score;
        }

        /**
         * Procedure:   operator=(const Rating& rating)
         *
         * Description: Overload the assignment operator so that it acts like
         *              the copy constructor.
         *
         * Returns:     A duplicated Rating Object.
         *
         * Parameters:
         * @param rating - Rating Object to duplicate
         * @return - duplicated rating object
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

    /**
     * Procedure:   operator>>(std::istream& istream, Rating& rating)
     *
     * Description: Overload the input operator to take a scraped line from
     *              "ratings.txt" and break it down into the component parts
     *              then assign those parts to the appropriate class variables.
     *              Done using .get(), .getline() and >>.
     *
     * Returns:     An input stream containing a filled rating object.
     *
     * Parameters:
     * @param istream - input stream
     * @param rating - rating object to be filled
     * @return - filled rating object
     */
    inline std::istream& operator>>(std::istream& istream, Rating& rating) {
        istream >> rating.ts;
        istream.get(); //unwanted character
        istream.get(); //unwanted character

        std::getline(istream, rating.user, '"');
        istream.get(); //unwanted character
        istream.get(); //unwanted character

        std::getline(istream, rating.movie, '"');
        istream.get(); //unwanted character

        istream >> rating.score;
        istream.get(); //unwanted character
        return istream;
    }

    /**
     * Procedure:   operator<<(std::ostream& ostream, Rating& rating)
     *
     * Description: Overload the output operator so that when printing out an
     *              accurate representation, as formatted by the "ratings.txt"
     *              file is used.
     *
     * Returns:     A formatted representation of the Rating Object within an
     *              output stream..
     *
     * Parameters:
     * @param ostream - output stream
     * @param rating - Rating Object to represent
     * @return - representation of rating
     */
    inline std::ostream& operator<<(std::ostream& ostream, Rating& rating) {
        ostream << rating.ts << ",\"" << rating.user << "\",\""
                << rating.movie << "\"," << rating.score;
        return ostream;
    }

    /**
     * Class:       RatingDB
     *
     * Description: Vector Database Class for the Rating class;  contains
     *              navigatory methods, overload methods and scrape methods.
     */
    class RatingDB {
    public:
        /**
         * Procedure:   RatingDB()
         *
         * Description: Default Constructor
         *
         * Returns:     Empty RatingDB object
         *
         * Parameters:  N/A
         */
        inline RatingDB() {}

        /**
         * Procedure:   ~RatingDB()
         *
         * Description: Destructor method, but as project is heap not stack
         *              there is no need fro this method.
         *
         * Returns:     N/A
         *
         * Parameters:  N/A
         */
        inline ~RatingDB() {}

        /**
         * Procedure:   RatingDB(const RatingDB& rDB)
         *
         * Description: Copy Constructor method
         *
         * Returns:     Duplicated RatingDB object
         *
         * Parameters:
         * @param rDB - RatingDB object to duplicate
         */
        inline RatingDB(const RatingDB& rDB) {
            this->ratingDB = rDB.ratingDB;
        }

        /**
         * Procedure:   operator=(const RatingDB& rDB)
         *
         * Description: Overload the assignment operator so that it functions
         *              exactly like a Copy Constructor method.
         *
         * Returns:     A duplicated RatingDB method
         *
         * Parameters:
         * @param rDB - RatingDB object to duplicate
         * @return - duplicated RatingDB object
         */
        inline RatingDB& operator=(const RatingDB& rDB) {
            this->ratingDB = rDB.ratingDB;
            return *this;
        }

        /**
         * Procedure:   size()
         *
         * Description: Returns the current size of the RatingDB vector
         *
         * Returns:     current vector size
         *
         * Parameters:  N/A
         * @return - current vector size
         */
        inline size_t size() {
            return ratingDB.size();
        }

        /**
         * Procedure:   add(Rating& rDB)
         *
         * Description: Method to add a new Rating to the Rating Database by
         *              using the .push_back() method.
         *
         * Returns:     N/A
         *
         * Parameters:
         * @param rDB - Rating to add
         */
        inline void add(Rating& rat) {
            ratingDB.push_back(Rating(rat));
        }

        /**
         * Procedure:   operator[](size_t index)
         *
         * Description: Overload the index operator so that it will return the
         *              object held at a given index within the vector.
         *
         * Returns:     Object at index position
         *
         * Parameters:
         * @param index - Position of the Object to retrieve
         * @return - Object at index position
         */
        inline Rating& operator[](size_t index) {
            return ratingDB.at(index);
        }

        /**
         * Procedure:   sort(std::function<bool(Rating&, Rating&) > comparator)
         *
         * Description: Allows the RatingDB to be sorted by comparison of any
         *              given class variable.
         *
         * Return:      N/A
         *
         * Parameters:
         * @param comparator - class variable to compare with
         */
        inline void sort(std::function<bool(Rating&, Rating&) > comparator) {
            std::sort(ratingDB.begin(), ratingDB.end(), comparator);
        }

        /**
         * Procedure:   find(std::function<bool(Rating&) > mustAdd)
         *
         * Description: Allow the retrieval of any given element within the
         *              RatingDB object and add it to a new RatingDB object.
         *
         * Returns:     A new RatingDB object containing the refined Database
         *
         * Parameters:
         * @param mustAdd - the variable to search for
         * @return - refined database
         */
        inline RatingDB find(std::function<bool(Rating&) > mustAdd) {
            RatingDB newRDB;
            for(std::vector<Rating>::iterator i = ratingDB.begin();
                i != ratingDB.end(); ++i) {
                if(mustAdd(*i)) newRDB.add(*i);
            }
            return newRDB;
        }

        friend std::ostream& operator<<(std::ostream& ostream, RatingDB& rDB);

    private:
        std::vector<Rating> ratingDB;
    };

    /**
     * Procedure:  readFile()
     *
     * Description: First, the method opens the "ratings.txt" file and prepares
     *              to scrape the data from the file - line by line - using
     *              operator overloading that is native to the object held
     *              within the database.
     *
     * Returns:     Filled Database
     *
     * Parameters:  N/A
     */
    RatingDB readFile();

    /**
     * Procedure:   operator<<(std::ostream& ostream, RatingDB& rDB)
     *
     * Description: Overload the output operator to iterate through the Rating
     *              Database and use the Rating output operator overload to
     *              print out a representation of each Rating object, that is
     *              then stored in an output stream.
     *
     * Returns:     An output stream containing a ready-to-print representation
     *              of the Rating Database.
     *
     * Parameters:
     * @param ostream - Output stream
     * @param rDB - Rating Database to print out
     * @return - Output stream containing representation of the Rating Database
     */
    inline std::ostream& operator<<(std::ostream& ostream, RatingDB& rDB) {
        for (std::vector<Rating>::iterator i = rDB.ratingDB.begin();
                i != rDB.ratingDB.end(); ++i) {
            ostream << *i << std::endl;
        }
        return ostream;
    }
}

#endif //PROG2_CWK3_RATING_H