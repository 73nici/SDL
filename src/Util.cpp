#include <Util.h>

void Util::log(std::string str) {
    if (DEBUG_MODE) {
        std::cout << str << std::endl;
    }
}

void Util::log(unsigned int number) {
    if (DEBUG_MODE) {
        std::cout << number << std::endl;
    }
}
