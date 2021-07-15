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
#include <assert.h>   // for 'assert(0)'

int main(void)
{
    // Allocate memory for a single integer and typecast the memory to an integer pointer
    int* ptr = (int*) malloc( sizeof(int) );

    // Always check for errors
    if (ptr == NULL)
    {
        puts("Error: No memory available");      // This should almost never happen unless asking for a massive array
        assert(0);
    }

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

```C
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>   // for 'assert(0)'

int main(void)
{
    // Allocate memory for an array of 15 integers, typecasting to 'int*'
    int* ptr = (int*) malloc(15 * sizeof(int));      

    // Always check for errors
    if (ptr == NULL)
    {
        puts("Error: No memory available");      // This should almost never happen unless asking for a massive array
        assert(0);
    }


    // Initialize array values to 1-15
    for(int i=0; i < 15; i++)
    {
        ptr[i] = i + 1;
    }

    // Print array values
    for(int i=0; i < 15; i++)
    {
        printf("%d ", ptr[i]);
    }
    putchar('\n');


    // Free the heap-allocated memory
    free(ptr);      // You can only free pointers, so you do not need to add the '*'

    return 0;
}
```
> Prints: <br />
> 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

## Initializing Memory with _memset()_
Unlike the other functions here, [_memset()_](https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm) does not belong to [_\<stdlib.h\>_](https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm); instead, it's a part of the [_\<string.h\>_](https://www.tutorialspoint.com/c_standard_library/string_h.htm) 
header file. _memset()_ allows you to set each byte in memory to a specific value.

**WARNING:** _memset()_ belongs under _\<string.h\>_ for a reason. _memset()_ sets each individual byte to the given value; if you try to set an integer array to 100, 
it will set each of the 4 bytes in the int to 100, giving your 0x64646464 (1,684,300,900). _memset()_ is only suitable for setting char array and setting and integer 
array to 0 (because all bytes are 0 -- a special case). If you want to initialize an integer array, do it manually with a for loop.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // includes 'memset()'
#include <assert.h>   // includes 'assert()'

int main(void)
{
    // Allocate an array of 10 chars on the heap
    char* arr = (char*) malloc( 10 * sizeof(char) );

    // Always check for errors BEFORE working with the memory
    if (arr == NULL)
    {
        puts("Error: No memory available");      // This should almost never happen unless asking for a massive array
        assert(0);
    }

        // If the memory is good, initialize it
        memset(arr, 'A', 10 * sizeof(char));      // Pointer to the array, value to set the bytes to, and the size in bytes

        // Print the values of the array
        for(int i=0; i < 10; i++)
        {
                printf("%c ", arr[i]);
        }
        putchar('\n');

    // Free the heap-allocated memory
    free(arr);      // You can only free pointers, so you do not need to add the '*'

    return 0;
}
```
> Prints: <br />
> A A A A A A A A A A <br />

## Allocating and Initializing Memory with _calloc()_
[_calloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_calloc.htm) makes initializing arrays even easier as it combines the alloccation and 
initialization by giving each element a default value (0). All _calloc()_ needs is the amount of elements and the size of each of them. If you do not need to use 
_calloc()_, use _malloc()_ instead as it's far more efficient.

```C
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>   // for 'assert(0)'

int main(void)
{
   // Allocate memory for an array of 15 integers, typecasting to 'int*' (each value = 0)
    int* ptr = (int*) calloc(15, sizeof(int));   

    // Always check for errors
    if (ptr == NULL)
    {
        puts("Error: No memory available");      // This should almost never happen unless asking for a massive array
        assert(0);
    }

    // Print array values
    for(int i=0; i < 15; i++)
    {
        printf("%d ", ptr[i]);
    }
    putchar('\n');


    // Free the heap-allocated memory
    free(ptr);      // You can only free pointers, so you do not need to add the '*'

    return 0;
}
```
> Prints: <br />
> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

## Resizing Memory with _realloc()_
[_realloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm) allows you to resize a chunk of allocated memory. You can downsize a block of memory
using _realloc()_ and if you set it to 0 then the memory will be deallocated. Note that _realloc()_ does NOT initialize any new memory it allocates. Like _malloc()_ and
_calloc()_, _realloc()_ returns NULL if it fails.

```C
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>   // for 'assert(0)'

int main(void)
{
    // Allocate memory for a single integer and typecast the memory to an integer pointer
    int* ptr = (int*) calloc(15, sizeof(int));      // An array of 15 integers

   // Always check for errors
    if (ptr == NULL)
    {
        puts("Error: No memory available");      // This should almost never happen unless asking for a massive array
        assert(0);
    }


    // Print array values
    for(int i=0; i < 15; i++)
    {
        printf("%d ", ptr[i]);
    }
    putchar('\n');

    // Resize array to 20 elements
    ptr = (int*) realloc(ptr, 20);          // Does not initialize the new 5 elements!

    // Print array values
    for(int i=0; i < 20; i++)
    {
        printf("%d ", ptr[i]);
    }
    putchar('\n');


    // Free the heap-allocated memory
    free(ptr);      // You can only free pointers, so you do not need to add the '*'

    return 0;
}
```
> Prints: <br />
> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 <br />
> 0 0 0 0 0 0 49 0 0 0 -785997808 32767 0 0 0 0 0 0 4113 0 <br />

## Freeing Memory with _free()_
The [_free()_](https://www.tutorialspoint.com/c_standard_library/c_function_free.htm) function deallocates any memory allocated with _malloc()_, _calloc()_ or _realloc()_.
It's the equivalent of C++'s [_delete_](https://www.geeksforgeeks.org/delete-in-c/) keyword. <br />
You **must** ues _free()_ every time you finish using some variable that was declared using any of the three prior functions.

```C
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>   // for 'assert(0)'

int main(void)
{
    // Allocate memory for a single integer and typecast the memory to an integer pointer
    int* ptr = (int*) malloc( sizeof(int) );

    // Always check for errors
    if (ptr == NULL)
    {
        puts("Error: No memory available");      // This should almost never happen unless asking for a massive array
        assert(0);
    }

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

## Sources
Edpresso: [_How to Use "malloc" in C_](https://www.educative.io/edpresso/how-to-use-malloc-in-c) (good for beginners) <br />
TutorialsPoint: [_C - Malloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm) <br />
JavaTPoint: [_Dynamic Memory Allocation in C_](https://www.javatpoint.com/dynamic-memory-allocation-in-c) <br />
Wikibooks: [_C Programming/stdlib.h/malloc_](https://en.wikibooks.org/wiki/C_Programming/stdlib.h/malloc) <br />
Wikipedia: [_C Dynamic Memory Allocation_](https://en.wikipedia.org/wiki/C_dynamic_memory_allocation) <br />
