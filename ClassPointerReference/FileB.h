#ifndef __FILEB_H__
#define __FILEB_H__

#include "StructX.h"
#include "FileA.h"

class A;

class B
{
    public:
        static void create(A*   pObjA,
                           X*   &objX);
        void fnB();

    private:
        B(A* pObjA, X* &objX);

        A*  _pObjA;
        X*  &_objBx;

};

#endif // __FILEB_H__
