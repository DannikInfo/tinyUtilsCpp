
#include "utils.h"

time_t curr_time;
tm * curr_tm;
char dt[50];

void utils::tokenize(std::string const &str, const char* delim, std::vector<std::string> &out){
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr){
        out.emplace_back(token);
        token = strtok(nullptr, delim);
    }
}

void utils::writeSQLToFile(const std::string& sql){
    time(&curr_time);
    curr_tm = localtime(&curr_time);
    bzero(dt, 50);
    strftime(dt, 50, "%d-%m-%Y", curr_tm);
    std::string date = std::string(dt);
    if(!std::filesystem::exists("cache/"+date))
        std::filesystem::create_directories("cache/"+date);

    strftime(dt, 50, "%d-%m-%Y %H_%M_%S", curr_tm);

    std::ofstream f("cache/"+date+"/"+std::string(dt)+".sql");
    f << sql;
    f.close();
}