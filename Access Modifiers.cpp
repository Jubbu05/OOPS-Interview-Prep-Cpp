#include <bits/stdc++.h>
using namespace std;

class Parent
{
public: // -> accessible anywhere in the code
    int x;

protected: // -> accessible in own class, parent class and derived class
    int y;

private: // -> accessible only in own class
    int z;

    void setdata(int n)
    {
        x = n;
    }
    int getdata()
    {
        return x;
    }
};

class child1 : public Parent
{
    // x will remain public
    // y will remain protected
    // z will no be accessible
};

class child2 : private Parent
{
    // x will be private
    // y will be private
    // z will no be accessible
};

class child3 : protected Parent
{
    // x will be protected
    // y will be protected
    // z will no be accessible
};

int main()
{
    return 0;
}