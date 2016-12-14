#include <iostream>
using namespace std;

// QUESTION 1: READ 1:
// WHEN TO RETURN BY VALUE AND RETURN BY REFERENCE
//
// http://stackoverflow.com/questions/21485366/why-we-use-reference-return-in-assigment-operator-overloading-and-not-at-plus-mi
// http://stackoverflow.com/questions/2337213/return-value-of-operator-overloading-in-c

//      - Some operators return by value, some by reference.
//      - An operator whose result is a new value (such as +, -, etc) must return the new value by value,
//      - An operator whose result is an existing value, but modified (such as <<, >>, +=, -=, etc), should return a reference to the modified value.

class Rectangle
{
    public:
        int length;
        int width;

        Rectangle operator+(const Rectangle& obj);
        Rectangle& operator=(const Rectangle& obj);
};

// READ 2:
// Returns Modification of existing value.
// So return by reference.
// That way we can do compound assignment
//
// You will get following errors if not returned by reference:
//      error: no match for 'operator=' (operand types are 'Rectangle' and 'void')
//      no known conversion for argument 1 from 'void' to 'const Rectangle&'
Rectangle& Rectangle::operator=(const Rectangle& obj)
{
    this->length = obj.length;
    this->width = obj.width;

    return *this;
}

// READ 3:
// Returns New Value.
// So return by value
Rectangle Rectangle::operator+(const Rectangle& obj)
{
    Rectangle tmp = *this;
    tmp.length = tmp.length + obj.length;
    tmp.width = tmp.width + obj.width;

    return tmp;
}

class Time
{
    private:
        int hours;             // 0 to 23
        int minutes;           // 0 to 59
    public:
        Time()
        {
            hours = 0;
            minutes = 0;
        }

        Time(int h, int m)
        {
            hours = h;
            minutes = m;
        }
        // method to display time
        void displayTime()
        {
            cout << "H: " << hours << " M:" << minutes <<endl;
        }

        // QUESTION 2: READ 4:
        // PREFIX INCREMENT vs POSTFIX INCREMENT
        // http://stackoverflow.com/questions/3846296/how-to-overload-the-operator-in-two-different-ways-for-postfix-a-and-prefix
        //
        // The only sane implementation of the postfix increment function is to make a copy of the object
        // Call the prefix increment function to perform the increment
        // And return the copy
        // but copy operations can be expensive)

        // overloaded prefix ++ operator
        // Modification of existing value.
        // So return by reference
        Time& operator++ ()  
        {
            ++this->minutes;          // increment this object
            if(this->minutes >= 60)  
            {
                ++this->hours;
                this->minutes -= 60;
            }
            return *this;

            /*
               ++minutes;          // increment this object
               if(minutes >= 60)  
               {
               ++hours;
               minutes -= 60;
               }
               return Time(hours, minutes);
             */
        }

        // QUESTION 3: READ 5:
        // WHY POSTFIX TAKES A DUMMY INT AS PARAMETER?
        //    There's not way to distinguish postfix and prefix by Return value
        //    For function overloading the parameter type should be different
        //
        // overloaded postfix ++ operator
        // Return new value
        // So return by reference
        Time operator++( int unused)         
        {
            // READ 6:
            // Make a copy of the value
            // T will have reference to 'this'
            Time T(*this);
            cout << "Post 1: H: " << T.hours << "; M: " << T.minutes << endl;

            // READ 7:
            // Use PREFIX to do the increment
            // This MUST be done on 'this' and NOT on 'T'
            ++(*this);
            cout << "Post 2a: H: " << T.hours << "; M: " << T.minutes << endl;
            cout << "Post 2b: H: " << (*this).hours << "; M: " << (*this).minutes << endl;

            // Return the copy (the old) value
            return T; 

            /*
            // save the orignal value
            Time T(hours, minutes);
            // increment this object
            ++minutes;                    
            if(minutes >= 60)
            {
            ++hours;
            minutes -= 60;
            }
            // return old original value
            return T; 
             */
        }
};

int main()
{
    {
        Rectangle ob1;
        ob1.length = 5;
        ob1.width = 3;

        Rectangle ob2;
        ob2.length = 15;
        ob2.width = 8;

        Rectangle ob3;
        Rectangle ob4;
        // It is like ob1.add(ob2)
        ob4 = ob3 = ob1 + ob2;

        cout << "L1: " << ob3.length << "; W: " << ob3.width << endl;
        cout << "L2: " << ob4.length << "; W: " << ob4.width << endl;
    }

    {
        Time T1(11, 59), T2(10,40);

        ++T1;                    // increment T1
        T1.displayTime();        // display T1
        ++T1;                    // increment T1 again
        T1.displayTime();        // display T1

        T2++;                    // increment T2
        T2.displayTime();        // display T2
        T2++;                    // increment T2 again
        T2.displayTime();        // display T2
    }

    return 0;
}
