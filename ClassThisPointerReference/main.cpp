// C:\PRAGADHEESH\DEV\LearnCpp\ClassPointerReference>g++ -std=c++11 main.cpp FileA.cpp FileB.cpp
#include <iostream>
#include "FileA.h"
#include "FileB.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    A *ob = new A();
    ob->fnA();


    return 0;
}
