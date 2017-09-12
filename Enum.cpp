#include<iostream>
#include <vector>
using namespace std;

struct myStruct {
    enum Days
    {
        MON,
        TUE,
        WED
    };
};

static const char* foo()
{
    return "hello";
}

static vector<myStruct::Days> bar()
{
    vector<myStruct::Days> vecDays;
    //vecDays.push_back(myStruct::Days::WED);
    return vecDays;
    //return vector<myStruct::Days>(0);
}

int main()
{
    cout << "Enum example" << endl;
    myStruct::Days myDay = myStruct::Days::WED;
    cout << "Day: " << myDay << endl;
    vector<myStruct::Days> vecDays;
    vecDays.push_back(myStruct::Days::WED);
    cout<<vecDays[0]<<endl;
    int i = vecDays[0];
    cout << i << endl;

    std::string a = foo();
    cout << a << endl;

    vector<myStruct::Days> v2 = bar();
    cout << "v2 size: " << v2.size() << endl;
    for (int i = 0; i < v2.size(); i++) 
    {
        cout << v2[i] << endl;;
    }
}
