/*
     Traditional C++ does not distinguish "move" and "copy", resulting in a large mount of data copying, wasting time and space.

     rvalue reference solves the confuse of concept of "move" and "copy".

     move is to convert lvalue to rvalue reference.
*/
#include <iostream>
#include <utility> // std::move
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str = "Hello.";
    vector<string> vec;

    vec.push_back(str);		//copy, using vector push_back(const &T)
    cout << "After push_back (copy) operation, str is " << str << endl;   // str is still "Hello"

    vec.push_back(move(str));	//move, there is no copy action, using vector push_back(const &&T)
				//str will be moved to vec, move can reduce copy cost
    cout << "After push_back (move) operation, str is " << str << endl;   // str is already moved, empty
    
    return 0;
}

