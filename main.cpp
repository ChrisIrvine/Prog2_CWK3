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

#include "MovieDatabase.h"

using namespace movieDatabase;

int main() {

    MovieDatabase data;

    std::cout << data << std::endl;

    return 0;
}