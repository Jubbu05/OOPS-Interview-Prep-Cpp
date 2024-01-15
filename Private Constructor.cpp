#include <iostream>
using namespace std;

class A
{
    A()
    {
        cout << "Constructor";
    }

public:
    void show()
    {
        cout << "Hi";
    }
    static void get()
    {
        A obj;
    }
};

int main()
{
    A::get();
    return 0;
}