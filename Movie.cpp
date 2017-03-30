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
 */
#include "Movie.h"

namespace movie {

    //Initialise the customisable constructor method
    Movie::Movie(const std::string &newTitle, const unsigned int newYear,
                 const std::string newCert, const std::string &newGenre,
                 const unsigned int newRuntime) {
        //Assign variable values to the object variables
        this->title = newTitle;
        this->year = newYear;
        this->certificate = newCert;
        this->genre = newGenre;
        this->runtime = newRuntime;
    }

    //Initialise the copy constructor method
    Movie::Movie(const Movie &copyMovie){
        //Copy over the variables
        this->title = copyMovie.getTitle();
        this->year = copyMovie.getYear();
        this->certificate = copyMovie.getCert();
        this->genre = copyMovie.getGenre();
        this->runtime = copyMovie.getRuntime();
    }

    //Destructor, doesn't need to do anything as stack not heap
    Movie::~Movie() {   }

    //Initialise the write() method, acts like a toString() stringbuilder
    //method from java
    std::ostream &Movie::write(std::ostream &stream) const {
        stream << "\"" << this->title<< "\","
               << this->year << ","
               << "\"" << this->certificate << "\","
               << "\"" << this->genre << "\","
               << this->runtime << ",0,0";

        return stream;
    }
}