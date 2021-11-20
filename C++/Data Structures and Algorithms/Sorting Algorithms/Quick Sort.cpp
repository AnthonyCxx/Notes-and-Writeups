template <typename T>
void swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

//Partition: declare a pivot point and put all smaller values before it and all larger values after it
template <typename T>
void partition(T array[], const std::size_t low, const std::size_t high, std::size_t& pivotpoint)
{
    //Pivotitem = given element, j = given index
    T pivotitem = array[low];
    std::size_t j = low;

    //Iterate over all the following elements
    for(std::size_t i=low+1; i <= high; i++)
    {
        //If the current element is less than the pivotitem
        if (array[i] < pivotitem)
        {
            //Increment j and swap the elements
            j++;
            swap<T>(array[i], array[j]);
        }
    }

    //Move pivotitem to pivotpoint
    pivotpoint = j;
    swap<T>(array[low], array[pivotpoint]);
}


//Quicksort
template <typename T>
void quickSort(T array[], const std::size_t low, const std::size_t high)
{
    std::size_t pivotpoint;

    if (low < high)  //Stop sorting
    {
        //Sort the array into left and right halves
        partition<T>(array, low, high, pivotpoint);

        //Sort the left half
        quickSort<T>(array, low, pivotpoint-1);

        //Sort the right half
        quickSort<T>(array, pivotpoint+1, high);
    }
}
