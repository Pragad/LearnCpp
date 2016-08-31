#include <iostream>
#include <vector>
using namespace std;

// Interface
class Shape
{
    public:
        // IMP: Empty Virtual Destructor for proper cleanup
        virtual ~Shape() { }
        virtual void printShape() = 0;
        virtual int getArea() = 0;
        virtual int getCircumference() = 0;
};

class Square : public Shape
{
    int _length;

    public:
        Square(int len) : _length(len) { }
        ~Square() { }

        virtual void printShape() { cout << "Square:: Len: " << _length; }
        virtual int getArea() { return _length * _length; }
        virtual int getCircumference() { return 4 * _length; }
};

class Rectangle : public Shape
{
    int _length;
    int _breadth;
    public:
        Rectangle(int len, int wid) : _length(len),
                                      _breadth(wid) { }
        ~Rectangle() { }

        virtual void printShape() { cout << "Rectangle:: Len: " << _length << "; Wid: " << _breadth; }
        virtual int getArea() { return _length * _breadth; }
        virtual int getCircumference() { return 2 * (_length + _breadth); }
};

int main()
{
    vector<Shape*> shapes;
    shapes.push_back(new Square(5));
    shapes.push_back(new Square(10));
    shapes.push_back(new Rectangle(5, 10));
    shapes.push_back(new Rectangle(15, 10));

    for (Shape* s : shapes)
    {
        s->printShape();
        cout << "; Area: " << s->getArea();
        cout << "; Circum: " << s->getCircumference() << endl;
    }

    cout << endl;
    return 0;
}
