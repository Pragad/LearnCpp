#include <iostream>
#include <sstream> 
using namespace std;

int main()
{
    stringstream s << 5;
    cout << "Hello" << endl;
    cout << s.str() << endl;
}
