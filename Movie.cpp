/**
 * File:        Movie.cpp
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Source code of the movie class declared in Movie.h create movie
 *              objects that are generated from the movies.txt file; containing
 *              details such as the title, year, rating-certificate, genre and
 *              runtime (in minutes). movies.txt is passed in through main.cpp
 *              before it is broken down and separated into individual movie
 *              objects. At this stage there is no file input, I am just
 *              testing the methods before I get to that stage.
 *
 * Version:     v1.0 - 29/03/2017 - created.
 *              v2.0 - 30/03/2017 - edited to be stack compatible
 *              v2.1 - 31/03/2017 - implemented input overloading
 *              v2.2 - 31/03/2017 - adapted output overload for efficiency
 */
#include "Movie.h"

namespace movie {
    //Initialise the customisable constructor method
    Movie::Movie(const std::string &newTitle, const unsigned int newYear,
                 const std::string newCert, const std::string &newGenre,
                 const unsigned int newRuntime, const unsigned int newN1,
                 const unsigned int newN2) {
        //Assign variable values to the object variables
        this->title = newTitle;
        this->year = newYear;
        this->certificate = newCert;
        this->genre = newGenre;
        this->runtime = newRuntime;
        this->nonsense1 = newN1;
        this->nonsense2 = newN2;
    }

    //Initialise the copy constructor method
    Movie::Movie(const Movie &copyMovie){
        //Copy over the variables
        this->title = copyMovie.getTitle();
        this->year = copyMovie.getYear();
        this->certificate = copyMovie.getCert();
        this->genre = copyMovie.getGenre();
        this->runtime = copyMovie.getRuntime();
        this->nonsense1 = copyMovie.getN1();
        this->nonsense2 = copyMovie.getN2();
    }

    //Destructor, doesn't need to do anything as stack not heap
    Movie::~Movie() {   }
}