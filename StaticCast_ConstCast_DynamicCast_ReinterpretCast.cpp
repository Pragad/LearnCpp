#include <iostream>
#include <typeinfo>             // typeid
using namespace std;
 
// ------------------------------------------------------------------------------------------
// const_cast
//
// Example 1
// const_cast can be used to change non-const class members inside a const member function.
// Consider the following code snippet.
// Inside const member function fun(), ‘this’ is treated by the compiler as ‘const student* const this’, i.e. ‘this’ is a constant pointer to a constant object, thus compiler doesn’t allow to change the data members through ‘this’ pointer.
// const_cast changes the type of ‘this’ pointer to ‘student* const this’.
// ------------------------------------------------------------------------------------------
class student
{
private:
    int roll;
public:
    // constructor
    student(int r):roll(r) {}
 
    // A const function that changes roll with the help of const_cast
    void fun1() const
    {
        ( const_cast <student*> (this) )->roll = 5;
    }
 
    int getRoll()  { return roll; }
};
 
// ------------------------------------------------------------------------------------------
// const_cast
//
// Example 2
// const_cast can be used to pass const data to a function that doesn’t receive const. For example, in the following program fun() receives a normal pointer, but a pointer to a const can be passed with the help of const_cast.
// ------------------------------------------------------------------------------------------
int fun2(int* ptr)
{
    return (*ptr + 10);
}

// ------------------------------------------------------------------------------------------
// const_cast
//
// Example 3
// It is undefined behavior to modify a value which is initially declared as const. Consider the following program. The output of the program is undefined. The variable ‘val’ is a const variable and the call ‘fun(ptr1)’ tries to modify ‘val’ using const_cast.
// ------------------------------------------------------------------------------------------
int fun3(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}

// ------------------------------------------------------------------------------------------
// const_cast
//
// Example 4
// const_cast is considered safer than simple type casting. It’safer in the sense that the casting won’t happen if the type of cast is not same as original object. For example, the following program fails in compilation because ‘int *’ is being typecasted to ‘char *’
// ------------------------------------------------------------------------------------------
void fun4()
{
    int a1 = 40;
    const int* b1 = &a1;
    // char* c1 = const_cast <char *> (b1); // compiler error
    // *c1 = 'A';
}

// ------------------------------------------------------------------------------------------
// const_cast
//
// Example 5
// ------------------------------------------------------------------------------------------
void fun5()
{
    int a1 = 40;
    const volatile int* b1 = &a1;
    cout << "typeid of b1 " << typeid(b1).name() << '\n';
    int* c1 = const_cast <int *> (b1);
    cout << "typeid of c1 " << typeid(c1).name() << '\n';
}

// -----------------------------------------------------------------------------------------
// static_cast
//
// Example 1
// -----------------------------------------------------------------------------------------
class B {};

class D : public B {};

class X {};

void staticCastFun()
{
    D* d = new D;
    B* b = static_cast<B*>(d); // this works
    // X* x = static_cast<X*>(d); // ERROR - Won't compile
}

// -----------------------------------------------------------------------------------------
// Example 2
// -----------------------------------------------------------------------------------------
class BaseStatic
{
    public:
        void DoIt() { cout << "BaseStatic"; }; ;
        ~BaseStatic() {};
};

class FooStatic : public BaseStatic
{
    public:
        void DoIt() { cout << "FooStatic"; }; 
        void FooStaticIt() { cout << "FooStatic It..."; }
};

class BarStatic : public BaseStatic
{
    public :
        void DoIt() { cout << "BarStatic"; }
        void BarStaticIt() { cout << "BarStatic It..."; }
};

BaseStatic* CreateRandomStatic()
{
    if( (rand()%2) == 0 )
        return new FooStatic;
    else
        return new BarStatic;
}

void StaticCastFun2()
{
    for( int n = 0; n < 3; ++n )
    {
        BaseStatic* base = CreateRandomStatic();
        base->DoIt();

        // error: cannot dynamic_cast 'base' (of type 'class BaseStatic*') to type 'class BarStatic*' (source type is not polymorphic)
        //BarStatic* bar = dynamic_cast<BarStatic*>(base);
        //FooStatic* foo = dynamic_cast<FooStatic*>(base);

        BarStatic* bar = static_cast<BarStatic*>(base);
        FooStatic* foo = static_cast<FooStatic*>(base);
        if( bar )
            bar->BarStaticIt();
        if( foo )
            foo->FooStaticIt();
    }

    {
        BaseStatic* base = new BaseStatic();

        // WORKS BUT Undefined behavior.
        FooStatic* foo1 = static_cast<FooStatic*>(base);
        if (foo1 == NULL)
        {
            cout << endl << "Static Cast Failed. foo1 is NULL" << endl;
        }
        else
        {
            cout << endl << "Static Cast Succeeded. foo1 is NOT NULL" << endl;
        }}
}

// -----------------------------------------------------------------------------------------
// dynamic_cast
//
// Example 1
// -----------------------------------------------------------------------------------------
class Base
{
    public:
        //virtual void DoIt() = 0;    // pure virtual

        // Making it just virtual function so that I can create an object for Base.
        // To demonstrate SECOND block in DynamicCastFun()
        virtual void DoIt() { cout << "Base"; }
        virtual ~Base() {};
};

class Foo : public Base
{
    public:
        virtual void DoIt() { cout << "Foo"; }; 
        void FooIt() { cout << "Fooing It..."; }
};

class Bar : public Base
{
    public :
        virtual void DoIt() { cout << "Bar"; }
        void BarIt() { cout << "baring It..."; }
};

Base* CreateRandom()
{
    if( (rand()%2) == 0 )
        return new Foo;
    else
        return new Bar;
}

void DynamicCastFun()
{
    for( int n = 0; n < 3; ++n )
    {
        Base* base = CreateRandom();

        base->DoIt();

        // NOT TYPE SAFE: WE DON'T KNOW THE TYPE OF BASE
        // SO USE DYNAMIC CAST INSTEAD
        //Bar* bar = (Bar*)base;
        //bar->BarIt();

        Bar* bar = dynamic_cast<Bar*>(base);
        Foo* foo = dynamic_cast<Foo*>(base);
        if( bar )
            bar->BarIt();
        if( foo )
            foo->FooIt();

    }

    {
        Base* base = new Base();
        Foo* foo1 = dynamic_cast<Foo*>(base);
        if (foo1 == NULL)
        {
            cout << endl << "Dynamic Cast Failed. foo1 is NULL" << endl;
        }
        else
        {
            cout << endl << "Dynamic Cast Succeeded. foo1 is NOT NULL" << endl;
        }
    }
}

// -----------------------------------------------------------------------------------------
// Interview Questions Bloom
//
// Problem 1
// -----------------------------------------------------------------------------------------
class base_class
{ 
public:
    base_class()
    { 
        // Problem 1. Very imp. 
        // This will call base class's m_function()
        cout << "base class constructor" << endl;
        m_function();
    }

    virtual int m_function()
    { 
        std::cerr << "base_class function" << endl;
    }
};

class derived_1 : public base_class
{ 
public:
    derived_1()
    {
        cout << "derived class constructor" << endl;
    }

    virtual int m_function()
    { 
        std::cerr << "derived_class function" << endl;
    }
};

class derived_2 : public base_class
{ };

//void check_function(base_class& ptr)
void check_function_1(base_class* ptr)
{ 
    derived_1* d1_ob1 = dynamic_cast<derived_1*> (ptr);

    if(NULL != d1_ob1)
    {
        // ptr is of type derived_1
        cout << "Ptr is of type derived_1" << endl;
    }
    else
    {
        // ptr is of type derived_2
        cout << "Ptr is of type derived_2" << endl;
    }
}

// http://stackoverflow.com/questions/1276847/difference-in-behavior-while-using-dynamic-cast-with-reference-and-pointers
void check_function_2(base_class& ptr)
{ 
    // VERY IMP
    // If passed through REFERENCE, then REFERECE CAN'T BE NULL.
    // When dynamic_cast for a pointer type fails it returns a null pointer and the caller can check for that,
    // But when it fails for a reference type it can't return a null reference.
    // So an exception is the only reasonable way to signal a problem.
    try
    {
        derived_1& d1_ob2 = dynamic_cast<derived_1&> (ptr);
    }
    catch (std::bad_cast exp)
    {
        cout << "Bad Cast Exp. Object is of type dervied_2" << endl;
    }
    cout << "No exception. Ptr is of type derived_1" << endl;


    /*
    if(NULL == d1_ob2)
    {
        // ptr is of type derived_1
        cout << "Ptr is of type derived_1" << endl;
    }
    else
    {
        // ptr is of type derived_2
        cout << "Ptr is of type derived_2" << endl;
    }
    */
}

// ------------------------------------------------------------------------------------------
// Main Function
// ------------------------------------------------------------------------------------------
int main(void)
{
    // Const Cast: Example 1
    {
        cout << endl << "Const Cast: Example 1:" << endl;
        student s(3);
        cout << "Old roll number: " << s.getRoll() << endl;
     
        s.fun1();
     
        cout << "New roll number: " << s.getRoll() << endl;
    }
 
    // Const Cast: Example 2
    {
        cout << endl << "Const Cast: Example 2:" << endl;
        const int val = 10;
        const int *ptr = &val;
        int *ptr1 = const_cast <int *>(ptr);
        cout << fun2(ptr1);
    }

    // Const Cast: Example 3a
    {
        cout << endl << "Const Cast: Example 3a:" << endl;
        const int val = 10;
        const int *ptr = &val;
        int *ptr1 = const_cast <int *>(ptr);

        // UNDEFINDED BEHAVIOR
        // fun3(ptr1);

        cout << val << endl;
    }

    // Const Cast: Example 3b
    // It it fine to modify a value which is not initially declared as const.
    // For example, in the above program, if we remove const from declaration of val, the program will produce 20 as output.
    {
        cout << endl << "Const Cast: Example 3b:" << endl;
        int val = 10;
        const int *ptr = &val;
        int *ptr1 = const_cast <int *>(ptr);
        fun3(ptr1);
        cout << val << endl;
    }
 
    // Const Cast: Example 4
    {
        cout << endl << "Const Cast: Example 4:" << endl;
        fun4();
    }
 
    // Const Cast: Example 5
    {
        cout << endl << "Const Cast: Example 5:" << endl;
        fun5();
    }

    // Static Cast: Example 1
    {
        cout << endl << "Static Cast" << endl;
        staticCastFun();
        StaticCastFun2();
    }

    // Dynamic Cast: Example 1
    {
        cout << endl << "Dynamic Cast" << endl;
        DynamicCastFun();
    }

    // Bloomberg Problem 1
    {
        cout << endl << "Bloomberg Problem 1" << endl;
        base_class *ptr = new derived_1();

        check_function_1(ptr);
        //check_function(*ptr);

        delete ptr;
    }

    // Bloomberg Problem 2
    {
        cout << endl << "Bloomberg Problem 2" << endl;
        base_class *ptr = new derived_1();

        check_function_2(*ptr);

        delete ptr;
    }
    return 0;
}
