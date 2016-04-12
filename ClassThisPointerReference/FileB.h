#ifndef __FILEB_H__
#define __FILEB_H__

#include "StructX.h"
#include "FileA.h"

class A;

class B
{
    public:
        static void create(A*   pObjA);
        void fnB();

    private:
        B(A* pObjA);

        A*  _pObjA;
        X*  &_objBx;
        //X** _pobjBx;

};

#endif // __FILEB_H__
