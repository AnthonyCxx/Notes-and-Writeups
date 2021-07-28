# Dynamic Memory Allocation and Deallocation in C++
> Pre-requisite: [_Pointers_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20and%20Data%20Types/Pointers.md)

Typically, when you declare a variable (an array, let's say) you know in advance how big it will need to be; however, this is not always the case.
The need to store data that we do not already know the size of gave rise to the need for [dynamic memory allocation](https://www.tutorialspoint.com/cplusplus/cpp_dynamic_memory.htm), the ability to declare variables (and even data structures) at runtime. Dynamic memory is stored in
[the heap](https://www.dummies.com/programming/cpp/how-the-heap-works-in-c/) as opposed to the stack (ref. [_The Stack vs the Heap_](https://nickolasteixeira.medium.com/stack-vs-heap-whats-the-difference-and-why-should-i-care-5abc78da1a88)).
Dynamic memory is allocated and deallocated using two keywords: [_new_](https://www.youtube.com/watch?v=NUZdUSqsCs4) and [_delete_](https://www.journaldev.com/38336/delete-operator-in-c-plus-plus). Always remember to free dynamically-allocated memory after you are done with it, as the computer does not free it for you (unlike stack-allocated memory); if you forget to free dynamically-allocated memory, it will remain allocated. This problem is known as [memory leak](https://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/) and can debilitate a system to the point of crashing it.

## Allocating and Deallocating Memory with _new_ and _delete_
The _new_ keyword declares a new instance of an object (in the raw memory sense) on the heap at runtime, allowing you to create as much memory as you need,
whenever you need it. The _new_ keyword also returns a pointer to the newly-allocated data, so be sure to catch it with a pointer of the appropriate type
(e.g. `int* ptr = new int;`). To delete allocated memory, delete the pointer directly instead of dereferencing it, like so: `delete ptr;`. You don't 
need to dereference the pointer to delete what it points to because you can only use _delete_ with pointers, so it's implicitly understood. And no,
writing `delete ptr;` does not delete the pointer, just its contents.

You should use _new_ and _delete_ in C++ instead of C's _malloc()_ and _free()_ because unlike _malloc()_ and _free()_, _new_ and _delete_
also call the constructors/destructors of objects when the memory is allocated/deallocated.
```C++

```

## Allocating and Deallocating Arrays with _new[]_ and _delete[]_
