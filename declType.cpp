/*
  C++ 11 auto keyword can only type variable.
  After calculating the auto variables, user need to know the type of the expression

  We need use decltype to get type of an expression:
    decltype(expression)


  For decltype(auto) is mainly used to derive return value type of a forwarding function
*/

#include <iostream>
#include <type_traits>

using namespace std;

string lookup1();
string& lookup2();

/*
 For C++ 11,
string forwarding_lookup1()
{
    return lookup1();
}
string& forwarding_lookup2()
{
    return lookup2();
}
*/

// For C++ 14, decltype(auto) can be used

decltype(auto) forwarding_lookup1()
{
    return lookup1();
}
decltype(auto) forwarding_lookup2()
{
    return lookup2();
}

int main()
{
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    if(is_same<decltype(x), int>::value) cout << "x is type is int" << endl;
    if(is_same<decltype(x), double>::value) cout << "x is type is double" << endl;
    if(is_same<decltype(x), decltype(z)>::value) cout << "type x == type z" << endl;


    return 0;
}

