#include "say.hpp"
#include <iostream>
#include <boost/lexical_cast.hpp>

int main(int argc, char *argv[])
{
    int numTimes = 1;
    if (argc > 1) {
        try {
            numTimes = boost::lexical_cast<int>(argv[1]);
        } catch (...) {}
    }

    for (int i = 0; i < numTimes; ++i) {
        mitre::sayHello(std::cout, "World!");
        std::cout << std::endl;
    }
    return 0;
}
