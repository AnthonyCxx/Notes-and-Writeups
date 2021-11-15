//swap function
template <typename T>
void swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

//Bubble sort
template <typename T>
void bubbleSort(T array[], const std::size_t n)
{
    bool notSorted = true;

    //For each element in array
    for (std::size_t i = 0; i < n && notSorted; ++i)
    {
        //Set not sorted to false
        notSorted = false;

        //Loop over each element in the array from the beginning
        for (std::size_t j = 0; j < n-i-1; ++j)
        {
           //Checks if sorted, swaps if not
           if (array[j] > array[j+1])
           {
             notSorted = true;
             swap<T>(array[j], array[j+1]);
           }
        }
    }
}
