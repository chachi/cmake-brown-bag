#include <string>
#include <iostream>

namespace mitre {

void sayHello(std::ostream& os, const std::string& s)
{
    os << "Hello " << s;
}

void sayGoodbye(std::ostream& os, const std::string& s)
{
    os << "Goodbye " << s;
}


}
