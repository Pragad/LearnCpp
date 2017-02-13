#include <iostream>
using namespace std;

#define DEBUG 1

int main()
{
    int a = 4;

#ifdef DEBUG
    cout << "Even Odd" << endl;
#endif

    //if (!(a & 1))
    if (a % 2 == 0)
    {
        cout << "Num is even" << endl;
    }
    else
    {
        cout << "Num is odd" << endl;
    }
    cout << endl;
    return 0;
}
