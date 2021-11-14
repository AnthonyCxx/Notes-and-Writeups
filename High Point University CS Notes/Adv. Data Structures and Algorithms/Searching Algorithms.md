# Searching Algorithms

## Sequential Search

```C++
template <typename T>
size_t seqSearch(T array[], T key, size_t size)
{
    //Iterate over the entire array
    for (size_t i=0; i < size; i++)
    {
        if (array[i] == key)  //If the key has been found
            return i;
    }

    //If the array has been exhausted without success, return false
    return -1;
}
```

## Binary Search (Iterative)

```C++
//Templated binary search using an iterative approach
template <typename T>
size_t binarySearch(const T array[], const T searchVal, const size_t size)
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
            return middle;

        //Otherwise cut in half again and start over
        else if (searchVal < array[middle])  //Discards the greater half
            right = middle - 1;

        else if (searchVal > array[middle])  //Discards the smaller half
            left = middle + 1;
    }

    //If list is exhausted without finding the value, then return -1
    return -1;
}
```

## Binary Search (Recursive)

```C++
//Templated binary search using a recursive approach
template <typename T>
size_t binarySearch(const T array[], const size_t left, const size_t right, const T searchVal)
{
    //Search loop (continues until list is exhausted)
    if (left <= right)
    {
        //Calculate the midpoint
        size_t middle = (left + right) / 2;    //Still integer division since 'size_t' is a special ULL

        //Search value found?
        if (array[middle] == searchVal)
            return middle;

        //Otherwise cut in half again and start over
        else if (searchVal < array[middle])  //Discards the greater half
            return binarySearch<T>(array, left, middle - 1, searchVal);

        else if (searchVal > array[middle])  //Discards the smaller half
            return  binarySearch<T>(array, middle + 1, right, searchVal);
    }

    //If list is exhausted without finding the value, then return false
    return -1;
}
```
