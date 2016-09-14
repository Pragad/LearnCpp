#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    {
		unsigned long int a = 15;
		std::string binaryNum = std::bitset<16>(a).to_string();
		std::cout << binaryNum << "\n";

		unsigned long b = std::bitset<16>(binaryNum).to_ulong();
		std::cout << b << "\n\n";
    }

    {
		int a = -5;
		int b = -7;
        int MASK = 0x0f;
		signed long long c = a;
        c = c & MASK;

        std::bitset<4> a1(a);
        std::bitset<4> b1(b);
		std::cout << "A: " << a1 << "\n";
		std::cout << "B: " << b1 << "\n\n";

        cout << "C1: " << c << endl;
        std::bitset<8> c1(c);
        cout << "C1: " << c1 << "\n\n";

		c <<= sizeof(int);
		//c <<= 1;
        cout << "C2: " << c << endl;
        std::bitset<8> c2(c);
        cout << "C2: " << c2 << "\n\n";

		c ^= (b & MASK);
        cout << "C3: " << c << endl;
        std::bitset<8> c3(c);
        cout << "C3: " << c3 << "\n\n";
    }

    std::cout << std::endl;
    return 0;
}
