class A                      // VTABLE -> | f2 | f3 | f4 |
{                            //Points to    A    A    A
public:
    void f1(){};
    virtual void f2(){};
    virtual void f3(){};
    virtual void f4(){};
};

class B : public A         // VTABLE -> | f2 | f3 | f4 |
{                          //Points to    B    A    A
public:
    void f1(){};
    void f2(){};
    void f4(int x){};
};

// In EB we see pointer belongs to which class that function will be called
// In LB we see object belongs to which class that function will be called

void main()
{
    A *p, obj1;
    B obj2;

    p = &obj1;
    p->f1();    //EB  -> A
    p->f2();    //LB  -> A
    p->f3();    //LB  -> A
    p->f4();    //LB  -> A
    p->f4(10);  //EB  Error
}

void main()
{
    A *p, obj1;
    B obj2;

    p = &obj2;
    p->f1();    //EB  -> A
    p->f2();    //LB  -> B
    p->f3();    //LB  -> A
    p->f4();    //LB  -> A
    p->f4(10);  //EB  -> B
}