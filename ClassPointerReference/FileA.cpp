#include <iostream>
#include "FileA.h"
#include "FileB.h"
using namespace std;

A::A():
   _objAx(0)
{
    cout << "A::Const()" << endl;
}

void
A::fnA()
{
    //_objAx = new X();
    cout << "A::fnA()" << endl;
    B::create(this,
              _objAx);
}

void
A::printA()
{
    cout << "Sym: " << _objAx->symbol << "; Num: " << _objAx->number << endl;
}
