/**
 * File:        movie.h
 *
 * Author:      ruw12gbu, 100036248
 *
 * Description: Header file for movie.cpp, containing the methods and variables
 *              used in the movie.cpp file.
 *
 * Version:     v1.0 - 29/03/2017 - created
 *              v1.0 - 30/03/2017 - edited to be stack compatible
 */

#ifndef PROG2_CWK3_MOVIE_H
#define PROG2_CWK3_MOVIE_H

#include <string>
#include <sstream>
#include <iostream>

namespace movie
{
    class Movie {
    public:
        /**
         * Inline Accessor and Mutator methods for the Movie class
         */
        //Declare title getters and setters
        inline void setTitle(std::string& newTitle){this->title = newTitle;}
        inline const std:: string getTitle() const {return this->title;};

        //Declare year getters and setters
        inline void setYear( unsigned int &newYear) {this->year = newYear;}
        inline const unsigned int& getYear() const {return this->year;}

        //Declare certificate getters and setters
        inline void setCert(std::string& newCert){
            this->certificate = newCert;
        }
        inline const std:: string getCert() const {return this->certificate;}

        //Declare genre getters and setters
        inline void setGenre(std::string& newGenre) {this->genre = newGenre;}
        inline const std:: string getGenre() const {return this->genre;}

        //Declare runtime getters and setters
        inline void setRuntime( unsigned int &newRuntime) {
            this->runtime = newRuntime;
        }
        inline const unsigned int& getRuntime() const {return this->runtime;}

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
         *                  object
         * @param newGenre - the genres to be assigned to the new Movie object
         * @param newRuntime - the runtime to be assigned to the new Movie
         *                     object
         */
        Movie(const std::string &newTitle, const unsigned int newYear,
              const std::string newCert, const std::string &newGenre,
              const unsigned int newRuntime);

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

        /**
         * Procedure:   write
         *
         * Description: Writer method that acts in a similar manner to the
         *              String Builder / toString() method that exists in
         *              Java.
         *
         * Returns:     An overloaded output stream containing an informational
         *              printout of the object.
         *
         * Parameters:
         * @param stream - stream to overload
         * @return
         */
        std::ostream &write(std::ostream &stream) const;

    private:
        std:: string title;
        unsigned int year;
        std:: string certificate;
        std:: string genre;
        unsigned int runtime;
    };

    /**
     * Procedure:   operator<<
     *
     * Description: Overload method to allow for quick informational prints of
     *              the object to be submitted through the output.
     *
     * Returns:     Overloaded output operator
     *
     * Parameters:
     * @param stream - output stream
     * @param movie - movie object to retrieve the information from
     * @return
     */
    inline std::ostream& operator<< (std::ostream &stream
            , const Movie& movie) {
        return movie.write(stream);
    }

    std::istream& operator>> (std::istream& stream, const Movie& movie);
}

#endif //PROG2_CWK3_MOVIE_H
