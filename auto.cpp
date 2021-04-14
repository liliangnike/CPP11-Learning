/*
  The keyword auto in C++11 is easily understanding.
  We have to pay attention to below case:
     Can't be used to derive array type

  C++11 should also not permit auto to be used for function argument
*/
#include <iostream>
#include <tuple>

using namespace std;

// C++ 11 may consider this as compile error, but in my g++ version, it is warning
// warning: use of ‘auto’ in parameter declaration only available with -fconcepts
// According to the warning, if compile with the command "g++ auto.cpp -fconcepts", no this error
// g++ version: g++ (Debian 8.3.0-6) 8.3.0
int add(auto x, auto y)
{
    return (int)(x + y);
}

int main()
{
    auto i = 0;
    auto arr = new auto(10);;

    auto arr2[10] = {arr};   //error: ‘arr2’ declared as array of ‘auto

    return 0;
}

