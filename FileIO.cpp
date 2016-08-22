#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

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

int main()
{
    vector <string> fileLines;
    string line;
    ifstream ifile;
    ofstream ofile;

    // Read data from a file
    {
        ifile.open("samp.txt");
        if (ifile.is_open())
        {
            while (!ifile.eof())
            {
                getline(ifile, line);
                fileLines.push_back(line);
            }

            // As we have reached the EOF, time to close the file
            ifile.close();
        }
        else
        {
            cout << "Unable to open the file" << endl;
        }

        printVector(fileLines);
    }

    // Write data to a new file
    {
        ofile.open("sampNew.txt");
        if (ofile.is_open())
        {
            // Write all vector lines to the file
            for (auto line : fileLines)
            {
                ofile << line << "\n";
            }

            // As we are done writing, close the file
            ofile.close();
        }
        else
        {
            cout << "Unable to open the file" << endl;
        }
    }

    // Print only comments
    {
        bool comment = false;
        for (auto line : fileLines)
        {
            size_t slashPos = line.find("//");
            size_t asterPos = line.find("/*");
            size_t closePos = line.find("*/");

            // VERY IMP: This should be done at the very beginning. Else this will never become false
            if (closePos != string::npos)
            {
                comment = false;
            }

            // If this line is not a part of multi-line comment AND
            // does not have any comments in it, then ignore the line)
            if (!comment &&
                slashPos == string::npos &&
                asterPos == string::npos &&
                closePos == string::npos)
            {
                continue;
            }
            
            // If the line is a part of multiline comment, print the line
            if (comment)
            {
                cout << line << endl;
            }
            // If line has "//" find its postion and print till end
            else if (slashPos != string::npos)
            {
                cout << line.substr(slashPos) << endl;
            }
            // If line has "/*" find its postion and print till end
            else if (asterPos != string::npos)
            {
                comment = true;
                cout << line.substr(asterPos) << endl;
            }
            // If line has "*/" find its postion and print till "*/"
            else if (closePos != string::npos)
            {
                cout << line.substr(0, closePos) << endl;
            }
        }
    }

    cout << endl;
    return 0;
}
