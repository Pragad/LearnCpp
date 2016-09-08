#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    string line;

    cout << "Enter a number: ";
    while (!(cin >> a))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "You should enter a number: ";
    }
    cout << "The number is: " << a << endl;

    while (getline(cin >> std::ws, line))
    {
        if (line != "quit")
        {
            cout << "Game..." << endl;
        }
        else
        {
            cout << "Quit Game" << endl;
            break;
        }
    }
}
