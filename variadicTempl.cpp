/*
    We can define varidic parameter for a function. But for template in traditional C++,
we only can specify fixed parameters.

    C++ 11 support users to define variadic parameters in template.


    For the time being, only know template cau support variadic parameters. Will do further learning in future.
*/
#include <iostream>
#include <vector>

using namespace std;


template<typename T, typename U>
class magicType
{
public:
    T tmp;
    U magic;
};

template<typename...VariadicP> class magicType;
template<typename P0, typename...VariadicP> class magicType;

int main()
{
    return 0;
}

