#include <sstream>
#include <assert.h>
#include <iostream>

#include "../say.hpp"

int main(int argc, char *argv[])
{
    std::string toTest = "Goodbye cruel world";
    std::stringstream s;
    mitre::sayGoodbye(s, "cruel world");

    assert(s.str() == toTest);
    return 0;
}
