/*
In traditional C++, we can declare a variable within a for statement, e.g.
     for (int i = 0; i < sz; i++)

but there is no way to do this in if (or switch) statement.

C++ 11 supports this.
 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define LEN 10

using namespace std;


int main()
{
    vector<int> vec = {1, 2, 3, 4};

    // auto keyword is supported by C++17, please add -std=c++17 in g++ command to avoid warning
    // g++ -std=c++17 filename.cpp
    const auto it = find(vec.begin(), vec.end(), 2);
    if (it != vec.end()) 
    {
        *it = 3;
    }

    // if statement here is similar to for statement
    if ( const auto it = find(vec.begin(), vec.end(), 3);
	it != vec.end() )
    {
	*it = 4;
    }

    for ( auto i : vec)
        cout << i << endl;
 
    return 0;
}

