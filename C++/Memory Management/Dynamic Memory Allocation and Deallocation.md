# Dynamic Memory Allocation and Deallocation in C++
> Pre-requisite: [_Pointers_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20and%20Data%20Types/Pointers.md)

Typically, when you declare a variable (an array, let's say) you know in advance how big it will need to be; however, this is not always the case.
The need to store data that we do not already know the size of gave rise to the need for [dynamic memory allocation](https://www.tutorialspoint.com/cplusplus/cpp_dynamic_memory.htm), the ability to declare variables (and even data structures) at runtime. Dynamic memory is stored in
[the heap](https://www.dummies.com/programming/cpp/how-the-heap-works-in-c/) as opposed to the stack (ref. [_The Stack vs the Heap_](https://nickolasteixeira.medium.com/stack-vs-heap-whats-the-difference-and-why-should-i-care-5abc78da1a88)).
Dynamic memory is allocated and deallocated using two keywords: [_new_](https://www.youtube.com/watch?v=NUZdUSqsCs4) and [_delete_](https://www.journaldev.com/38336/delete-operator-in-c-plus-plus). Always remember to free dynamically-allocated memory after you are done with it, as the computer does not free it for you (unlike stack-allocated memory); if you forget to free dynamically-allocated memory, it will remain allocated. This problem is known as [memory leak](https://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/) and can debilitate a system to the point of crashing it.

C++ also has access to C's memory allocation functions under [_\<cstdlib\>_](https://www.programiz.com/cpp-programming/library-function/cstdlib); however, using them in C++
is discouraged because functions like [malloc()](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm) do not call constructors (wheras _new_ does).

## Allocating and Deallocating Memory with _new_ and _delete_
The _new_ keyword declares a new instance of an object (in the raw memory sense) on the heap at runtime, allowing you to create as much memory as you need,
whenever you need it. The _new_ keyword also returns a pointer to the newly-allocated data, so be sure to catch it with a pointer of the appropriate type
(e.g. `int* ptr = new int;`). To delete allocated memory, delete the pointer directly instead of dereferencing it, like so: `delete ptr;`. You don't 
need to dereference the pointer to delete what it points to because you can only use _delete_ with pointers, so it's implicitly understood. And no,
writing `delete ptr;` does not delete the pointer, just its contents.

**WARNING**: if you delete a pointer that has already been deleted (if you delete a pointer twice), then you will get a segmentation fault and your program will crash.
```C++
#include <iostream>
using namespace std;

int main()
{
    //Declare a new integer, allocated dynamically
    int* ptr = new int;

    //Assign to the new integer
    *ptr = 5;

    //Use the new integer
    cout << "The new pointer contains: " << *ptr << '\n';

    //Free the dynamically allocated memory
    delete ptr;

    return 0;
}
```

You should use _new_ and _delete_ in C++ instead of C's _malloc()_ and _free()_ because unlike _malloc()_ and _free()_, _new_ and _delete_
also call the constructors/destructors of objects when the memory is allocated/deallocated. Oh, and both _new_ and _delete_ can be overloaded
since they're operators.

## Allocating and Deallocating Arrays with _new[]_ and _delete[]_
_new_ and _delete_ are expectionally useful for arrays since it avoids the problem of having to know the size of the array at compile time.
You use _new_ and _delete_ with arrays just like you do with primitive data types, except you need to add brackets. A new integer array would
look like this: `int* newArray = new int[10];` and deleting the array would look like this: `delete [] newArray`.

From doing some testing, I've found that arrays seem to be initialized to 0 by default, but you should initialize them anyway.
```C++
#include <iostream>
using namespace std;

/*
    As a rule of thumb, be sure to keep track of the size of dynamically-allocated arrays;
    otherwise, you'll be stuck with an array you don't know the size of.
*/

int main()
{
    //Size should be 'size_t' (or at least unsigned) so it can't be negative
    size_t size;

    //Get the size of the array
    cout << "Enter the size of the array you want to create: ";
    cin >> size;

    //Declare a new array of the requested size
    int* arrptr = new int[size];   //arrptr stand for 'array pointer'

    //Use the stored size to iterate over the loop
    for(size_t i=0; i < size; i++)
    {
        cout << arrptr[i] << " ";
    }
    cout << '\n';

    //Delete the dynamically-allocated array
    delete [] arrptr;

    return 0;
}
```
_new[]_ and _delete[]_ are technically separate operators from _new_ and _delete_, so make sure you overload both if you overload one.
> Reference: [_C++ Standard Library: \<new\>_](https://www.cplusplus.com/reference/new/) 
