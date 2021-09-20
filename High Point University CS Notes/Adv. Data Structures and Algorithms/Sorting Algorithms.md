# Sorting Algorithms
> By complexity: <br />
> [O(n²)](https://github.com/EthanC2/Notes-and-Writeups/blob/main/High%20Point%20University%20CS%20Notes/Adv.%20Data%20Structures%20and%20Algorithms/Sorting%20Algorithms.md#on-complexity) <br />
> [O(n log n)](https://github.com/EthanC2/Notes-and-Writeups/blob/main/High%20Point%20University%20CS%20Notes/Adv.%20Data%20Structures%20and%20Algorithms/Sorting%20Algorithms.md#on-log-n-complexity) <br />

# O(n²) Complexity

## Exchange Sort
Time Complexity: O(n²) <br />
Slowest when: <br />
Fastest when: <br />

```C++
template <typename T>
void Swap(T& a, T& b)  //Cannot be 'swap' (lowercase) since it's a pre-defined function
{
    T temp(move(a));
    a = move(b);
    b = move(temp);
}

template <typename T>
void exchangeSort(T array[], size_t size)
{
    //For every element in the array
    for(size_t i=0; i < size-1; i++)
    {
        //Compare every element after it to the current element (i), swapping if needed
        for(size_t j=i+1; j < size; j++)
        {
            if (array[i] > array[j])
                Swap<T>(array[i], array[j]);
        }
    }
}
```

## Selection Sort
Time Complexity: O(n²) <br />
Slowest when: <br />
Fastest when: <br />
 
```C++
#include <iostream>
#include "RandomArray.hpp"
using namespace std;

//Swap function
template <typename T>
void Swap(T& a, T& b)
{
    T temp(move(a));
    a = move(b);
    b = move(temp);
}

template <typename T>
void selectionSort(T array[], size_t size)
{
    //To keep track of the smallest number in the array
    size_t min;

    //For every element in the array
    for(size_t i=0; i < size-1; ++i)
    {
        //Set the 'smallest' number to the current index
        min = i;

        //Starting at the current index, iterate over the rest of the indices until the array is exhausted
        for(size_t j=i+1; j < size; ++j)
        {
            //If you come across a smaller number while iterating, set it to the smallest number
            if (array[j] < array[min])
                min = j;
        }

        //Swap the current index with the smallest number found
        Swap<T>(array[i], array[min]);
    }

}
```

## Bubble Sort
Time Complexity: O(n²) <br />
Slowest when: <br />
Fastest when: <br />

```C++

```

## Insertion Sort
Time Complexity: O(n²) <br />
Slowest when: <br />
Fastest when: <br />

```C++

```

# O(n log n) Complexity

## Merge Sort
Time Complexity: O(n²) <br />
Slowest when: <br />
Fastest when: <br />
