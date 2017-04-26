/**
 * File:        Movie.cpp
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Source Code file for Movie.h that hosts the code responsible
 *              for the copy and customisable constructor methods; as well as
 *              the operator overloading for the class and struct operators.
 *
 * Version:     v1.0 - created.
 *              v2.0 - edited to be stack compatible
 *              v2.1 - implemented input overloading
 *              v2.2 - adapted output overload for efficiency
 *              v3.0 - reworked to be Struct compatible (Genre)
 *              v3.1 - polished and commented
 */
#include "Movie.h"

namespace movie {
    //Initialise the customisable constructor method
    Movie::Movie(const std::string &newTitle, const unsigned int newYear,
                 const std::string newCert, Genre &newGenre,
                 const unsigned int newRuntime, const unsigned int newRating,
                 const unsigned int newRatingCount) {
        //Assign variable values to the object variables
        this->title = newTitle;
        this->year = newYear;
        this->certificate = newCert;
        this->genre = newGenre;
        this->runtime = newRuntime;
        this->rating = newRating;
        this->ratingCount = newRatingCount;
    }

    //Initialise the copy constructor method
    Movie::Movie(const Movie &copyMovie){
        //Copy over the variables
        this->title = copyMovie.getTitle();
        this->year = copyMovie.getYear();
        this->certificate = copyMovie.getCert();
        this->genre = copyMovie.getGenre();
        this->runtime = copyMovie.getRuntime();
        this->rating = copyMovie.getRating();
        this->ratingCount = copyMovie.getRatingCount();
    }

    //Destructor, doesn't need to do anything as stack not heap
    Movie::~Movie() {   }

    //Overload the output operator for the movie object
    std::ostream& operator<<(std::ostream &ostream, Movie &movie) {
        ostream << "\"" << movie.title << "\",";
        ostream << movie.year << "," ;
        ostream << "\"" << movie.certificate << "\",";
        ostream << "\"" << movie.genre << "\",";
        ostream << movie.runtime << ",";
        ostream << movie.rating << "," ;
        ostream << movie.ratingCount;

        return ostream;
    }

    //Overload the input operator for the movie object
    std::istream& operator>>(std::istream &istream, Movie &movie) {
        istream.get(); //get rid of the quote mark

        //Grab the string, delimited by the next quote mark, then ignore said
        //quote mark.
        std::getline(istream, movie.title, '"');
        istream.get(); //get rid of the comma

        //Get the next integer
        istream >> movie.year;
        istream.get(); //comma

        istream.get(); //first quote mark
        std::getline(istream, movie.certificate, '"');
        istream.get(); //comma

        istream >> movie.genre;
        istream.get(); //comma

        istream >> movie.runtime;
        istream.get(); //comma

        //Skip past the next 3 characters, allowing the input to continue
        for (size_t i = 0; i < 4; ++i) {
            istream.get();
        }

        //At this stage, the rating and ratingCount are not yet fed external
        //Data.
        movie.rating = 0.0;
        movie.ratingCount = 0;

        return istream;
    }

    //Overload the output operator for the Genre struct
    std::ostream& operator<<(std::ostream& ostream, Genre& genre) {
        std::stringstream output;

        if (genre.action) output << "/" << "Action";
        if (genre.adventure) output << "/" << "Adventure";
        if (genre.animation) output << "/" << "Animation";
        if (genre.biography) output << "/" << "Biography";
        if (genre.comedy) output << "/" << "Comedy";
        if (genre.crime) output << "/" << "Crime";
        if (genre.drama) output << "/" << "Drama";
        if (genre.family) output << "/" << "Family";
        if (genre.fantasy) output << "/" << "Fantasy";
        if (genre.filmnoir) output << "/" << "Film-Noir";
        if (genre.history) output << "/" << "History";
        if (genre.horror) output << "/" << "Horror";
        if (genre.music) output << "/" << "Music";
        if (genre.musical) output << "/" << "Musical";
        if (genre.mystery) output << "/" << "Mystery";
        if (genre.romance) output << "/" << "Romance";
        if (genre.scifi) output << "/" << "Sci-Fi";
        if (genre.thriller) output << "/" << "Thriller";
        if (genre.war) output << "/" << "War";
        if (genre.western) output << "/" << "Western";

        output.get(); //Removes the first "/"

        std::string outString;
        output >> outString;

        ostream << outString;
        return ostream;
    }

    //Overload the input operator for the Genre Struct
    std::istream& operator>>(std::istream& istream, Genre& genre) {
        genre = {};
        istream.get();
        std::string iString;
        std::getline(istream, iString, '"');
        std::stringstream gStream;
        gStream << iString;
        std::string next;

        while(std::getline(gStream, next, '/')) {
            if (next == "Action") genre.action = true;
            else if (next == "Adventure") genre.adventure = true;
            else if (next == "Animation") genre.animation = true;
            else if (next == "Biography") genre.biography = true;
            else if (next == "Comedy") genre.comedy = true;
            else if (next == "Crime") genre.crime = true;
            else if (next == "Drama") genre.drama = true;
            else if (next == "Family") genre.family = true;
            else if (next == "Fantasy") genre.fantasy = true;
            else if (next == "Film-Noir") genre.filmnoir = true;
            else if (next == "History") genre.history = true;
            else if (next == "Horror") genre.horror = true;
            else if (next == "Music") genre.music = true;
            else if (next == "Musical") genre.musical = true;
            else if (next == "Mystery") genre.mystery = true;
            else if (next == "Romance") genre.romance = true;
            else if (next == "Sci-Fi") genre.scifi = true;
            else if (next == "Thriller") genre.thriller = true;
            else if (next == "War") genre.war = true;
            else if (next == "Western") genre.western = true;
        }
        return istream;
    }

    //Overload the assignment operator for efficiency
    Movie& Movie::operator=(const Movie& movie) {
        this->title = movie.title;
        this->year = movie.year;
        this->certificate = movie.certificate;
        this->genre = movie.genre;
        this->runtime = movie.runtime;
        this->rating = movie.rating;
        this->ratingCount = movie.ratingCount;
    }
}