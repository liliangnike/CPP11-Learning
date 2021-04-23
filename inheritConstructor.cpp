/*
    In C++, base class can be initialized in derived class. In traditional C++,
constructor of derived class needs to pass arguments one by one.

    derived(int i, double d) : base(i, d) {}

    After C++ 11, we can use the keyword 'using'

    See the demo code:
*/
#include <iostream>

class demo
{
public:
    int val1;
    int val2;

    demo() { val1 = 1; }

    demo( int value) : demo() // delegate constructor
    {
	val2 = value;
    }
};

class derivedDemo : public demo
{
public:
    using demo::demo;      // inheritance constructor to initialize base class
};

int main()
{
    derivedDemo d(3);
    std::cout << "val1 = " << d.val1 << std::endl;
    std::cout << "val2 = " << d.val2 << std::endl;
    return 0;
}
