/**
 * File:        Rating.cpp
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Source Code file for Rating.h that holds the code for the
 *              readFile() function.
 *
 * Version:     v1.0 - created
 *              v2.0 - readFile added
 *              v2.1 - polished and commented
 */

#include "Rating.h"
#include <fstream>

namespace rating {
    //Open and Scrape "ratings.txt" and popuplate the Ratings Database.
    RatingDB readFile() {
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
