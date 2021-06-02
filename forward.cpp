/*
	See an short example,
	
	void reference(int &v)
	{
	    cout << "lvalue reference" << endl;
	}

	void reference(int &&v)
	{
	    cout << "rvalue reference" << endl;
	}

	template <typename T>
	void demo(T&& v)
	{
	    cout << " Parameter passing is: " << endl;
	    reference(v);
	}

	pass(1);  -> reference(int &v)

	int n = 1;
	pass(n);  -> reference(int &&v)

	C++11 supports to reference a reference type based on below rules:

        //  Passed argument parameter type  -> function parameter type ==> changed to which type

	T& -> lvalue reference ==> T&

	T& -> rvalue reference ==> T&

	T&& -> lvalue reference ==> T&

	T&& -> rvalue reference ==> T&&

	YES. ONLY and ONLY if argument type is exactly same as reference type with function parameter type, the correct reference type can be derived.

	std::forward to perfect forward (pass) parameter type and keep the type to be same as original type.

	(lvalue reference keeps lvalue reference, rvalue reference keeps rvalue reference.
*/
#include <iostream>
#include <utility>

using namespace std;

int main()
{
    return 0;
}
