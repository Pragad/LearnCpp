#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Enter a number: ";
    while (!(cin >> a))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "You should enter a number: ";
    }

    cout << "The number is: " << a << endl;

}
