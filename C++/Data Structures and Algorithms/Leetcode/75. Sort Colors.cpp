/*
  Given an array of numbers 0, 1, and 2, sort the array in-place without using any library functions.
  I chose heap sort for this problem because it is the fastest sorting algorithm (O(n log n)) that only uses O(1) memory. 
  Here stability is not relevant. 

  Heap sort implementation adapted from: https://www.geeksforgeeks.org/cpp-program-for-heap-sort/
*/

//Heapify :D!
void heapify(std::vector<int>& nums, int n, int i)
{
    int left  = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;

    if (left < n and nums[left] > nums[largest])
        largest = left;

    if (right < n and nums[right] > nums[largest])
        largest = right;

    if (largest != i) 
    {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}


//Call heapsort
void heapSort(std::vector<int>& nums)
{
    for (int i=nums.size()/2 - 1; i >= 0; --i)
    {
        heapify(nums, nums.size(), i);
    }

    for (int i=nums.size()-1; i >= 0; --i)
    {
        std::swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}


// DRIVER CODE //
void sortColors(std::vector<int>& nums) 
{
    heapSort(nums);
}
