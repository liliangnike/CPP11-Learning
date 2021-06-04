/*
	Like the name, std::unique_ptr is exclusive smart pointer that prohibits other smart pointers from sharing the same object.

	std::make_unique was provided from C++ 14.

	Because it is unique and can't be copied. So we can use std::move to transfer it to other unique_ptr.
*/
#include <iostream>
#include <memory>

struct Foo {
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) {
    std::cout << "f(const Foo&)" << std::endl;
}

int main()
{
    std::unique_ptr<Foo> p1 = std::make_unique<Foo>();
    
    if (p1) p1->foo();
    {
	std::unique_ptr<Foo> p2 = std::move(p1);
	
	f(*p2);

	if (p2) p2->foo();

	if(p1) p1->foo(); //p1 is empty, because move

	p1 = std::move(p2);

	if(p1) p1->foo();

	std::cout << "p2 is destroyed" << std::endl;
    }

    if (p1) p1->foo();

    return 0;
}
