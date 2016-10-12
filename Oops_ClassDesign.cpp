#include <iostream>
using namespace std;

// ------------------------------------------------------------------------------------------
// Engine Class
// ------------------------------------------------------------------------------------------
class Engine
{
public:
    Engine (int cc);
    void start();
};

// ------------------------------------------------------------------------------------------
// Wheel Class
// ------------------------------------------------------------------------------------------
class Wheel
{
public:
    Wheel (int numWheels);
};

// ------------------------------------------------------------------------------------------
// Vehicle Class
// http://stackoverflow.com/questions/6052131/can-virtual-classes-in-c-have-member-variables
// ------------------------------------------------------------------------------------------
class Vehicle
{
protected:
    //Engine _engines;
    //Wheel  _wheels;

public:
    virtual void move() = 0;
    virtual void start() = 0;
};

// ------------------------------------------------------------------------------------------
// Car Class
// ------------------------------------------------------------------------------------------
class Car : public Vehicle
{
public:
    Car(int engines = 4) : _engines(engines),
                           _wheels(4) { }

    void start()
    {
        _engines.start();
    }

    void move()
    {
        cout << "Car Moves" << endl;
    }

private:
    Engine  _engines;
    Wheel   _wheels;
};

// ------------------------------------------------------------------------------------------
// Truck Class
// ------------------------------------------------------------------------------------------
class Truck : public Vehicle
{
public:
    Truck(int engines = 8) : _engines(engines),
                             _wheels(8) { }

    void start()
    {
        _engines.start();
    }

    void move()
    {
        cout << "Truck Moves" << endl;
    }

private:
    Engine _engines;
    Wheel   _wheels;
};

// ------------------------------------------------------------------------------------------
// Bicycle Class
// ------------------------------------------------------------------------------------------
class Bicycle : public Vehicle
{
public:
    Bicycle() : _wheels(2) { }

    void start()
    {
        cout << "Pedal" << endl;
    }

    void move()
    {
        cout << "Truck Moves" << endl;
    }

private:
    Wheel   _wheels;
};

// ------------------------------------------------------------------------------------------
// Main Function
// ------------------------------------------------------------------------------------------
int main()
{
    cout << endl;
    return 0;
}
