# Searching Algorithms

## Sequential Search

```C++
#define SIZE(array) sizeof(array) / sizeof(array[0])

template <typename T>
bool seqSearch(T array[], T key, size_t size)
{
    for (size_t i=0; i < size; i++)
    {
        if (array[i] == key)
            return true;
    }

    return false;
}
```
