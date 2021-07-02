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
    printf("%s", "Array contents: ");

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
over any array, you would need to know the size of said array; however, there is no [_Array.Length_](https://docs.microsoft.com/en-us/dotnet/api/system.array.length?view=net-5.0) property like in C#. To solve this problem, you have to resort to some pretty neat tricks. Assuming that all the elements of the array are the same size in bytes (which
is true for all arrays of primitive types), then you can calculate the size of the array by finding the size of the array in bytes and dividing it by the size of the 
first element in the array. This can be done in a single macro: `#define SIZE(array) sizeof(array) / sizeof(array[0])`.
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

## Passing Arrays as Parameters
Arrays are always [passed by reference](https://www.tutorialspoint.com/cprogramming/c_function_call_by_reference.htm), not [by value](https://www.tutorialspoint.com/cprogramming/c_function_call_by_value.htm), this is beacuse "the name of the array itself is just a pointer to the first element"
(via notes from [Florida State University](https://www.cs.fsu.edu/~myers/c++/notes/pointers2.html)). Passing an array as a parameter is exactly the same as passing 
a variable, except you need to put _\[\]_ (brackets) after the array name to indicate that it's an array (do not include the size of the array in the brackets). 
```C
#include <stdio.h>
#define SIZE(array) sizeof(array) / sizeof(array[0])

void printArray(int array[], int size)
{
    // Header
    printf("Array values: ");

    // Loop over values
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    // Ending
    putchar('\n');
}

void zeroFill(int array[], int size)  // <== Notice that 'int array[]' does not have a '*' nor '&'
{
    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

int main(void)
{
    // An array with three sequential values
    int array[3] = {1, 2, 3};

    // Before
    puts("BEFORE zero-filling the array...");
    printArray(array, SIZE(array));

    // Zero-fill
    zeroFill(array, SIZE(array));

    // After
    puts("\nAFTER zero-filling the array...");
    printArray(array, SIZE(array));

    return 0;
}
```
> Prints: <br />
> BEFORE zero-filling the array... <br />
> Array values: 1 2 3 <br />
>
> AFTER zero-filling the array... <br />
> Array values: 0 0 0 <br />

## Multi-dimensional Arrays
[Multi-dimensional arrays](https://www.tutorialspoint.com/cprogramming/c_multi_dimensional_arrays.htm) are arrays that themselves contain arrays. These contained arrays
are uniform in size and can even store other arrays to create 3-dimensional arrays and so on. Anything beyond a two-dimensional array can be [quite confusing](https://www.youtube.com/watch?v=dQw4w9WgXcQ). When
you access a multi-dimensional array, you have to specify the row and column like so: `array[row][column]`. Passing a multi-dimensional array as a parameter requires
putting a set of _\[\]_ for each dimension and [putting the amount of dimensions (excluding the first) in the corresponding bracket](https://stackoverflow.com/questions/2828648/how-to-pass-a-multidimensional-array-to-a-function-in-c-and-c). See below for an example.

```C
#include <stdio.h>

// Print multi-array
void printMultiArray(int array[][3], int rows, int cols)   // Second dimension must be known
{
    // General header
    puts("Array Contents:");

    // For each row
    for(int row=0; row < rows; row++)
    {
        // Print the header for the row
        printf("Row %d contents: ", row);

        // Print all the elements in the row
        for(int element=0; element < cols; element++)
        {
            // Print the element, follow by a space
            printf("%d ", array[row][element]);
        }

        // Newline at the end of each row
        putchar('\n');
    }
}

/* DRIVER CODE */
int main(void)
{
    // 3x3 Array
    int multiArray[3][3] =  {
                                {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9},
                            };

    // Print multi-array
    printMultiArray(multiArray, 3, 3);

    return 0;
}
```

## Jagged Arrays
[article](https://thispointer.com/allocating-and-deallocating-2d-arrays-dynamically-in-c-and-c/)
