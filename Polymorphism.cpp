Ability of ojects/methods to take different forms
The term Polymorphism means the ability to take many forms.

// Function Overloading -> Compile Time Polymorphism
#include <bits/stdc++.h>
using namespace std;

class Addition
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }
    double sum(double a, double b)
    {
        return a + b;
    }
    int sum(int a, int b, int c)
    {
        return a + b + c;
    }
};
int main()
{
    Addition obj;
    cout << obj.sum(20, 15) << endl;
    cout << obj.sum(2.2, 15.2) << endl;
    cout << obj.sum(81, 100, 10);

    return 0;
}

// Function Overriding -> Run Time Polymorphism
#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    void print()
    {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "Derived Function" << endl;
    }
};

int main()
{
    Derived derived1, derived2;
    //Derived -> o/p
    derived1.print();

    // access print() function of the Base class
    derived2.Base::print();

    return 0;
}

int main()
{
    Derived derived1;

    // pointer of Base type that points to derived1
    Base *ptr = &derived1;

    // call function of Base class using ptr
    ptr->print();

    return 0;
}


//Virtual keyword

#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void print()
    {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "Derived Function" << endl;
    }
};
int main()
{
    Derived derived1;

    // pointer of Base type that points to derived1
    Base *ptr = &derived1;

    // call function of Derived class using ptr
    ptr->print();
    return 0;
}