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
The [_malloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm) function allocates _n_ bytes where _n_ is an integer provided as the function argument.
Memory allocated with _malloc()_ **does not have a datatype** by default and must be typecasted via `(datatype*)`. Any memory allocated with _malloc()_ must be freed with 
[_free()_](https://www.tutorialspoint.com/c_standard_library/c_function_free.htm). You could memorize the size of every datatype, or you could just use the [_sizeof() operator_](https://www.geeksforgeeks.org/sizeof-operator-c/). Really though, use the _sizeof()_ operator because the size of a given datatype may vary from system to system.

Finally, if _malloc()_ cannot allocate memory (because there is not enough room), then it will return NULL.

```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allocate memory for a single integer and typecast the memory to an integer pointer
    int* ptr = (int*) malloc( sizeof(int) );

    // Always check for errors
    if (ptr == NULL)
        puts("Error: No memory available");      // This should almost never happen unless asking for a massive array

    // Set the value of the dynamically-allocated memory
    *ptr = 5;

    // Use the value
    printf("The dynamically-allocated memory holds the integer value \'%d\'\n", *ptr);

    // Free the heap-allocated memory
    free(ptr);      // You can only free pointers, so you do not need to add the '*'

    return 0;
}
```
> Prints: <br />
> The dynamically-allocated memory holds the integer value '5' <br />

### Allocating Arrays with _malloc()_
Arrays are easy to allocate with _malloc()_, just multiply the amount of elements you want to allocate by the size of the datatype. <br />
The only hard part is accessing the array elements. To access the elements, add point to the beginning of the array ('ptr' in this case) and add the 
position of the element you want to access as an integer (this is called the offset).


```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allocate memory for a single integer and typecast the memory to an integer pointer
    int* ptr = (int*) malloc(15 * sizeof(int));      // An array of 15 integers

    // Always check for errors
    if (ptr == NULL)
        puts("Error: No memory available");      // This should almost never happen unless asking for a massive ptray


    // Initialize array values to 1-15
    for(int i=0; i < 15; i++)
    {
        *(ptr + i) = i + 1;    // '*(ptr + i)' is the pointer to the array + the offset
    }

    // Print array values
    for(int i=0; i < 15; i++)
    {
        printf("%d ", *(ptr + i));
    }
    putchar('\n');


    // Free the heap-allocated memory
    free(ptr);      // You can only free pointers, so you do not need to add the '*'

    return 0;
}
```
> Prints: <br />
> 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

## Allocating and Initializing Memory with _calloc()_

## Resizing Memory with _realloc()_

## Freeing Memory with _free()_

## Sources
Edpresso: [_How to Use "malloc" in C_](https://www.educative.io/edpresso/how-to-use-malloc-in-c) (good for beginners) <br />
TutorialsPoint: [_C - Malloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm) <br />
JavaTPoint: [_Dynamic Memory Allocation in C_](https://www.javatpoint.com/dynamic-memory-allocation-in-c) <br />
Wikibooks: [_C Programming/stdlib.h/malloc_](https://en.wikibooks.org/wiki/C_Programming/stdlib.h/malloc) <br />
Wikipedia: [_C Dynamic Memory Allocation_](https://en.wikipedia.org/wiki/C_dynamic_memory_allocation) <br />
