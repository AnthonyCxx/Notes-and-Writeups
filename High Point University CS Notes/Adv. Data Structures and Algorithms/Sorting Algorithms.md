# Sorting Algorithms

## Exchange Sort
Time Complexity: O() <br />
Slowest when: <br />
Fastest when: <br />

```C++
template <typename T>
void Swap(T& a, T& b)
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
Time Complexity: O() <br />
Slowest when: <br />
Fastest when: <br />
 
```C++

```

## Bubble Sort
Time Complexity: O() <br />
Slowest when: <br />
Fastest when: <br />

```C++

```

## Insertion Sort


```C++

```
