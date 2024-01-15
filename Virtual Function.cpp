A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class. It tells the compiler to perform late binding where the compiler matches the object with the right called function and executes it during the runtime. This technique falls under Runtime Polymorphism.

 When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the method.

#include <iostream>
using namespace std;

class base {
public:
	virtual void print() { cout << "print base class\n"; }

	void show() { cout << "show base class\n"; }
};

class derived : public base {
public:
	void print() { cout << "print derived class\n"; }

	void show() { cout << "show derived class\n"; }
};

int main()
{
	base* bptr;
	derived d;
	bptr = &d;

	// Virtual function, binded at runtime
	bptr->print();

	// Non-virtual function, binded at compile time
	bptr->show();

	return 0;
}
// o/p
// print derived class
// show base class