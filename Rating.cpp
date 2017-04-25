/**
 *
 */

#include "Rating.h"
#include <cctype>
#include <fstream>
#include <string>
#include <iostream>

namespace rating {

    RatingDB RatingDB::readFile() {
        RatingDB rDB;

        std::fstream ratingFile;
        ratingFile.open("../ratings.txt");

        if (ratingFile.is_open()) {
            while (ratingFile.good() && std::isdigit(ratingFile.peek())) {
                Rating next;

                ratingFile >> next;
                ratingFile.get();

                rDB.add(next);
            }
        }
        return rDB;
    }
}
