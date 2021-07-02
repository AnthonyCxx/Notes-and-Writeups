# Arrays in C
An array is a data structure that stores a set of elements, each of which has to be of the same datatype. Arrays are not limited to primitive types, so you can make an
array of arrays (a matrix), and an array of arrays of arrays (a tensor). Declaring an array uses the following format <br /> `datatype name[size];`. The size of the array
_must_ be known at compile time, unless [allocated dynamically](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/).
```C
#include <stdio.h>

int main(void)
{
    // Declare a 1D array of 5 elements (integers, all of which are 0)
    // In C, memory does not have a default value. You MUST initialize it before using it.
    int simple_array[5] = {0, 0, 0, 0, 0};

    // Print the values of the array
    printf("Array contents: ");

    // Loop over the array
    for(int index=0; index < 5; index++)  // 5 is the size of the array
    {
        printf("%d ", simple_array[index]);
    }
    putchar('\n');     //Endline

    return 0;
}
```


## Jagged Arrays
[article](https://thispointer.com/allocating-and-deallocating-2d-arrays-dynamically-in-c-and-c/)
