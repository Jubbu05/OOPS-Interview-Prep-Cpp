A class is a user defined data type or A class is a blueprint for creating objects
Object is an instance of a class. Is an entity that has state and behavior, it is created at runtime.

#include <bits/stdc++.h>
using namespace std;

class Fruit
{
public:
    string name;
    string colour;
};

int main()
{
    Fruit x;
    x.name = 'Apple';
    x.colour = 'Red';

    Fruit *y = new Fruit();
    y->name = 'Mango';
    y->colour = 'Yellow';

    return 0;
}