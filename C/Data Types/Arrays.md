# Arrays in C
An array is a data structure that stores a set of elements, each of which has to be of the same datatype. Arrays are not limited to primitive types, so you can make an
array of arrays (a matrix), and an array of arrays of arrays (a tensor). Declaring an array uses the following format <br /> `datatype name[size];`.
```C
#include <stdio.h>

int main(void)
{
    // Declare a 1D array of 5 elements (integers, all of which are 0)
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
