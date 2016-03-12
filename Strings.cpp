#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Q1. Assigning value to a struct inside a union
// http://stackoverflow.com/questions/17556780/how-can-i-assign-value-to-the-struct-inside-union-here

int main()
{
    // Q2. We can't enter a string with just 5 characters.
    // http://stackoverflow.com/questions/579734/assigning-strings-to-arrays-of-characters
    //
    // Q3: IMP: Array Decaying
    // http://stackoverflow.com/questions/10088661/assigning-a-string-of-characters-to-a-char-array?lq=1
    uint8_t fileName[9];
    //strncpy(fileName, "hello", 9);
    //fileName = "hello000";
    cout << fileName << endl;


    int *a;
    int *b; 
    // *a = 5;
    /*
       cout<<a<<endl;
       cout<<*a<<endl;
       cout<<b<<endl;
       cout<<*b<<endl;

       char test[9];
       std::string str("HelloWorld");
       str.copy(test, 5);
       cout << test << endl;
     */

    // Modifying a string
    {
        string tempStr = "xyz";
        tempStr[0] = 'a';
        tempStr[1] = 'b';
        tempStr[2] = 'c';
        cout << "TempStr: " << tempStr << endl;
    }

    // Adding characters to a string
    {
        string str;
        str += 'a';
        str += 'b';
        str += 'c';
        str += 'd';
        cout << str << endl;
    }

    // String Compare
    {
        string str1 = "223425623";
        string str2 = "234256623";

        cout << "String Compare: " << str1.compare(str2) << endl;
        cout << "String Compare: " << str2.compare(str1) << endl;
    }

    {
        int a = 5;
        int Arr[a];
        cout << sizeof(Arr) << endl;
    }

    // Getting multi-words input from CIN
    {
        string wordsList;
        cout << "Enter a multi word string: " << endl;

        // Flush the new line characters if any
        //cin.ignore();
        //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        getline(cin, wordsList);

        cout << wordsList << endl;
    }

    // Getting multi-lines input from CIN
    {
        std::vector<std::string> lines;
        std::string line;
        cout << "Enter a multi line string: " << endl;

        // If you want to ignore the leading whitespaces then
        //while (getline(cin >> ws, line)
        while (getline(cin, line))
        {
            if (!line.empty())
            {
                lines.push_back(line);
            }
            else
            {
                break;
            }
        }

        for (string str : lines)
        {
            cout << str << endl;
        }
    }

    cout <<  endl;
    return 0;
}
