template <typename T>
std::size_t sequentialSearch(T arr[], std::size_t n, T key)
{
    //Interate over every element in the array
    for(std::size_t i=0; i < n; ++i)
    {
        if (arr[i] == key)  //If you find the item, return it
            return i;
    }

    //If list is exhausted, return -1 (sentinel value)
    return -1;
}
