/**
 * File:        main.cpp
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Driving file for the second programming coursework.
 *              Create the MovieDatabase and the Ratings objects, scraping data
 *              from movies.txt and ratings.txt then process the Rating object
 *              to apply the ratings to the movie objects held within the
 *              MovieDatabase.
 *
 * Version:     v1.0 - 30/03/2017 - created
 *              v2.0 - 15/04/2017 - recreated for testing purposes
 *              v3.0 - 20/04/2017 - reworked to run task 1
 *              v3.1 - 20/04/2017 - reworked to run task 2
 *              v3.2 - 21/04/2017 - reworked to run task 3 and 4
 *              v3.3 - 23/04/2017 - reworked to run task 5 and 6
 *              v3.4 - 24/04/2017 - polished and commented
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "TimeStamp.h"
#include "MovieDatabase.h"
#include "Rating.h"
#include "Movie.h"

/**
 * Task 1. Sort movies in ascending order of release date and display on the
 * console.
 * @param mvdb - The MovieDatabase object to search through
 */
void task1(movieDatabase::MovieDatabase& mvdb) {
    std::cout << "The Movies contained within the MovieDatabase in order of "
            "release data:" << std::endl;
    mvdb.sort();
    std::cout << mvdb << std::endl;
}

/**
 * Task 2. Display the 3rd Longest 'Film-Noir' Movie
 * @param mvdb - The MovieDatabase object to search through
 */
void task2(movieDatabase::MovieDatabase& mvdb) {
    std::cout << "The Third Longest 'Film-Noir' Movie is: " << std::endl;

    //Create a new database just for the movies that are Film-Noir
    movieDatabase::MovieDatabase filmNoir =
            mvdb.find([](movie::Movie &movie) {
        return movie.getGenre().filmnoir == true;
    });

    //Sort the movies by descending runtime order
    filmNoir.sort([](movie::Movie& m1, movie::Movie& m2) {
        return m1.getRuntime() > m2.getRuntime();
    });

    //Print out the third movie in the Film-Noir database
    std::cout << filmNoir[2] << std::endl;
}

/**
 * Task 3. Display the 10th highest rated 'Sci-Fi' film
 * @param mvdb - The MovieDatabase to search through
 */
void task3(movieDatabase::MovieDatabase& mvdb) {
    std::cout << "The 10th highest rated Science-Fiction film in the database"
            " is:" << std::endl;

    //Create a new MovieDatabase for the ScienceFiction movies
    movieDatabase::MovieDatabase scienceFiction =
            mvdb.find([](movie::Movie &movie) {
        return movie.getGenre().scifi;
    });

    //Sort them by decreasing ratings
    scienceFiction.sort([](movie::Movie& m1, movie::Movie& m2) {
        return m1.getRating() > m2.getRating();
    });

    //Print out the 10th object within the ScienceFiction MovieDatabase
    std::cout << scienceFiction[9] << std::endl;
}

/**
 * Task 4. Display the highest rated film
 * @param mvdb
 */
void task4(movieDatabase::MovieDatabase& mvdb) {
    std::cout << "The highest rated movie within the MovieDatabase is: "
              << std::endl;

    //Set it so that no rating can be less that 0
    double highestRating = -1.0;
    size_t newHighestRating = 0;

    //Search for the position highest rated film
    for (size_t i = 0; i < mvdb.size(); ++i) {
        if (mvdb[i].getRating() > highestRating) {
            newHighestRating = i;
            highestRating = mvdb[i].getRating();
        }
    }

    //Print the result
    std::cout << mvdb[newHighestRating] << std::endl;
}

/**
 * Task 5. Display the Movie with the Longest Title
 * @param mvdb
 */
void task5(movieDatabase::MovieDatabase& mvdb) {
    std::cout << "The Movie with the Longest Title within the MovieDatabase is"
            ": " << std::endl;

    size_t longestTitle = 0;
    size_t newLongestTitle = 0;

    for (size_t i = 0; i < mvdb.size(); ++i) {
        if (mvdb[i].getTitle().size() > longestTitle) {
            newLongestTitle = i;
            longestTitle = mvdb[i].getTitle().size();
        }
    }

    //Print the result
    std::cout << mvdb[newLongestTitle] << std::endl;
}

void task6(rating::RatingDB& rDB) {
    std::cout << "The (chromatically) 101st User Rating for a film is: "
              << std::endl;
    std::cout << "Note... formatted as [dd/mm/yyyyTHH:MM:SSZ]" << std::endl;

    rDB.sort([](rating::Rating& r1, rating::Rating& r2) {
        timestamp::TimeStamp& t1 = r1.getTS();
        timestamp::TimeStamp& t2 = r2.getTS();

        return t1.totalSeconds() < t2.totalSeconds();
    });

    //Print out the result
    std::cout << rDB[100] << std::endl;
}

int main() {
    /* Scrape the data from the movies.txt and ratings.txt files, to
     * populate the MovieDatabase object and Rating object.
     */
    movieDatabase::MovieDatabase mvdb;
    rating::RatingDB rdb;

    mvdb.readFile();
    rdb.readFile();

    for(size_t i = 0; i < mvdb.size(); ++i) {
        movie::Movie& movie = mvdb[i];
        double avScore = 0;

        rating::RatingDB tempRDB = rdb.find([movie]
            (rating::Rating r) mutable {
                return movie.getTitle() == r.getMovie();
        });

        for(size_t j = 0; j < tempRDB.size(); ++j) {
            rating::Rating& r = tempRDB[j];
            avScore += r.getScore();
        }

        avScore /= tempRDB.size();

        movie.setRating(avScore);
        int ratingCount = static_cast<int> (tempRDB.size());
        movie.setRatingCount(ratingCount);
    }

    task1(mvdb);
    task2(mvdb);
    task3(mvdb);
    task4(mvdb);
    task5(mvdb);
    task6(rdb);

    return 0;
}