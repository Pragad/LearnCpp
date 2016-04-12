#ifndef __FILEA_H__
#define __FILEA_H__

#include "StructX.h"
#include "FileB.h"

class A
{
    public:
        A();
        void fnA();
        void printA();

        //X** getObjAx() { return &_objAx ; }
        X*& getObjAx() { return _objAx ; }

    private:
        X*  _objAx;
};

#endif // __FILEA_H__
