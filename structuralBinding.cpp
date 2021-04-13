/*
C++ 11 provides std::tuple that support to return multiple values. It is similar
to other language, like Python.

But we have to know the number of objects that the tuple contains and the corresponding
type also need know.
 C++ 17 support coding like below. 
*/
#include <iostream>
#include <tuple>

using namespace std;

std::tuple<int, double, std::string> func()
{
    return std::make_tuple(1, 2.3, "test");
}

int main()
{
    auto [x, y, z] = func();
    cout << x << ", " << y << ", " << z << endl;
    return 0;
}

