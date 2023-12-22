#ifndef CPL_MAPNUMBERREADER_H
#define CPL_MAPNUMBERREADER_H

#include <fstream>

class MapNumberReader {
public:
    auto getSumOfFirstAndLastDigitPerLine(std::ifstream & file) -> int;
};


#endif //CPL_MAPNUMBERREADER_H
