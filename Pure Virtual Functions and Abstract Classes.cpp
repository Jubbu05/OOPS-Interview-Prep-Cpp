class Test
{
public:
    // Pure Virtual Function
    virtual void show() = 0;
};

// can't create obj of that class that is having a single virtual function but we can create pointer to that class
// A class having atleast single virtual function is called Abstract Class
// If a class is inheriting a class having a pure virtual function the base class have to override the virtual function
// An Abstract Class can have constructors

// Abstract Class
class Base
{
public:
    void f1()
    {
        cout << "Hi";
    }   
    // Pure Virtual Function
    virtual void f2() = 0;
    virtual void f3() = 0;
};

class Derived : public Base
{
public:
    void f2()
    {
        cout << "Hello";
    }
    void f3() {}
};

// If didn't override all the pure virtual function then this class is also called Abstract Class and can't create obj of it
class Derived2 : public Base
{
public:
    void f2()
    {
        cout << "Hello";
    }
};