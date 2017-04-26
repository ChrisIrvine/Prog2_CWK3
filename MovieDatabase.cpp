/**
 * File:        MovieDatabase.cpp
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Source code file for MovieDatabase.h, containing details for
 *              the output operator overloading and the readFile() methods.
 *
 * Version:     v1.0 - Created.
 *              v2.0 - readFile method added
 *              v3.0 - experimented with operator overloading location
 *              v3.1 - polished and commented
 */
#include <iostream>
#include <fstream>
#include "Movie.h"
#include "MovieDatabase.h"

namespace movieDatabase {

    //Scrape the "movies.txt" file and populate the Movie Database.
    MovieDatabase readFile() {
        MovieDatabase mvdb;
        std::fstream mFile;
        mFile.open("../movies.txt");

        if (mFile.is_open()) {
            while (mFile.good() && mFile.peek() == '"') {
                movie::Movie next;
                mFile >> next;
                mFile.get();
                mvdb.add(next);
            }
        }
        return mvdb;
    }

    //Overload the output operator to iterate over the database, printing each
    //Movie object
    std::ostream &operator<<(std::ostream &ostream, MovieDatabase &mvdb) {
        for(std::vector<movie::Movie>::iterator i = mvdb.mvdb.begin();
            i != mvdb.mvdb.end(); ++i) {
            ostream << *i << std::endl;
        }
        return ostream;
    }
}
