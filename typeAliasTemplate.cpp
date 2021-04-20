/*
   What is template? What is type? We should be clear on this.

   Template is use to generate type.

   In traditional C++, typedef can define a new name for a type;
but for template, we can't do this because template is not a type.

   C++ 11 allows to use the keyword using.
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

// This is not allowed
template <typename T>
typedef magicType<vector<T>, string> IllegalMagicType;

// In C++11
template <typename T>
using legalMagicType = magicType<vector<T>, string>;
int main()
{
    legalMagicType<bool> test;

    return 0;
}

