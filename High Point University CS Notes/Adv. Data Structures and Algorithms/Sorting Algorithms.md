# Sorting Algorithms

## Exchange Sort

```C++
template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void exchangeSort(T array[], size_t size)
{
    //For every element in the array
    for(size_t i=0; i < size-1; i++)
    {
        //Compare every element after it to the current element, swapping if needed
        for(size_t j=i+1; j < size; j++)
        {
            if (array[i] > array[j])
                Swap<T>(array[i], array[j]);
        }
    }
}
```
