/*
This file ic copied from the file constExpr.cpp.
For review on the keyword constexpr, I kept below notes.

C++ 11 and later provides the keyword 'constexpr' to support user to declare
        function or object constructor or variables

        to tell complier that this is 'const expression' during compile phase.

This is different from the keyword 'const'
        1) const is for read-only variables. It is to tell users that the variable 
           can't be changed during runtime.
        2) constexpr is to tell compiler that this is const expression.

For array definition, const expression shoule be used.


====================================

    Based on above introduction on constexpr, can we use constexpr into conditional judgment?
If so, code will complete judgment during complile phase, the program will be more efficient.
  
    C++ 17 support this.
*/
#include <iostream>

using namespace std;


/*
    The actual behavior during compile phase will be like below:
int print_type_info(const int &t)
{
    return t + 1;
}

double print_type_info(const double &t)
{
    return t + 0.001;
}
*/

template<typename T>
auto print_type_info(const T &t)
{
    if constexpr (is_integral<T>::value)
    {
	return t + 1;
    }
    else
    {
	return t + 0.001;
    }
}

int main()
{
    cout << print_type_info(5) << endl;
    cout << print_type_info(3.14) << endl;
    return 0;
}

