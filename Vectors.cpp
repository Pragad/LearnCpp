#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // For sort
using namespace std;

// Utility function to print a vector
template <typename T>
void printVector(T dataVecs)
{
    cout << endl;

    // VERY IMP
    //for (auto data : dataVecs)
    //for(size_t i = 0; i < dataVecs.size(); i++)
    for(vector<string>::size_type i = 0; i < dataVecs.size(); i++)
    {
        //cout << data << endl;
        cout << dataVecs[i] << endl;
    }
    cout << endl;
    cout << endl;
}

struct MeetingTime
{
    int startTime;
    int endTime;

    MeetingTime(double sT, double eT) : startTime(sT),
                                        endTime(eT) { }

    /*
    bool operator < (const MeetingTime& meetTime) const
    {
        return (startTime < meetTime.startTime);
    }

    bool operator > (const MeetingTime& meetTime) const
    {
        return (areDoubleGreater(endTime, meetTime.endTime));
    }
    */

    bool operator < (const MeetingTime& meetTime) const
    {
        return (startTime < meetTime.startTime);
    }

    bool operator > (const MeetingTime& meetTime) const
    {
        return (endTime < meetTime.endTime);
    }
};

// TODO:
struct MyMeetStrtEndComp
{
    bool operator()( const MeetingTime& lx, const MeetingTime& rx ) const {
        cout << "Comp: " << lx.startTime << "; " << rx.endTime << endl;
        return lx.startTime >= rx.endTime;
    }
};


void printMeetingVector(vector<MeetingTime> meetings)
{
    cout << "List of Meetings: " << endl;
    for (auto meeting : meetings)
    {
        cout << meeting.startTime << "-" << meeting.endTime << endl;
    }
    cout << endl;
}

int main()
{
    // 1. VECTORS
    // This will add 3 5's to the vector
    std::vector<int> numsSimp (3, 5);

    // Create a Vector from an Array
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    // Tells the Version of _c++. Used to check if C++ 11 is being used.
    cout << "__c++: " <<__cplusplus << endl;

    // First way to iterate through a vector. Using AUTO
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout <<endl;
    
    // Second Way. Using Iterator
    // We can move the iterator to a specific position as well.
    for (std::vector<int>::iterator it = nums.begin() + 2; it != nums.end(); it++)
    {
        cout << *it << " ";
    }  
    cout <<endl;
    
    // Using .at() to access a specific element.
    // Also we have use ARRAY representation
    for (unsigned int i = 0; i < nums.size(); i++)
    {   
        //cout << nums.at(i) << " ";
        cout << nums[i] << " ";
    }
    cout <<endl;


    // 1b. Inserting multiple elements into Vector
    std::vector<int> v1{2,5,8,11,14};
    std::vector<int> v2 = {2,5,8,11,14};

    // 2. UNORDERED MAP
    unordered_map<int, int> myHash;
    myHash[5] = 0;
    cout << myHash[5] << endl;


    // 3. Vector of Vectors
    // 3 Rows and 2 Cols
    vector< vector<int> > matrix(3,vector<int>(2));

    cout << "Vector of Vectors " << endl;

    vector< vector<int> > vecOfVecs;
    vector<int> vec2 = {5, 6};
    vector<int> vec3 = {7};
    vector<int> vec4 = {1, 2, 3};

    /*
    vecOfVecs[0] = vec2;
    vecOfVecs[1] = vec3;
    vecOfVecs[2] = vec4;
    */

    vecOfVecs.push_back(vec2);
    vecOfVecs.push_back(vec3);
    vecOfVecs.push_back(vec4);
    // Here is a simple explanation. vector< vector<int> > vecOfVecs(3); creates a vector with three empty vectors inside it. So you start with { {}, {}, {} }. Then you push back your three new vectors onto the end. So you end up with { {}, {}, {}, {5,6}, {7}, {1,2,3}}.

    cout << vecOfVecs[0][0] << endl;


    // Pass Vectors through recursion
    {
        vector<int> vecInts = {1, 2, 3};
        cout << &vecInts << endl;
        cout << &vecInts[0] << endl;
        cout << &vecInts[1] << endl;
        cout << &vecInts[2] << endl;
        cout << (&vecInts + 1)<< endl;
    }

    // Struct objects sorted by two parameters
    {
        vector<struct MeetingTime> meetingsStrTimeSort = {{9, 10}, {14, 16}, {8, 12},  {12, 16},  {10, 12}};
        vector<struct MeetingTime> meetingsEndTimeSort = meetingsStrTimeSort;
        
        printMeetingVector(meetingsStrTimeSort);
        sort(meetingsStrTimeSort.begin(), meetingsStrTimeSort.end());
        printMeetingVector(meetingsStrTimeSort);

        printMeetingVector(meetingsEndTimeSort);
        sort(meetingsEndTimeSort.begin(), meetingsEndTimeSort.end(), greater<MeetingTime>());
        printMeetingVector(meetingsEndTimeSort);

        MeetingTime tmp = {11, 13};
        auto itr = std::upper_bound(meetingsEndTimeSort.begin(), meetingsEndTimeSort.end(), tmp, MyMeetStrtEndComp());

        cout << "Itr: " << (*itr).startTime << "-" << (*itr).endTime << endl;

    }
    cout << endl;
}
