/*
  Solution 1: Iterating 
  =======================
  Since the array is sorted, we can iterate over
  the elements in the array 
*/
int removeDuplicates(vector<int>& nums) 
{
    //Corner case: if there are no elements in the vector, then you should not return k+1
    if (!nums.size())
        return 0;

    //Iterator 
    std::size_t k = 0;

    //Iterate over the entire vector, adding the new element every time it's encountered
    for(std::size_t i=0; i < nums.size(); i++)
    {
        if (nums[i] != nums[k])
        {
            k++; 
            nums[k] = nums[i];
        }
    }

    return k+1;
}


/*
  Solution 2: Using std::unique() and iteration arithmetic
  ===================================================
  ...
  
  Credit for this solution foes to https://leetcode.com/tuminskiy/
*/
int removeDuplicates(vector<int>& nums) 
{
  
  const auto it = unique(begin(nums), end(nums));
  return static_cast<int>(it - begin(nums));
}
