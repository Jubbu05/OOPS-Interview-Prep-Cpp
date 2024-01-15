#include <bits/stdc++.h>
using namespace std;

// Single Inheritance A -> B

class Parent
{
public:
    int x;
};

class child1 : public Parent
{
};

// Multilevel Inheritance A -> B -> C
// Parent class is derived from another class
class Parent
{
public:
    int x;
};

class child : public Parent
{
};

class grandchild : public child
{
};

// Multiple Inheritance A , B -> C
class Parent1
{
public:
    int x;
};

class Parent2
{
public:
    int y;
};
class child : public Parent1, public Parent2
{
};

// Hierarchical Inheritance A -> B, C
class Parent
{
public:
    int x;
};

class child1 : public Parent
{
};

class child2 : public Parent
{
};

// Hybrid Inheritance
// Combination of more then 1 Inheritance type

// Diamond problem
// A -> B, C -> D
//  will have features of Parent class 2 times
class Parent
{
public:
    int x;
};

class child1 : public Parent
{
};

class child2 : public Parent
{
};

class grandchild : public child1, public child2
{
};

int main()
{
    return 0;
}