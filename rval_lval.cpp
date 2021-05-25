/*
    Left value and right value is distinguished by lifecycle of an object after an expression.

    1. What is lvalue, left value?
	Simply understanding, left value is the value to the left of assignment symbol.
	To be precise, lvaue is a presistent object still exists after an expression (might not be assignment expression).
	
	Its address can be obtained.

    2. What is rvalue, right value?
	The value on the right refers to the tmporary object that will not exist after an expression (might not be assignment expression) ends.

	int a = 3; 	// a is lvalue, 3 is rvalue


In C++ 11, rvalue is divided into 2 types: pvalue and xvalue. In traditional C++, prvalue and xrvalue are same concept.
	
    3. pvalue, pure rvalue
	Pure rvalues, such as 10, 3 + 4, "This is string", lambda expression
	
	Special case is that in class, string literal is rvalue; in other cases, string literal is lvalue.

	For example,
	class demo
        {
	    const char*&& right = "this is a rvalue";
	};

	but in other cases, 
	int main()
	{
	    const char * const &left = "this is a lvalue";
	}
	
    4. xvalue, expiring rvalue
	It is a destroyed rvalue but can be moved.

	See below example:
	vector<int> demo()
	{
	    vector<int> tmp = {1, 2, 3};
	    return tmp;
	}

	// In traditional C++, tmp will be assigned to v firstly and then to be destroyed. This causes a lot of system overhead if tmp is big.

	vector<int> v = demo();       // v is lvalue, demo() is pure rvalue; Once assignment copy finished, demo() will be destroyed immediately, can't be obtained any more.
	
	xvalue defines behavior that rvalue temporary object can be identified to support 'move' operation. ---- see std::move 

	move operation can eliminate many copy-and-assign operations.

    5. lvalue reference
	lvalue reference is reference in traditional C++. Please refer to traditional C++ for details on reference.
	
	int a = 0;
	int &b = a;    // & is to the left of =, so it is left value reference
	int *p = &a;   // & is to the right of =, so it is get address operation

    6. rvalue reference
	rvalue reference is xvalue. It is reference of right temporary object value.
	To get xvalue, use T &&.

	rvalue reference can extend liftcycle of right temporary object.

	int a = 10;
	int && b = a;  // illegal, a is lvalue and can't be initialized to rvalue reference
	int && c = 10; // OK

	std::move() is provided to convert lvalue to rvalue.
  	
*/

#include <iostream>
#include <string>

using namespace std;

void reference(string& str)
{
    cout << "lvalue reference" << endl;
}

void reference(string&& str)
{
    cout << "rvalue reference" << endl;
}

int main()
{
    string lv1 = "Left value string,";      //lv1 is lvalue;
    // string && rvalr = lv1;               // illegal
    string &&rv1 = move(lv1);		    // legal, move can convert lvalue to rvalue
    cout << rv1 << endl;

    const string &lv2 = lv1 + lv1; 	    // legal, lvalue reference

    string &&rv2 = lv1 + lv2;		   // legal, lv1 + lv2 becomes rvalue
    cout << rv2 << endl;

    reference(rv2);   
    return 0;
}
