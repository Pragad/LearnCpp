#include <iostream>
using namespace std;

int main()
{
    int a = 4;

    if (!(a & 1))
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
