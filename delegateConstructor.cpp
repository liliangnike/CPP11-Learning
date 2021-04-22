/*
    C++ 11 allows a constructor to call another constructor in the same class.
  
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

int main()
{
    demo d(2);
    std::cout << "val1 = " << d.val1 << std::endl;
    std::cout << "val2 = " << d.val2 << std::endl;
    return 0;
}
