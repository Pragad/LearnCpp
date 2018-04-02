// A2DD.cpp
#include "A2DD.h"
#include <iostream>
using namespace std;

/*
A2DD::A2DD(int x,int y)
{
  gx = x;
  gy = y;
}
*/

int A2DD::getSum()
{
  return gx + gy;
}

void A2DD::printNum()
{
    cout << "x: " << gx << "; gy: " << gy << endl;
}

