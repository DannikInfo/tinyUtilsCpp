#ifndef TINYUTILS_UTILS_H
#define TINYUTILS_UTILS_H

#include <string>
#include <vector>
#include <cstring>
#include <filesystem>
#include <fstream>

class utils {
public:
    static void tokenize(const std::string &str, const char *delim, std::vector<std::string> &out);

    static void writeSQLToFile(const std::string &sql);
};


#endif //TINYUTILS_UTILS_H
