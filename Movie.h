/**
 * File:        movie.h
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Header file for movie.cpp, containing the methods and variables
 *              used in the movie.cpp file.
 *
 * Version:     v1.0 - 29/03/2017 - created
 *              v2.0 - 30/03/2017 - edited to be stack compatible
 *              v2.1 - 31/03/2017 - implemented input overloading
 *              v2.2 - 31/03/2017 - adapted output overloader for efficiency
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
        Movie() {
        }

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

    std::ostream& operator<<(std::ostream& ostream, Movie &movie);

    std::ostream& operator<<(std::ostream& ostream, Genre& genre);

    std::istream& operator>>(std::istream& istream, Movie &movie);

    std::istream& operator>>(std::istream& istream, Genre& genre);

    /**
     * Procedure:   &operator>>
     *
     * Description: Overload the input operator to take a line of data from a
     *              text file and break it down into the component parts; then
     *              assign the data to the class variables of the movie object.
     *
     * Returns:     A new movie object with data scraped from a file.
     *
     * Parameters:
     * @param istream - input stream
     * @param movie - movie object to create
     * @return - new movie object with data scraped from a file.
     */


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
