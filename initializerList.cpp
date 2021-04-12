/*
In traditional C++, we can initialize an array like this:
    int arr[3] = {1, 2, 3};

    we also can initialize a class object like this:
    classA classA(1, 2, 3);

but the methods are specific to each other and not generic.

C++ 11 make it to be generic by std::initializer_list.
 
*/
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;


class foo
{
public:
    vector<int> vec;

    // constructor to use initializer_list
    foo(std::initializer_list<int> initialValues)
    {
	for (std::initializer_list<int>::iterator it = initialValues.begin(); it != initialValues.end(); it++)
	{
	    vec.push_back(*it);
	}
    }

    // this feature also can be used by a member function
    /*void func(std::initializer_list<int> initialValues)
    {     
        for (std::initializer_list<int>::iterator it = initialValues.begin(); it != initialValues.end(); it++)
        {
            vec.push_back(*it);
        }
    }*/
};

int main()
{
    // constructor to use initializer_list
    foo test = {1, 2, 3, 4};

    // member function to use initializer_list
    // foo.func({1, 2, 3, 4});

    for ( auto i : test.vec )
    {
	cout << i << endl;
    }
 
    return 0;
}

