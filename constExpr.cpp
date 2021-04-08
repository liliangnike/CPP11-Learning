/*
C++ 11 and later provides the keyword 'constexpr' to support user to declare
        function or object constructor or variables

        to tell complier that this is 'const expression' during compile phase.

This is different from the keyword 'const'
        1) const is for read-only variables. It is to tell users that the variable 
           can't be changed during runtime.
        2) constexpr is to tell compiler that this is const expression.

For array definition, const expression shoule be used.
*/
#include <iostream>
#define LEN 10

using namespace std;

int len_func()
{
    int i = 2;
    return i;
}

constexpr int len_func_constexpr()
{
    return 5;
}

// C++ 11 does not support local varianles, loops, branches internally. C++ 14 can support.
constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    char arr1[10];      // OK
    char arr2[LEN];     // OK
    
    int len = 10;
    // char arr3[len];     // NOK, compiler does not know the value of len
 
    const int len2 = len + 1;
    //  char arr4[len2];   // Most compiler ok, but it is illegal. Array size should be const expression type, but len2 is const constant.

    constexpr int len2_constexpr = 1 + 2 + 3;
    char arr4[len2_constexpr];     // OK

    // char arr5[len_func() + 5];  // NOK
    char arr6[len_func_constexpr() + 1];  // OK

    std::cout << fibonacci(10) << std::endl;   
 
    return 0;
}

