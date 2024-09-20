#include <iostream>
#include <string>
using namespace std;

class Base
{
    public:
    virtual void fn1(){};
    virtual void fn2(){};
};

class D1: public base
{
    public:
    void fn1() override {};
};

class D2: public base
{
    public:
    void fn2() override {};
};

int main()
{
    D1 d1 {}
    base* dPtr = &d1;
    dPtr->fn1();
}