#include <sstream>
#include <assert.h>
#include <iostream>

#include "../say.hpp"

int main(int argc, char *argv[])
{
    std::string toTest = "Hello goodbye";
    std::stringstream s;
    mitre::sayHello(s, "goodbye");

    assert(s.str() == toTest);
    return 0;
}
