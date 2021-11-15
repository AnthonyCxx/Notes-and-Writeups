//Swap function
<typename T>
void swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

//Selection sort
template <typename T>
void selectionSort(T array[], const std::size_t n)
{
    std::size_t min;

    //For every element in the array
    for (std::size_t i = 0; i < n-1; ++i)
    {
        min = i;

        //Starting at the current index, iterate over the rest of the indices until the array is exhausted
        for (std::size_t j=i+1; j < n; ++j)
        {
            if (array[j] < array[min])
                min = j;
        }

        //Swap the current index with the smallest number found
        swap<T>(array[i], array[min]);
    }
}
