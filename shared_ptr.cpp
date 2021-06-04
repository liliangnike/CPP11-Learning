/*
	Just like the name, std::shared_ptr is a smart pointer that records how many objects are sharing the pointer. No need to call 'delete' operator.

	std::make_shared also make std::shared_ptr to avoid using 'new'.

	Useful utilities:
	get() -> get the raw pointer
	reset() -> reduce the reference count (objects number)
	use_count() -> reference count
*/
#include <iostream>
#include <memory>

void demo(std::shared_ptr<int> i)
{
    (*i)++;
}

int main()
{
    auto pointer = std::make_shared<int>(10);
    demo(pointer);
    std::cout << *pointer << std::endl;	// 11, pointer will be destroyed before leaving the end of the main function

    auto pointer2 = pointer; 	//reference count + 1
    auto pointer3 = pointer;    // reference count + 1

    int *p = pointer.get(); // get raw pointer

    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3
   
    pointer2.reset();
    std::cout << "reset pointer2: " << std::endl; 
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2

    pointer3.reset();
    std::cout << "reset pointer3: " << std::endl; 
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0

    return 0;
}
