# Arrays in C
An array is a derived type that stores a set of elements, each of which has to be of the same datatype. Arrays are not limited to primitive types, so you can make an an
array of structs, array of arrays (a matrix), and an array of arrays of arrays (a tensor). Declaring an array uses the following format <br /> `datatype name[size];`. 
The size of the array _must_ be known at compile time, unless [allocated dynamically](https://www.cplusplus.com/doc/tutorial/dynamic/).

## Declaring an Array
```C++
#include <iostream>
using namespace std;

int main(void)
{
    // Declare a 1D array of 5 elements (integers, all of which are 0)
    // In C++, memory does not have a default value. You MUST initialize it before using it.
    int simple_array[5] = {0, 0, 0, 0, 0};

    // Print the values of the array
    cout << "Array contents: ";

    // Loop over the array
    for(int index=0; index < 5; index++)  // 5 is the size of the array
    {
        cout << simple_array[index] << " ";
    }
    cout << '\n';     //Endline

    return 0;
}
```
> Leaving the array uninitialized gave me the following output: 0, 0, 873242784, 32692, -524434688

## Array Trick: Calculating Size on the Fly
Writing flexible code in C++ can be challenging at times because of the lack of built-in tools. For example, if you wanted to write a flexible function that could iterate
over any array, you would need to know the size of said array; however, there is no [_Array.Length_](https://docs.microsoft.com/en-us/dotnet/api/system.array.length?view=net-5.0) property like in C#. To solve this problem, you have to resort to a pretty neat trick. Assuming that all the elements of the array are the same size in bytes (which
is true for all arrays of primitive types), then you can calculate the size of the array by finding the size of the array in bytes and dividing it by the size of the 
first element in the array. This can be done in a single macro: `#define SIZE(array) sizeof(array) / sizeof(array[0])`.

**WARNING**: this trick does not work with pointers (it would just return the size of the pointer); that means that this trick will not work for arrays passed as 
paramters nor arrays created with the [_new_](https://docs.microsoft.com/en-us/cpp/cpp/new-operator-cpp?view=msvc-160) keyword. If you want to use this trick in a function, 
pass the size of the array as a separate parameter.

```C++
#include <iostream>
using namespace std;

#define SIZE(array) sizeof(array) / sizeof(array[0])
//                  ^ size of the array   ^ size of the first element

int main(void)
{
    int hugeArray[100'000];   // You can use a single apostrophe as a comma in C++

    int arraySize = SIZE(hugeArray);

    cout << "The size of the huge array is exactly " << arraySize << '\n';

    return 0;
}
```

## Passing Arrays as Parameters
Arrays are always [passed by reference](https://www.ibm.com/docs/en/zos/2.2.0?topic=calls-pass-by-reference-c-only), not [by value](https://www.tutorialspoint.com/cplusplus/cpp_function_call_by_value.htm), this is beacuse "the name of the array itself is just a pointer to the first element"
(via notes from [Florida State University](https://www.cs.fsu.edu/~myers/c++/notes/pointers2.html)). Passing an array as a parameter is exactly the same as passing 
a variable, except you need to put _\[\]_ (brackets) after the array name to indicate that it's an array (it's not necessary include the size of the array in the brackets). 
```C++
#include <iostream>
#define SIZE(array) sizeof(array) / sizeof(array[0])
using namespace std;

void printArray(int array[], int size)
{
    // Header
    cout << "Array values: ";

    // Loop over values
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    // Ending
    cout << '\n';
}

void zeroFill(int array[], int size)  // 'int array[]' is converted to 'int* array' by the compiler
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

        /*
                         NOTE: The array size must be passed as a parameter
                         because the 'SIZE()' macro doesn't work inside
                         of functions unless the array was declared inside of functions.
    */

    // Before
    cout << "BEFORE zero-filling the array...\n";
    printArray(array, SIZE(array));

    // Zero-fill
    zeroFill(array, SIZE(array));

    // After
    cout << "\nAFTER zero-filling the array...\n";
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

## Returning an Array from a Function
Arrays can be returned from a function with `return array;`. Remember that the name of the array is just a pointer to the first element, so you will need to catch
the array with a pointer of the same type as the array. If you declare the array in the function _without_ declaring it on the heap,
the array will be deallocated when the function [goes out of scope](https://stackoverflow.com/questions/34586141/what-does-going-out-of-scope-means-in-c-objects#:~:text=A%20name%20like%20i%20can,a%20local%20loop%20variable%20i%20.) and you will have a [dangling pointer](https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/). Below, the function _createScoreboard()_ returns a new array (so it must be allocated on the heap).

```C++
#include <iostream>
#define SIZE(array) sizeof(array) / sizeof(array[0])
using namespace std;

// Creates an integer array that represents the players scores
int* createScoreboard(int playerCount)
{
    // Declare a new arra
    int* array = new int[playerCount];

    // Array is NULL if not enough space on the heap for a new array
    if (array == NULL)
    {
                //fprintf means print to file: stderr is a 'file' in UNIX
        fprintf(stderr, "Failed to allocate a new array. Returning NULL.\n");
    }

    // Return the array to main
    return array;
}

int main(void)
{
    // Declare a pointer to catch the scoreboard
    int* scoreboard;

    // Create and catch a new scoreboard
    scoreboard = createScoreboard(5);

    // Print all the elements of the array
    printf("Array elements: ");
    for(int i=0; i < 5; i++)
    {
        cout << scoreboard[i] << " ";
    }
    cout << '\n';

    // Free the memory of the scoreboard on the heap (prevents memory leak)
    delete [] scoreboard;

    return 0;
}
```
> Prints: <br />
> 0 0 0 0 0
>
> Note: After doing some testing, it seems that dynamically-allocated arrays are automatically initialized to 0

## Multi-dimensional Arrays
[Multi-dimensional arrays](https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/) are arrays that themselves contain arrays. These contained arrays
are uniform in size and can even store other arrays to create 3-dimensional arrays and so on. When
you access a multi-dimensional array, you have to specify the row and column like so: `array[row][column]`. Passing a multi-dimensional array as a parameter requires
putting a set of _\[\]_ for each dimension and [putting the amount of dimensions (excluding the first) in the corresponding bracket](https://stackoverflow.com/questions/2828648/how-to-pass-a-multidimensional-array-to-a-function-in-c-and-c). See below for an example.

```C++
#include <iostream>
#define SIZE(array) sizeof(array) / sizeof(array[0])
using namespace std;

// Print multi-array
void printMultiArray(int array[][3], int rows, int cols)   // Second dimension must be known
{
    // General header
    puts("Array Contents:");

    // For each row
    for(int row=0; row < rows; row++)
    {
        // Print the header for the row
        cout << "Row " << row << " contents: " ;

        // Print all the elements in the row
        for(int element=0; element < cols; element++)
        {
            // Print the element, follow by a space
            cout << array[row][element] << " ";
        }

        // Newline at the end of each row
        cout << '\n';
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
> Prints: <br />
> Array Contents: <br />
> Row 0 contents: 1 2 3 <br />
> Row 1 contents: 4 5 6 <br />
> Row 2 contents: 7 8 9 <br />
