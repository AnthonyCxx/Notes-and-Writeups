# Searching Algorithms

## Sequential Search

```C++
template <typename T>
bool seqSearch(T array[], T key, size_t size)
{
    //Iterate over the entire array
    for (size_t i=0; i < size; i++)
    {
        if (array[i] == key)  //If the key has been found
            return true;
    }

    //If the array has been exhausted without success, return false
    return false;
}
```

## Binary Search

```C++
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
```
