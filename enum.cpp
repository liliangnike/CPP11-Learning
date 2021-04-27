/*
    It is known that enumeration type is treated as integers typs.

    1. In the same namespace, differ enum type with same enum member name will not be compiled pass.

       enum fruits { APPLE, TOMATO, ORANGE};
       enum foods { CAKE, TOMATO, MEAT};      // compilation failure

    2. enum will be converted into integer type implicitly. User can't designate specific type for enums.

    3. Memory space is uncertain.

       enum A { A1 = 1, A2 = 2, ABig = 0xFFFFFFFFU};  
       enum B {B1 = 1, B2 = 2, BBig = 0xFFFFFFFFFUL};

       For ABig and BBig, differ OS platform, different result will be shown


    C++ 11 introduce strongly typed enumeration.
    1. enum class type will not be converted to integer type and can't be compared with integer type.
       Within same enum class type, differ members can be compared.

    2. Differ enum class type can have same name.

    3. Default base type of enum class is int.
*/
#include <iostream>

using namespace std;


// demo::V4 == 100, // illegal, can not compare with integer type
enum class demo : unsigned int
//enum class demo  // if so, default type is int
{
    V1,
    V2,
    V3 = 100,
    V4 = 100
};

int main()
{
    if (demo::V3 == demo::V4)
    {
	cout << "V3 == V4" << endl;
	cout << "Values are, V3 = " << demo::V3 << ", V4 = " << demo::V4 << endl;  // compile error, << should be overload
    }

    return 0;
}

