Composition: Composition is a design principle where a class contains objects of other classes, helping to create more complex objects by combining simpler ones.

class Engine {
    // Engine class implementation
};

class Car {
    Engine engine;  // Car "has-a" Engine
    // Other members and methods
};


Inheritance: Inheritance is a mechanism that allows a class (subclass/derived class) to inherit properties and behaviors from another class (superclass/base class).

class Animal {
    // Animal class implementation
};

class Dog : public Animal {
    // Dog inherits from Animal
    // Additional members and methods specific to Dog
};
