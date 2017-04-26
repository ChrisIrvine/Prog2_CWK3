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
 * Version:     v1.0 - created
 *              v2.0 - recreated for testing purposes
 *              v2.1 - changed how the databases are combined
 *              v3.0 - reworked to run task 1
 *              v3.1 - reworked to run task 2
 *              v3.2 - reworked to run task 3 and 4
 *              v3.3 - reworked to run task 5 and 6
 *              v3.4 - polished and commented
 */

#include <iostream>
#include <vector>
#include <sstream>
#include "TimeStamp.h"
#include "MovieDatabase.h"
#include "Rating.h"

/**
 * Procedure:   chronologicalOrder(movieDatabase::MovieDatabase& mvdb)
 *
 * Description: The first task from the coursework brief. "Sort Movies in
 *              ascending order of release date (1921-2016) and then in alpha
 *              order if have same dates". Does this by called MovieDatabase's
 *              sort() method and then printing out the ordered Movie Database.
 *              There is also a line of formatting at the end.
 *
 * Returns:     N/A
 *
 * Parameters:
 * @param mvdb - The MovieDatabase object to order
 */
void chronologicalOrder(movieDatabase::MovieDatabase& mvdb) {
    std::cout << "The Movies contained within the MovieDatabase in order of "
            "release data:" << std::endl;
    mvdb.sort();
    std::cout << mvdb << std::endl;
    //formatting
    std::cout << "--------------------------------------------\n" << std::endl;
}

/**
 * Procedure: filmNoirSearch(movieDatabase::MovieDatabase& mvdb)
 *
 * Description: The second task from the coursework brief. "Display the third-
 *              longest Film-Noir movie". Does this by searching through the
 *              MovieDatabase, copying any Film-Noir movies into a new Database
 *              then ordering the Film-Noir Database by runtime (longest to
 *              shortest), then printing the third movie in the ordered Film-
 *              Noir Database.
 *
 * Returns:     N/A
 *
 * Parameters:
 * @param mvdb - The MovieDatabase object to search through
 */
void filmNoirSearch(movieDatabase::MovieDatabase& mvdb) {
    std::cout << "The Third Longest 'Film-Noir' Movie is: " << std::endl;
    movieDatabase::MovieDatabase filmNoir =
            mvdb.find([](movie::Movie &movie) {
        return movie.getGenre().filmnoir;
    });
    filmNoir.sort([](movie::Movie& m1, movie::Movie& m2) {
        return m1.getRuntime() > m2.getRuntime();
    });
    std::cout << filmNoir[2] << std::endl;
    //formatting
    std::cout << "\n------------------------------------------\n" << std::endl;
}

/**
 * Procedure:   sciFiSearch(movieDatabase::MovieDatabase& mvdb)
 *
 * Description: The third task from the coursework brief. "Display the tenth
 *              highest rated Sci-Fi movie". Achieves this by copying any
 *              Sci-Fi movies from the Movie Database into a new Sci-Fi
 *              Database, then sorting the Sci-Fi Database by rating. Before,
 *              finally, printing the 10th object from the ordered Sci-Fi
 *              Database.
 *
 * Returns:     N/A
 *
 * Parameters:
 * @param mvdb - The MovieDatabase to search through
 */
void sciFiSearch(movieDatabase::MovieDatabase& mvdb) {
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
    std::cout << "\n------------------------------------------\n" << std::endl;
}

/**
 * Procedure:   highestRated(movieDatabase::MovieDatabase& mvdb)
 *
 * Description: The fourth task from the coursework brief. "Display the highest
 *              rated movie". Because it would be inefficient to simply sort
 *              the Movie Database by rating, this is achieved by iterating
 *              through the Movie Database taking note of each Rating and
 *              comparing it to the next Rating in the Database, overwriting
 *              the initial Rating if the next is higher. Then finding (and
 *              printing) the movie with the highest rating.
 *
 * Returns:     N/A
 *
 * Parameters:
 * @param mvdb - The MovieDatabase to search through
 */
void highestRated(movieDatabase::MovieDatabase& mvdb) {
    std::cout << "The highest rated movie within the MovieDatabase is: "
              << std::endl;
    //Set it so that no rating can be less that 0
    double highestRating = -1.0;
    size_t newHighestRating = 0;
    for (size_t i = 0; i < mvdb.size(); ++i) {
        if (mvdb[i].getRating() > highestRating) {
            newHighestRating = i;
            highestRating = mvdb[i].getRating();
        }
    }
    std::cout << mvdb[newHighestRating] << std::endl;
    //formatting
    std::cout << "\n------------------------------------------\n" << std::endl;
}

/**
 * Procedure:   longestTitle(movieDatabase::MovieDatabase& mvdb)
 *
 * Description: The fifth task from the coursework brief. "Display the film
 *              with the Longest Title". This is achieved in a similar manner
 *              to the highestRated() method.
 *
 * Returns:     N/A
 *
 * Parameters:
 * @param mvdb - The MovieDatabase to search through
 */
void longestTitle(movieDatabase::MovieDatabase& mvdb) {
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
    std::cout << mvdb[newLongestTitle] << std::endl;
    //formatting
    std::cout << "\n------------------------------------------\n" << std::endl;
}

/**
 * Procedure:   userRating101(movieDatabase::MovieDatabase& mvdb)
 *
 * Description: The sixth task from the coursework brief. "Display the
 *              chronologically 101st user rating". The Rating Database is
 *              sorted into ascending order and the 101th object is printed
 *              out.
 *
 * Returns:     N/A
 *
 * Parameters:
 * @param rDB - The Rating Database to search through
 */
void task6(rating::RatingDB& rDB) {
    std::cout << "The (chromatically) 101st User Rating for a film is: "
              << std::endl;
    std::cout << "Note... formatted as [dd/mm/yyyyTHH:MM:SSZ]" << std::endl;
    rDB.sort([](rating::Rating& r1, rating::Rating& r2) {
        timestamp::TimeStamp& t1 = r1.getTS();
        timestamp::TimeStamp& t2 = r2.getTS();
        return t1.totalSeconds() < t2.totalSeconds();
    });
    std::cout << rDB[100] << std::endl;
    //formatting
    std::cout << "\n------------------------------------------\n" << std::endl;
}

/**
 * Procedure:   main()
 *
 * Description: The main method for the project. Firstly it creates and
 *              populates the Movie and Rating Databases from the "movies.txt"
 *              and "ratings.txt" files. Then applies the average rating and
 *              the number of times each film has been rated to the
 *              MovieDatabase from the data held within the Ratings Database.
 *              Finally this method calls the six tasks (as specified in the
 *              coursework brief) before EXIT_SUCCESS.
 *
 * Returns:     EXIT_SUCCESS
 *
 * Parameters:  N/A
 *
 * @return - EXIT_SUCCESS
 *
 */
int main() {
    movieDatabase::MovieDatabase mvdb = movieDatabase::readFile();
    rating::RatingDB rdb = rating::readFile();

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

    chronologicalOrder(mvdb);
    filmNoirSearch(mvdb);
    sciFiSearch(mvdb);
    highestRated(mvdb);
    longestTitle(mvdb);
    task6(rdb);

    return EXIT_SUCCESS;
}