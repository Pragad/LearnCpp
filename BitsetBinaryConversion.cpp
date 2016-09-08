#include <iostream>
#include <bitset>

int main()
{
    unsigned long int a = 15;
    std::string binaryNum = std::bitset<16>(a).to_string();
    std::cout << binaryNum << "\n";

    unsigned long b = std::bitset<16>(binaryNum).to_ulong();
    std::cout << b << "\n";
}
