Steps to Implement Singleton Class in C++:

Make all the constructors of the class private.
Delete the copy constructor of the class.
Make a private static pointer that can point to the same class object (singleton class).
Make a public static method that returns the pointer to the same class object (singleton class).

#include <bits/stdc++.h>
using namespace std;

class Singleton
{
private:
    string name, loves;
    static Singleton *instancePtr;

    // Default constructor
    Singleton(){}

public:
    // deleting copy constructor
    Singleton(const Singleton &obj) = delete;

    static Singleton *getInstance()
    {
        if (instancePtr == NULL)
        {
            // We can access private members
            // within the class.
            instancePtr = new Singleton();
            return instancePtr;
        }
        else
        {
            // if instancePtr != NULL that means
            // the class already have an instance.
            // So, we are returning that instance
            // and not creating new one.
            return instancePtr;
        }
    }

    void setValues(string name, string loves)
    {
        this->name = name;
        this->loves = loves;
    }
    void print()
    {
        cout << name << " Loves " << loves << "." << endl;
    }
};

// initializing instancePtr with NULL
Singleton *Singleton::instancePtr = NULL;

int main()
{
    Singleton *obj1 = Singleton::getInstance();

    obj1->setValues("Manish","GeeksForGeeks");
    obj1->print();
    cout << "Address of obj1: " << obj1 << endl;

    Singleton *obj2 = Singleton::getInstance();

    obj2->setValues("Vartika","GeeksForGeeks");
    obj2->print();
    cout << "Address of obj2: " << obj2 << endl;

    return 0;
}
