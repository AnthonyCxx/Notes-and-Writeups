/*
  Given a vector 'nums', return a vector that contains the array
*/

/*
  Solution 1: Use a For-loop
  ==========================
  You can use a for-loop to copy all the elements
  into a new vector. If you use modulus, the index
  will return to the beginning of the array once you
  exceed the max value of the array.
*/
vector<int> getConcatenation(vector<int>& nums) 
{
    vector<int> ans;
    ans.reserve(nums.size()*2);

    for(int i=0; i < nums.size()*2; ++i)
    {
        ans.push_back(nums[i % nums.size()]);
    }

    return ans;
}

/*
  Solution 2: Use a std::vector.insert()
  ======================================
  Vectors have a method '.insert()' that "inserts a series 
  of elements at the specified location in the container."
  If you append the values of the vector to itself, you can
  get the concatenation without having to create a new array.
  
  Credit: https://leetcode.com/yoksyokesh/
*/

vector<int> getConcatenation(vector<int> &nums)
{
    nums.insert(nums.end(), nums.begin(), nums.end());
    return nums;
}
