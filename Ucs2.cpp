#include <iostream>
#include <cstring>              // memset, strlen, memcmp
using namespace std;

typedef unsigned short ucs2_t;
static const uint8_t CharDollar[] = {'$', 0};

int main()
{
    ucs2_t a[] = {'$', 0};

    if (0 == memcmp(&a[0], CharDollar, sizeof(CharDollar)))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << endl;
    return 0;
}
