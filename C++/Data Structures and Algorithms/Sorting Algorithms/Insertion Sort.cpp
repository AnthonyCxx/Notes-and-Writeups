//Insertion sort
template <typename T>
void insertionSort(T array[], const std::size_t n)
{
    T key;
    std::size_t iter;

    //For every element in the array (beyond the first)
    for (std::size_t i=1; i < n; ++i)
    {
        //Store the value of the current index in the key, and its predecessor in iter
        key = array[i];
        iter = i-1;

        //Move all the elements between the key and its spot back by 1
        while (key < array[iter] and iter >= 0)
        {
            array[iter + 1] = array[iter];
            --iter;
        }

        //Assign the extracted value (the key) to its spot
        array[iter + 1] = key;
    }
}
