#include <bits/stdc++.h>
using namespace std;

class Rectangle{
    public:
    int l;
    int b;

    //Default Constructor -> no args pass
    Rectangle(){
        l = 0;
        b = 0;
    }

    //Parameterized Constructor -> args pass
    Rectangle(int x, int y){
        l = x;
        b = y;
    }
    //Copy Constructor -> initialise obj by another existing obj
    Rectangle(Rectangle& r){
        l = r.l;
        b = r.b;
    }

    //Destructor
    ~Rectangle(){
    }
};

int main(){
    Rectangle r1; // will call Default Constructor

    Rectangle r2(5,6);
    
    Rectangle r3 = r2;
    //or
    Rectangle r3(r2);
    
    return 0;
}