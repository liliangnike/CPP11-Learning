/*
    In example of lambda.cpp, we can see that there 2 ways to call function f

    1. Call f by function pointer
   
    2. Call f by lambda

    In C++, different callable objects may have various called ways.

    In lambda.cpp case, though there 2 ways to call f, but the can be unified to:

    -> int (int)



    For std::bind, it can accept a callable object, after binding some parameters, it will become a new callable object.

    Sometimes, we may have requirement to call an object, but we can't get all parameter at one time.

    Then we can bind the parameters and then complete the call after all the parameters are complete.

*/

#include <iostream>
#include <functional>

int demo (int a)
{
    return a;
};

int demoBind (int a, int b, int c)
{
    return a + b + c;
};

int main()
{
    // std::function wraps a function that take int parameter and return value type is also int.
    std::function<int(int)> func1 = demo;

    int num = 10;
    std::function<int(int)> func2 = [&](int val) -> int { return 1 + num + val; };

    std::cout << func1(10) << std::endl;
    std::cout << func2(10) << std::endl;

    // first parameter a is placehold, can be passed later; 1 -> b; 2 -> c
    auto bindFunc = std::bind(demoBind, std::placeholders::_1, 1, 2);
    std::cout << "binded function result: " << bindFunc(1) << std::endl;
 
    return 0;
}
