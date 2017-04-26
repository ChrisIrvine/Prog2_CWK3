/**
 * File:        Movie.h
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Header file for Movie.cpp. Details the Genre struct and the
 *              inlined Movie methods.
 *
 * Version:     v1.0 - created.
 *              v2.0 - edited to be stack compatible
 *              v2.1 - implemented input overloading
 *              v2.2 - adapted output overload for efficiency
 *              v3.0 - reworked to be Struct compatible (Genre)
 *              v3.1 - polished and commented
 */

#ifndef PROG2_CWK3_MOVIE_H
#define PROG2_CWK3_MOVIE_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

namespace movie {
    //Struct for the genre variable, defining as 1. In alphabetical order.
    struct Genre final {
        bool action : 1;
        bool adventure : 1;
        bool animation : 1;
        bool biography : 1;
        bool comedy : 1;
        bool crime : 1;
        bool drama : 1;
        bool family : 1;
        bool fantasy : 1;
        bool filmnoir : 1;
        bool history : 1;
        bool horror : 1;
        bool music : 1;
        bool musical : 1;
        bool mystery : 1;
        bool romance : 1;
        bool scifi : 1;
        bool thriller : 1;
        bool war : 1;
        bool western : 1;
    };

    /**
     * Class:       Movie
     *
     * Description: Contains the methods and variables that compose a Movie
     *              Object. Including Accessor and Mutator methods for each
     *              private class variable, a default constructor, copy
     *              constructor, custom constructor and a destructor. Also
     *              includes a Genre Struct and operator overloading.
     */
    class Movie {
    public:
        //Inline Accessor and Mutator methods for the Movie class

        //Declare title getters and setters
        inline void setTitle(std::string& newTitle){this->title = newTitle;}
        inline const std::string getTitle() const {return this->title;};

        //Declare year getters and setters
        inline void setYear(int &newYear) {this->year = newYear;}
        inline const int& getYear() const {return this->year;}

        //Declare certificate getters and setters
        inline void setCert(std::string& newCert){
            this->certificate = newCert;
        }
        inline const std::string getCert() const {return this->certificate;}

        //Declare genre getters and setters
        inline void setGenre(Genre& newGenre) {this->genre = newGenre;}
        inline const Genre getGenre() const {return this->genre;}

        //Declare runtime getters and setters
        inline void setRuntime(int &newRuntime) {this->runtime = newRuntime;}
        inline const int& getRuntime() const {return this->runtime;}

        //Declare rating getters and setters
        inline void setRating(double &newRating) {this->rating = newRating;}
        inline const double& getRating() const {return this->rating;}

        //Declare rating count getters and setters
        inline void setRatingCount(int &newRatingCount) {
            this->ratingCount = newRatingCount;
        }
        inline const int& getRatingCount() const {return this->ratingCount;}

        /**
         * Procedure:   Movie (default)
         *
         * Description: Default constructor.
         *
         * Returns:     A blank movie object
         */
        Movie() { }

        /**
         * Procedure:   Movie (customisable)
         *
         * Description: Customisable constructor for the Movie class that
         *              allows for each class variable of the object to be
         *              declared by the user.
         *
         * Returns:     A new Movie object
         *
         * Parameters:
         * @param newTitle - the title to be assigned to the new Movie object
         * @param newYear - the year to be assigned to the new Movie object
         * @param newCert - the certificate to be assigned to the new Movie
         *                  object.
         * @param newGenre - the genres to be assigned to the new Movie object
         * @param newRuntime - the runtime to be assigned to the new Movie
         *                     object.
         * @param newRating - the rating that the movie has been assigned by
         *                      users.
         * @param newRatingCount - the number of times the movie has been rated
         *                          by users.
         */
        Movie(const std::string &newTitle, const unsigned int newYear,
              const std::string newCert, Genre &newGenre,
              const unsigned int newRuntime, const unsigned int newRating,
              const unsigned int newRatingCount);

        /**
         * Procedure:   Movie (copy)
         *
         * Description: Copy Constructor that takes a single movie object
         *              parameter and copies over the values held within the
         *              movie object.
         *
         * Returns:     A new movie object identical to the copyMovie object.
         *
         * Parameters:
         * @param copyMovie - movie object to be copies
         */
        Movie(const Movie &copyMovie);

        /**
         * Procedure:   Movie (destruct)
         *
         * Description: Destructor method for memory management applications,
         *              however as this class runs off the stack, there is no
         *              need for a destructor.
         *
         * Returns:     N/A
         *
         * Parameters:  N/A
         */
        ~Movie();

        /* Make the overload operators friends of the class to allow access to
         * the class's private fields.
         */
        friend std::ostream& operator<< (std::ostream& ostream, Movie& movie);
        friend std::istream& operator>> (std::istream& istream, Movie& movie);
        friend bool operator<(const Movie& m1, const Movie&m2);
        Movie& operator=(const Movie& movie);

    private:
        std::string title;
        int year;
        std::string certificate;
        Genre genre;
        int runtime;
        double rating;
        int ratingCount;
    };

    /**
     * Procedure:   operator<<(std::ostream& ostream, Movie &movie)
     *
     * Description: Overload the output operator to print the scraped movie
     *              object exactly as it was in the "movies.txt" file. Achieves
     *              this by creating an output stream and fetching each class
     *              variable with formatting either side of the fetching.
     *
     * Returns:     An output stream containing a representation of the
     *              movie object.
     *
     * Parameters:
     * @param ostream - the stream to direct the output to
     * @param movie - movie object containing the data to output
     * @return
     */
    std::ostream& operator<<(std::ostream& ostream, Movie &movie);

    /**
     * Procedure:   operator<<(std::ostream& ostream, Genre& genre)
     *
     * Description: Overload the Genre output operator to return a string
     *              representation of the movie object's Genre. Achieves this
     *              by checking which of the Struct is true, if true the
     *              correct string is directed to the output stream.
     *
     * Returns:     An output stream containing the string representation
     *
     * Parameters:
     * @param ostream - the stream to direct the output to
     * @param genre - Struct to examine
     * @return
     */
    std::ostream& operator<<(std::ostream& ostream, Genre& genre);

    /**
     * Procedure:   operator>>(std::istream& istream, Movie &movie)
     *
     * Description: Overload the input operator to take a line of data from a
     *              text file and break it down into the component parts; then
     *              assign the data to the class variables of the movie object.
     *              Using .get() to remove any unwanted characters.
     *
     * Returns:     An input stream containing new movie object with data
     *              scraped from a file.
     *
     * Parameters:
     * @param istream - input stream
     * @param movie - movie object to create
     * @return - new movie object with data scraped from a file.
     */
    std::istream& operator>>(std::istream& istream, Movie &movie);

    /**
     * Procedure:   operator>>(std::istream& istream, Genre &genre)
     *
     * Description: Overload the input operator for Genre, that takes a string
     *              from the "movies.txt" file and discerns if the string
     *              matches any of the allowed Structs.
     *
     * Returns:     An input stream containing the correct Genres for that
     *              movie object.
     *
     * Parameters:
     * @param istream - input stream
     * @param genre - genre object for the new movie object
     * @return - associated genres to the new movie object
     */
    std::istream& operator>>(std::istream& istream, Genre& genre);

    /**
     * Procedure:   operator<
     *
     * Description: Overload the less than operator to allow a sort function
     *              without specific parameters.
     *
     * Returns:     Boolean value as a result from the comparison.
     *
     * Parameters:
     * @param m1 - the first movie object to compare
     * @param m2 - the second movie object to compare
     * @return - boolean true or false value as a result from the comparison
     */
    inline bool operator< (const Movie& m1, const Movie& m2) {
        return m1.year == m2.year ? m1.title < m2.title : m1.year < m2.year;
    }
}

#endif //PROG2_CWK3_MOVIE_H
