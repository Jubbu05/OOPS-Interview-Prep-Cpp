// Diamond Problem
#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A()
    {
        cout << "Constructor A" << endl;
        a = 10;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "Constructor B" << endl;
        a = 20;
    }
};

class C : public A
{
public:
    C()
    {
        cout << "Constructor C" << endl;
        a = 40;
    }
};

class D : public B, public C
{
public:
    D()
    {
        cout << "Constructor D" << endl;
    }
};

int main()
{
    D obj;
    cout << "a = " << obj.a << endl;
    return 0;
}

// Constructor A
// Constructor B
// Constructor A
// Constructor C
// Constructor D


// Fix
#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A()
    {
        cout << "Constructor A" << endl;
        a = 10;
    }
};

class B : virtual public A
{
public:
    B()
    {
        cout << "Constructor B" << endl;
        a = 20;
    }
};

class C : virtual public A
{
public:
    C()
    {
        cout << "Constructor C" << endl;
        a = 40;
    }
};

class D : public B, public C
{
public:
    D()
    {
        cout << "Constructor D" << endl;
    }
};

int main()
{
    D obj;
    cout << "a = " << obj.a << endl;
    return 0;
}

// O/P
// Constructor A
// Constructor B
// Constructor C
// Constructor D
// a = 40