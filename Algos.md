## Sum of an Array

```C++
#include <iostream>
using namespace std;

//The amount of elements in an array is the size of the array in bytes divided by the size of a single element
#define SIZE(array) sizeof(array) / sizeof(array[0])


// Function 'sum()' finds and returns the sum of all the elements in an array
template <typename T>
T sum(const T array[], const size_t size)
{
    T result = 0;

    for(size_t i=0; i < size; i++)
    {
        result += array[i];
    }

    return result;
}


// DRIVER CODE //
int main()
{
    int arr[5] {1, 2, 3, 4, 5};

    cout << "The sum of the array is: " << sum<int>(arr, SIZE(arr)) << '\n';

    return 0;
}
```


## Binary Search

```C++
#include <iostream>
using namespace std;

/*
The amount of elements in an array is the size of the array in bytes divided by the size of a single element.
This only works in the same scope the array is declared in as most operations (including passing an array)
cause the array to decay into a pointer.
*/
#define SIZE(array) sizeof(array) / sizeof(array[0])


//Templated binary search using an iterative approach
template <typename T>
bool binarySearch(const T array[], const T searchVal, const size_t size) //Returns 'true' because '-1' is a valid search value
{
    //Initial points for left and right (and declaration of midpoint)
    size_t left = 0, right = size - 1;
    size_t middle;

    //Search loop (continues until list is exhausted)
    while (left <= right)
    {
        //Calculate the midpoint
        middle = (left + right) / 2;    //Still integer division since 'size_t' is a special ULL

        //Search value found?
        if (array[middle] == searchVal)
            return true;

        //Otherwise cut in half again and start over
        else if (searchVal < array[middle])  //Discards the greater half
            right = middle - 1;

        else if (searchVal > array[middle])  //Discards the smaller half
            left = middle + 1;

    }

    //If list is exhausted without finding the value, then return false
    return false;
}


// DRIVER CODE //
int main()
{
    //An array of 10 sorted integers, 1-10
    int arr[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int elem = 5;

    //Search for the element using binary search
    if ( binarySearch(arr, elem, SIZE(arr)) )
        cout << "The element \'" << elem << "\' is in the array\n";
    else
        cout << "The element \'" << elem << "\' is NOT in the array\n";

    return 0;
}
```
