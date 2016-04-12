#include <iostream>
using namespace std;

struct X
{
    char symbol;
    uint32_t number;
};

void fn1(X*& objX)
{
    objX->symbol = 'x';
    objX->number = 30;
}

void fn2(X*& objX)
{
    objX = new X();
    objX->symbol = 'x';
    objX->number = 30;
}

int main()
{
    cout << "Hello" << endl;
    X* objX1 = new X();
    X* objX2 = NULL;

    fn1(objX1);
    fn2(objX2);

    cout << objX1->symbol << " " << objX1->number << endl;
    cout << objX2->symbol << " " << objX2->number << endl;
    return 0;
}
