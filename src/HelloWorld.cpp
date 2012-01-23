#include "say.hpp"
#include "SayString.h"
#include <iostream>
#include <boost/lexical_cast.hpp>

int main(int argc, char *argv[])
{
#ifdef SHOULD_REPEAT
    int numTimes = 1;
    if (argc > 1) {
        try {
            numTimes = boost::lexical_cast<int>(argv[1]);
        } catch (...) {}
    }
#endif

#ifdef SHOULD_REPEAT
    for (int i = 0; i < numTimes; ++i) {
#endif

        mitre::sayHello(std::cout, "World " + STRING_TO_SAY);
        std::cout << std::endl;

#ifdef SHOULD_REPEAT
    }
#endif

    return 0;
}
