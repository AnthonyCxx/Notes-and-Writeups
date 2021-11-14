/*
  Templated, Recursive Binary Search
  =================================
  
  RREQUIREMENTS: data is sorted

  Time Complexity: O(log n)
  Space Complexity: O(log n)
*/

template <typename T>    //Array,        left side,          right side,          search value
std::size_t binarySearch(const T arr[], const std::size_t l, const std::size_t r, const T key)
{
    if (l <= r)
    {
        //Calculate the midpoint
        std::size_t mid = (l + r) / 2;

        //Search value found?
        if (key == arr[mid])
            return mid;    //Return the index of the key

        //Otherwise cut in half and start over
        else if (key < arr[mid])    //Discards the greater half and repeat the search
            return binarySearch<T>(arr, l, mid-1, key);

        else if (key > arr[mid])    //Discards the smaller half and repeat the search
            return binarySearch<T>(arr, mid+1, r, key);
    }

    //If list is exhausted without finding the value, then return -1 (sentinel value)
    return -1;
}
