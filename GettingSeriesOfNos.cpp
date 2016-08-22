#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arraySum(vector<int> arr)
{
    int sum = 0;
    for  (auto a : arr)
    {
        sum += a;
    }
    
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    
    cout << arraySum(arr) ;

    return 0;
}

