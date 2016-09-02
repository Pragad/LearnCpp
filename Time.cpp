#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

int main()
{
    {
        // http://www.cplusplus.com/reference/ctime/time/
        time_t curTime;
        curTime = time(0);
        time(&curTime);
        cout << "Epoch Time In Seconds 1: " << curTime << endl;

    // Method 1 to convert Time to String
        cout << ctime(&curTime) << endl;
        curTime += 1800;
        unsigned long int l1Time = (unsigned long int)curTime;
        unsigned long int l2Time = static_cast<unsigned long int>(curTime);
        cout << l1Time << endl;
        cout << l2Time << endl;

        // OR
    // Method 2 to convert Time to String
        // http://www.cplusplus.com/reference/ctime/tm/
        struct tm* locTime = localtime(&curTime);
        cout << "Year: " << locTime->tm_year + 1900 << ", ";
        cout << "Mon: " << locTime->tm_mon + 1 << ", ";
        cout << "Day : " << locTime->tm_mday << ", ";
        cout << "Hour: " << locTime->tm_hour << ", ";
        cout << "Min : " << locTime->tm_min << ", ";
        cout << "Sec : " << locTime->tm_sec << endl;

        // OR
    // Method 3 to convert Time to String
        // localtime Convert time_t to tm as local time (function )
        cout << asctime(locTime) << endl;


 
        for (int i = 0; i < 100000000; i++)
        {
            int j = 5;
        }
    }

    {
        // get the current time
        const auto now     = std::chrono::system_clock::now();

        // transform the time into a duration since the epoch
        const auto epoch   = now.time_since_epoch();

        // cast the duration into seconds
        const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);

        cout << "Epoch Time In Seconds 2: " << seconds.count() << endl;
    }
}
