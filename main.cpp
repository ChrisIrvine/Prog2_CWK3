/**
 * File:        main.cpp
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Test Driver for the Movie.cpp and Movie.h files. At this stage
 *              the expected output is...
 *          "Lord of the Rings",2005,"PG-13","Action/Adventure/Fantasy",140,0,0
 *          "Lord of the Rings",2005,"PG-13","Action/Adventure/Fantasy",140,0,0
 *          "Rogue One",2016,"PG-13","Science Fiction/Action/Adventure",134,0,0
 *
 * Version:     v1.0 - 30/03/2017 - created
 */
#include <iostream>
#include "Movie.h"

using namespace movie;

int main() {

    //Initialise test variables
    std:: string testTitle("Rogue One");
    unsigned int testYear = 2016;
    std:: string testCert("PG-13");
    std:: string testGenre("Science Fiction/Action/Adventure");
    unsigned int testRuntime = 135;

    //Test Default constructor
    Movie lotr("Lord of the Rings", 2005, "PG-13", "Action/Adventure/Fantasy",
               140);
    std::cout << lotr << std::endl;

    //Test copy constructor
    Movie copyCat(lotr);
    std::cout << copyCat << std::endl;

    //Test customisable constructor
    Movie rogue(testTitle, testYear, testCert, testGenre, testRuntime);
    std::cout << rogue << std::endl;

    return 0;
}