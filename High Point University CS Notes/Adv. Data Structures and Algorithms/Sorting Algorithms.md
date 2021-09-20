# Sorting Algorithms
> By complexity: <br />
> [O(n²)]() <br />
> [O(n log n)]() <br />

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
