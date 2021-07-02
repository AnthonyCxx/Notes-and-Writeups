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

## Array Trick: Calculating Size on the Fly
Writing flexible code in C can be challenging at times because of the lack of built-in tools. For example, if you wanted to write a flexible function that could iterate
over any array, you would need to know the size of said array; however, there is no [_Array.Length_](https://docs.microsoft.com/en-us/dotnet/api/system.array.length?view=net-5.0) method like in C#. To solve this problem, you have to resort to some pretty neat tricks. Assuming that all the elements of the array are the same size in bytes (which
is true for all arrays of primitive types), then you can calculate the size of the array by finding the size of the array in bytes and dividing it by the size of the 
first element in the array. This could be done in a single macro: `#define SIZE(array) sizeof(array) / sizeof(array[0])`.
```C
#include <stdio.h>

int main(void)
{
    int hugeArray[100000];

    int arraySize = sizeof(hugeArray) / sizeof(hugeArray[0]);
    //              ^ size of the array        ^ size of the first element

    printf("The size of the huge array is %d\n", arraySize);

    return 0;
}
```

## Jagged Arrays
[article](https://thispointer.com/allocating-and-deallocating-2d-arrays-dynamically-in-c-and-c/)
