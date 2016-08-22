#include <iostream>
#include "FileB.h"
#include "FileA.h"
using namespace std;

B::B(A*     pObjA,
     X*&    objX):
   _pObjA(pObjA),
   _objBx(objX)
{ 
    cout << "B::Const()" << endl;
}

void
B::create(A*    pObjA,
          X*&   objX)
{
    cout << "B::create()" << endl;
    B* obB = new B(pObjA,
                   objX);

    obB->fnB();
}

void
B::fnB()
{
    cout << "B::fnB()" << endl;

    // Following line crashes the program
    _objBx = new X();
    _objBx->symbol = 'p';
    _objBx->number = 30;
    cout << "B::fnB()" << endl;
    _pObjA->printA();
}
