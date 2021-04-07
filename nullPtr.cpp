/*
If C++ complier does not allow to convert void * to any other type, it has to define NULL as 0.
There will be problem.
C++ has feature of overloading when calling a function. If we have function declaration:
void func(char *);
void func(int);

So func(NULL) will call func(int). The result will be defferent.

To solve this, nullptr is introduced into C++11.

The output of this program will show that NULL is not 0 and nullprt.

****
    In C++11 development, please user nullprt directly.
****
*/
#include <iostream>
#include <type_traits>

using namespace std;

void func(char *);
void func(int);

int main()
{
    if(is_same<decltype(NULL), decltype(0)>::value) cout << "NULL == 0" << endl;
    if(is_same<decltype(NULL), decltype((void *)0)>::value) cout << "NULL == (void *)0" << endl;
    if(is_same<decltype(NULL), std::nullptr_t>::value) cout << "NULL == nullptr" << endl;

    func(0);
    func(nullptr);

    return 0;
}

void func(char *)
{
    cout << "func (char *) is called." << endl;
}

void func(int)
{
    cout << "func (int) is called." << endl;
}
