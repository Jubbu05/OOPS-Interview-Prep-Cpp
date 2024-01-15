class Base {
	int b_var;
};

class Derived : public Base {
	int d_var;
};

int main()
{
	Derived d_obj;
	Base b_obj = d_obj; // so b_obj has b_var and d_obj has b_var as well as d_var 
                        // so only the value of b_var will be copied so it is called Object Slicing
}

// Base class will have
// b_var

// Derived class will have
// b_var
// d_var