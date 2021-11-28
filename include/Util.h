#ifndef SDL_CPP_UTIL_H
#define SDL_CPP_UTIL_H

#include <iostream>
#include <Constant.h>

class Util {
public:
    /**
     * logs to stdout
     * @param str the string to log
     */
    static void log(std::string str) {
        if (DEBUG_MODE) std::cout << str << std::endl;
    }

    /**
     * logs to stdout
     * @param num the number to log
     */
    static void log(unsigned int num) {
        if (DEBUG_MODE) std::cout << num << std::endl;
    }
};


#endif //SDL_CPP_UTIL_H
