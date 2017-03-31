#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <iostream>
#include "MovieDatabase.h"

namespace movieDatabase {

    MovieDatabase::MovieDatabase() {
        std::string title, genre, certificate;
        unsigned int year, runtime, n1, n2;
        std::istringstream stream;

        //Chosen to directly input the file location rather than passing
        //through a class variable as file location will not change.
        std::ifstream reader("../movies.txt");
        std::string line;

        if(reader.is_open()) {
            std::cout << "File opening correctly" << std::endl;
        } else {
            std::cout << "Error opening file" << std::endl;
        }

        while(getline(reader, line)) {
            mvdb.push_back(movie::operator>>(reader));
        }
        std::cout << "Database created" << std::endl;
    }

    MovieDatabase::MovieDatabase(const MovieDatabase &copyDB) {

    }

    std::vector<movie::Movie>
    MovieDatabase::chronologicalOrder(const MovieDatabase &targetDB) {
        return std::vector<movie::Movie>();
    }

    std::ostream &MovieDatabase::write(std::ostream &stream) const {
        for(std::vector<movie::Movie>::const_iterator it = mvdb.begin();
            it != mvdb.end(); ++it) {
            stream << *it << std::endl;
        }
        return stream;
    }
}
