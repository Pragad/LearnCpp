// http://stackoverflow.com/questions/18439520/is-there-a-128-bit-integer-in-c
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

int main()
{
    __int128 a = 5;
    std::cout << sizeof(a) << "\n";

    std::cout << "\n";
    return 0;
}
