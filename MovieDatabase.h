//
// Created by Christopher Irvine on 28/03/2017.
//

#ifndef PROG2_CWK3_MOVIEDATABASE_H
#define PROG2_CWK3_MOVIEDATABASE_H

#include <string>
#include <vector>
#include "Movie.h"

namespace movieDatabase {
    class MovieDatabase {
    public:
        /**
         * Default constructor
         */
        MovieDatabase();

        /**
         * Copy constructor
         */
        MovieDatabase(const MovieDatabase &copyDB);

        /**
         * method to put database into chronological order
         * @param targetDB
         * @return
         */
        std::vector<movie::Movie> chronologicalOrder(const MovieDatabase &targetDB);

        std::ostream &write(std::ostream &stream) const;

    private:
        std:: vector<movie::Movie> mvdb;
    };

    inline std::ostream& operator<< (std::ostream &stream
            , const MovieDatabase& mvdb) {
        return mvdb.write(stream);
    }
}

#endif //PROG2_CWK3_MOVIEDATABASE_H
