/*
    Lambda expression function is similar to anonymous function.

    Basic syntax of C++11 Lambda expression:

	[capture list]  (parameter list) mutable exception attribute -> return type { function body; }

	Not all of them are mandatory, in actual using, some can be excluded.

	For example, belows are frrequent usage:

	-> 	[capture list] (params list) -> return type {function body}
	->	[capture list] (params list) {function body}
	->	[capture list] {function body}


	Capture list can be below types:
	1. Value
	2. Reference
	3. Implicit
	4. Expression

        For 1, 2, 3, capture the variables that already defined in the outer scope 

        
        Lambda is a class type (similar to function object type) essentially. 
	So lambda also can be called as a function type. --------------------------- see std::function for more details.       
*/

#include <iostream>
#include <memory>

using namespace std;

void lambda_capture_value()
{
    int val = 1;
    auto copy_val = [val] { return val; };
    // Implicit capture, value capture
    //auto copy_val = [=] { return val; };

    val = 100;
    auto saved_val = copy_val(); 
    // value is 1, it is copied when the lambda function is created
    cout << "After capture value, saved value is " << saved_val << endl;
};

void lambda_capture_reference()
{
    int val = 1;
    auto copy_val = [&val] { return val; };
    // Implicit capture, reference capture
    //auto copy_val = [&] { return val; };

    val = 100;
    auto saved_val = copy_val(); 
    // value is 100, bscause it is already passed by reference
    cout << "After capture reference, saved value is " << saved_val << endl;
};

void lambda_capture_expression()
{
    auto important = make_unique<int>(1); // after created, important is exclusive pointer, refer to unique_ptr in C++11, can't be moved or copied

    auto add = [v1 = 1, v2 = move(important)](int a, int b) -> int { return a + b + v1 + (*v2); };
    cout << "After capture expression, sum value is " << add(3, 4) << endl;
};

void lambda_generic()
{
    auto generic = [](auto a, auto b) { return a + b; };
    cout << "generic lambda -> " << generic(1, 2) << endl;
    cout << "generic lambda -> " << generic(1.1, 2.2) << endl;
};

// see std::function
using funcPtr = void(int);
void func(funcPtr f)
{
    f(1);
};

void lambda_call_as_function_object()
{
    auto f = [](int val) { cout << "Value is " << val << " after calling this lambda as function object." << endl;};
    func(f);    // calling f function pointer
    f(1);       // calling f by lambda
};

int main()
{
    lambda_capture_value();
    lambda_capture_reference();
    lambda_capture_expression();
    lambda_generic();
    lambda_call_as_function_object();

    return 0;   
}
