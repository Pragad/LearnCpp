#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Use const reference
// Also make it a friend to have access to private members

struct Student
{
    string name;
    uint32_t age;

    // Method 1: Using operator <
    // Making it a friend require two Arguments
    //bool operator<(const Student& ob)
    friend bool operator<(const Student& ls, const Student& rs)
    {
        return ls.age < rs.age;
    }
};

// Method 2: Custom Compare Function
bool compStudent(const Student& a, const Student& b)
{
    return a.age < b.age;
}

// Method 3: Using operator ()
struct MyStudComp
{
    bool operator() (const Student& a, const Student& b)
    {
        return a.age < b.age;
    }
}obComp;

void printStudents(vector<Student> studs)
{
    for (auto ob : studs)
    {
        cout << "Name: " << ob.name << "; Age: " << ob.age << endl;
    }
    cout << endl;
}

int main()
{
    vector<Student> studs = {{"abc", 20},
                             {"def", 14},
                             {"ghi", 15},
                             {"jkl", 18},
                             {"mno", 16},
                             {"pqr", 12},
                             {"stu", 11},
                             {"efg", 13},
                             {"lmn", 19},
                             {"cde", 17}};

    //sort(studs.begin(), studs.end(), compStudent);
    //sort(studs.begin(), studs.end());
    sort(studs.begin(), studs.end(), obComp);

    // Using Lambda
    /*
    sort(studs.begin(), studs.end(), 
         [](const Student& a, const Student& b) -> bool
         { 
            return a.age < b.age; 
         });
         */

    printStudents(studs);
}
