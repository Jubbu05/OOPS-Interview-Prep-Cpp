class Demo
{
    int a;

public:
    // Demo aa, bb, cc
    // cc = aa + bb
    Demo operator+(Demo bb)
    {
        Demo cc;
        cc.a = a + bb.a;
        return cc;
    }

    // for ++a
    void operator++()
    {
        a = a + 1;
    }

    // for a++
    // a = a + 1->int
    void operator++(int)
    {
        a = a + 1;
    }

    // aa = bb
    void operator=(Demo bb)
    {
        a = bb.a;
    }

    // aa += bb
    // aa = aa + bb
    void operator+=(Demo bb)
    {
        a = a + bb.a;
    }

    // if(aa == bb)
    bool operator==(Demo bb)
    {
        return a = bb.a;
    }
};

// complex number -> real and imaginary
class Complex
{
    int r;
    int i;

public:
    // cc = aa + bb
    Complex operator+(Complex bb)
    {
        Complex cc;
        cc.r = r + bb.r;
        cc.i = i + bb.i;
        return cc;
    }
};