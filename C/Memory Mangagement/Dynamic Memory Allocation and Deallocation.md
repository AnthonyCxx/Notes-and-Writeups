# Dynamic Memory Allocation in C
> Pre-requisite: [Pointers](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Memory%20Mangagement/Pointers.md)

Typically, when you declare a variable (an array, let's say) you know in advance how big it will need to be; however, this is not always the case.
The need to store data that we do not already know the size of gave rise to the need for [dynamic memory allocation](https://www.programiz.com/c-programming/c-dynamic-memory-allocation), the ability to declare variables (and even data structures) at runtime. Dynamic memory is stored in [the heap](https://www.geeksforgeeks.org/memory-layout-of-c-program/) as opposed to the stack (ref. [_The Stack vs the Heap_](https://nickolasteixeira.medium.com/stack-vs-heap-whats-the-difference-and-why-should-i-care-5abc78da1a88)).
Dynamic memory is declared and managed using four C functions within the [_\<stdlib.h\>_](https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm) library:
[_malloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm), [_calloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_calloc.htm),
[_realloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm), and [_free()_](https://www.tutorialspoint.com/c_standard_library/c_function_free.htm).
These four functions allow you to delcare, resize, and free memory. Always remember to free dynamically-allocated memory after you are done with it, as the computer does not
free it for you (unlike stack-allocated memory); if you forget to free dynamically-allocated memory, it will remain allocated. This problem is known as 
[memory leak](https://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/) and can debilitate a system.

## Allocating Memory with _malloc()_


## Allocating and Initializing Memory with _calloc()_

## Resizing Memory with _realloc()_

## Freeing Memory with _free()_

## Sources
Edpresso: [_How to Use "malloc" in C_](https://www.educative.io/edpresso/how-to-use-malloc-in-c) (good for beginners) <br />
TutorialsPoint: [_C - Malloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm) <br />
JavaTPoint: [_Dynamic Memory Allocation in C_](https://www.javatpoint.com/dynamic-memory-allocation-in-c) <br />
Wikibooks: [_C Programming/stdlib.h/malloc_](https://en.wikibooks.org/wiki/C_Programming/stdlib.h/malloc) <br />
Wikipedia: [_C Dynamic Memory Allocation_](https://en.wikipedia.org/wiki/C_dynamic_memory_allocation) <br />
