//Swap function
template <typename T>
void swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

//Exchange sort
template <typename T>
void exchangeSort(T array[], const std::size_t n)
{
    bool notSorted = true;

    //For every element in the array
    for(std::size_t i=0; i < n-1 && notSorted; ++i)
    {
        notSorted = false;

        //Compare every element after it to the current element (i), swapping if needed
        for(std::size_t j=i+1; j < n; ++j)
        {
            if (array[i] > array[j])
            {
                swap<T>(array[i], array[j]);
                notSorted = true;
            }
        }
    }
}
