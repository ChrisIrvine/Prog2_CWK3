//
// Created by Christopher Irvine on 28/03/2017.
//

#ifndef PROG2_CWK3_MOVIEDATABASE_H
#define PROG2_CWK3_MOVIEDATABASE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include "Movie.h"

namespace movieDatabase {
    class MovieDatabase {
    public:
        /**
         * Procedure:   MovieDatabase()
         *
         * Description: Default constructor that creates an empty MovieDatabase
         *              object.
         *
         * Returns:     Empty MovieDatabase object.
         *
         * Parameters:  N/A
         */
        inline MovieDatabase() {
        }

        /**
         * Procedure:   MovieDatabase(const MovieDatabase &copyDB)
         *
         * Description: Copy Constructor that will create a new MovieDatabase
         *              object containing all the movie object held within the
         *              target MovieDatabase.
         *
         * Returns:     New duplicated MovieDatabase Object.
         *
         * Parameters:
         * @param copyDB - MovieDatabase copied.
         */
        inline MovieDatabase(const MovieDatabase &copyDB) {
            mvdb = copyDB.mvdb;
        }

        /**
         * Procedure:   ~MovieDatabase()
         *
         * Description: Destructor, but not needed for memory management in
         *              this project.
         *
         * Returns:     Destructed MovieDatabase object.
         *
         * Parameters:  N/A
         */
        inline ~MovieDatabase() { };

        /**
         * Procedure:   operator= (const MovieDatabase &copyDB)
         *
         * Description: Inline overload assignment operator that copies the
         *              MovieDatabase.
         *
         * Returns:     A new MovieDatabase object containing all the data held
         *              within the database to copy from.
         *
         * Parameters:
         * @param copyDB - the MovieDatabase object to copy from
         * @return - a new MovieDatabase object containing copied data.
         */
        inline MovieDatabase& operator= (const MovieDatabase &copyDB) {
            mvdb = copyDB.mvdb;
            return *this;
        }

        /**
         * Method to retrieve the size of the MovieDatabase
         * @return - an unsigned long int representing the size of the DB.
         */
        inline unsigned long size() {
            return mvdb.size();
        }


        /**
         * Procedure:   add (movie::Movie& movie)
         *
         * Description: Inlined add method to push a new movie object to the
         *              back of the vector, using the .push_back method from
         *              vectors.
         *
         * Returns:     N/A
         *
         * Parameters:
         * @param movie - Movie object to be added
         */
        inline void add (movie::Movie& movie) {
            mvdb.push_back(movie::Movie(movie));
        }

        /**
         * Procedure:   operator[] (unsigned long index)
         *
         * Description: Inline overload method to grab a movie object at a
         *              specific place in the MovieDatabase, using the .at
         *              method from vectors.
         *
         * Returns:     A movie object pulled from the MovieDatabase.
         *
         * Parameters:
         * @param index - position of the movie to be pulled
         * @return - movie object pulled from the MovieDatabase.
         */
        inline movie::Movie& operator[](unsigned long index) {
            return mvdb.at(index);
        }

        /**
         * Procedure:   sort()
         *
         * Description: Inline sort method to sort movies into ascending order,
         *              using the sort method from the standard library.
         *
         * Returns:     N/A
         *
         * Parameters:  N/A
         */
        inline void sort() {
            std::sort(mvdb.begin(), mvdb.end());
        }

        /**
         * Procedure:   sort(std::function<bool(movie::Movie&, movie::Movie&
         *              > comparator)
         *
         * Description: Inline sort method that uses a lambda sort function to
         *              compare 2 movie objects.
         *
         * Returns:     N/A
         *
         * Parameters:
         * @param comparator - what to compare the movie objects against.
         */
        inline void sort(std::function<bool(movie::Movie&, movie::Movie&)
            > comparator) {
            std::sort(mvdb.begin(), mvdb.end(), comparator);
        }

        /**
         * Procedure:   find(std::function<bool(movie::Movie&) > mustAdd)
         *
         * Description: find method that sends movie to a lambda function and
         *              must add it to a new Database if the lambda returns
         *              true. Returns a new MovieDatabase object.
         *
         * Returns:     MovieDatabase object containing the found objects.
         *
         * Parameters:
         * @param mustAdd
         * @return
         */
        inline MovieDatabase find(std::function<bool(movie::Movie&)
            > mustAdd) {
            MovieDatabase newDB;

            for(std::vector<movie::Movie>::iterator i = mvdb.begin();
                i != mvdb.end();
                ++i) {
                if (mustAdd(*i)) newDB.add(*i);
            }
            return newDB;
        }


        /**
         *
         * @param ostream
         * @param mvdb
         * @return
         */
        friend std::ostream& operator<<(std::ostream& ostream
                , MovieDatabase& mvdb);

        MovieDatabase readFile();

    private:
        std:: vector<movie::Movie> mvdb;
    };

}

#endif //PROG2_CWK3_MOVIEDATABASE_H
