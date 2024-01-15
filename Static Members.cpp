Satic member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class.

We are allowed to invoke a static member function using the object and the ‘.’ operator but it is recommended to invoke the static members using the class name and the scope resolution operator.

#include <iostream>

using namespace std;

class Box
{
public:
private:
    double length;  
    double breadth; 
    double height; 

    static int objectCount;

public:
    // Constructor definition
    Box(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "Constructor called." << endl;
        length = l;
        breadth = b;
        height = h;

        // Increase every time object is created
        objectCount++;
    }
    double Volume()
    {
        return length * breadth * height;
    }
    static int getCount()
    {
        return objectCount;
    }
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main()
{
    // Print total number of objects before creating object.
    cout << "Inital Stage Count: " << Box::getCount() << endl;

    Box Box1(3.3, 1.2, 1.5); // Declare box1
    Box Box2(8.5, 6.0, 2.0); // Declare box2

    // Print total number of objects after creating object.
    cout << "Final Stage Count: " << Box::getCount() << endl;

    return 0;
}

//-----------------------------------------------------------------

#include<iostream>
using namespace std;
  
class GfG
{
   public:
     static int i;
      
     GfG(){};
};

int main()
{
  GfG obj1;
  GfG obj2;
  obj1.i = 2;
  obj2.i = 3;
  
  cout << obj1.i<<" "<<obj2.i;   
}
// will give compilation error

#include<iostream>
using namespace std;
  
class GfG
{
   public:
     static int i;
      
     GfG(){};
};
// Initialize static member of class 
int GfG::i = 1;

int main()
{
  GfG obj1;
  GfG obj2;
  obj1.i = 2;
  obj2.i = 3;
  
  cout << obj1.i<<" "<<obj2.i;   
}
// o/p 
// 3 3

