// Using Sealed modifier such as final
// as the base class is declared as final

#include <iostream>
using namespace std;

class Base final{
};

// Compile error because base class is final
class Derived : public Base{
};

int main(){
    return 0;
}


//---------------------------------------------------------------

https://youtu.be/WObyOa2FXwI?feature=shared

// Make class non-inheritable without using final keyword in C++

// SOLUTION:
// a. Make default constructor of Final class as private.
// b. Inherit Final class as virtual in our class which we want to make non-inheritable.
// c. Make our class as friend inside Final class. (so that only our class can call the constructor of Final class, not the derived class)

// Final class cannot be inherited
#include <iostream>
using namespace std;

class Base;

class Final {
private:
	Final() {}
	friend class Base;
};

// Making our Base class as non-inheritable
class Base : virtual Final {
public:
	Base() {}
};

// will give error 
class Derived : public Base {
public:
	Derived() {}
};

int main()
{
	return 0;
}

