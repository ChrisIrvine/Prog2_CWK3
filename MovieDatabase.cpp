/**
 *
 */
#include <iostream>
#include <fstream>
#include "Movie.h"
#include "MovieDatabase.h"

namespace movieDatabase {

    MovieDatabase MovieDatabase::readFile() {
        //Create a new MovieDatabase object
        MovieDatabase mvdb;

        std::fstream mFile;
        mFile.open("../movies.txt");

        if (mFile.is_open()) {
            while (mFile.good() && mFile.peek() == '"') {
                movie::Movie next;

                mFile >> next;
                mFile.get(); //get the new line special character

                mvdb.add(next);
            }
        }
        return mvdb;
    }

    std::ostream &operator<<(std::ostream &ostream
            , MovieDatabase &mvdb) {
        for(std::vector<movie::Movie>::iterator i = mvdb.mvdb.begin();
            i != mvdb.mvdb.end(); ++i) {
            ostream << *i << std::endl;
        }
        return ostream;
    }
}
