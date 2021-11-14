/*
  Templated, Iterative Binary Search
  ==================================

  REQUIREMENTS: data is sorted

  Time Complexity: O(1)
  Space Complexity: O(log n)
*/

template <typename T>    //Array        size of the array,   search value
std::size_t binarySearch(const T arr[], const std::size_t n, const T key)
{
    //Initial points for left and right (and declaration of midpoint)
    std::size_t left = 0, mid, right = n-1;

    //Search loop (continues until list is exhausted)
    while (left <= right)   //<== Must be '<=' otherwise it will end before final step
    {
        //Calculate the midpoint of the array
        mid = (left + right) / 2;

        //Search value found?
        if (arr[mid] == key)
            return mid;       //Return the index of the key

        //Otherwise, cut in half and start over
        else if (key < arr[mid])   //Discards the greater half
            right = mid-1;

        else if (key > arr[mid])  //Discards the smaller half
            left = mid+1;
    }

    //If the list is exhausted without finding the value, then return -1 (sentinel value)
    return -1;
}
