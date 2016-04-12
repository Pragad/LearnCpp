#include <iostream>
using namespace std;

struct X
{
    char symbol;
    uint32_t number;
};

class A;
class B;

class A
{
    public:
        A();
        void fnA();
        void printA();

    private:
        X*  _objAx;
};

A::A():
   _objAx(NULL)
{ }

void
A::fnA()
{
    //_objAx = new X[2];
    B::create(this,
              _objAx);
}

void
A::printA()
{
    cout << "Sym: " << _objAx.symbol << "; Num: " << _objAx.number << endl;
}

class B
{
    public:
        static void create(A*   pObjA
                           X*&  objX);
        void fnB();

    private:
        B(X* &objX);

        A*  _pObjA;
        X*  _objBx;

};

B::B(A*     pObjA,
     X*&    objX):
   _pObjA(pObjA),
   _objBx(objX)
{ }

void
B::create(A*    pObjA,
          X*&   objX)
{
    B obB = new B(pObjA,
                  objX);
}

void
B::fnB()
{
    _objBx.symbol = 'p';
    _objBx.number = 30;
    _pObjA.printA();
}


int main()
{
    cout << "Hello" << endl;
    return 0;
}
