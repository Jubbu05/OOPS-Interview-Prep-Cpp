Abstraction is a concept, which is allowed by encapsulation
You can do encapsulation without using abstraction, but if you wanna use some abstraction in your projects, you'll need encapsulation.

Abstraction hides details in design level while Encapsulation hides details in implementation level 

Abstraction let's you to focus on what the object does instead of how it does where as Encapsulation means hiding the internal details how an object works

#include <bits/stdc++.h>
using namespace std;

class Demo
{
    int x;

public:
    void setdata(int n)
    {
        x = n;
    }
    int getdata()
    {
        return x;
    }
};

int main()
{
    Demo obj;
    obj.setdata(5);
    cout << obj.getdata() << endl;

    return 0;
}