#include <iostream>
using namespace std;

class Rectangle
{
    public:
        int length;
        int width;

        Rectangle operator+(const Rectangle& obj);
        void operator=(const Rectangle& obj);
};

void Rectangle::operator=(const Rectangle& obj)
{
    this->length = obj.length;
    this->width = obj.width;
}

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

      // overloaded prefix ++ operator
      Time operator++ ()  
      {
         ++minutes;          // increment this object
         if(minutes >= 60)  
         {
            ++hours;
            minutes -= 60;
         }
         return Time(hours, minutes);
      }

      // overloaded postfix ++ operator
      Time operator++( int )         
      {
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
        // It is like ob1.add(ob2)
        ob3 = ob1 + ob2;

        cout << "L: " << ob3.length << "; W: " << ob3.width << endl;
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
