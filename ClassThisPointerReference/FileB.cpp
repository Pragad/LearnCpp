#include <iostream>
#include "FileB.h"
#include "FileA.h"
using namespace std;

B::B(A*     pObjA):

   _pObjA(pObjA),
   _objBx(pObjA->getObjAx())
   //_objBx(pObjA->_objAx)
   //_pobjBx(pObjA->getObjAx())
{ 
    cout << "B::Const()" << endl;
}

void
B::create(A*    pObjA)
{
    cout << "B::create()" << endl;
    B* obB = new B(pObjA);

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

    /*
    (*_pobjBx) = new X();
    (*_pobjBx)->symbol = 'p';
    (*_pobjBx)->number = 30;
    */
    cout << "B::fnB()" << endl;
    _pObjA->printA();
}
