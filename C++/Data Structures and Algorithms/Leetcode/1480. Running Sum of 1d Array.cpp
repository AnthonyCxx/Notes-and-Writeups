/*
  Find the running sum of a one-dimensional array.
  -> Definition of a running sum: https://www2.microstrategy.com/producthelp/2019/FunctionsRef/Content/FuncRef/RunningSum.htm 
*/

vector<int> runningSum(vector<int>& nums) 
{
    std::vector<int> ans;
    int sum = 0;

    for(const int& num : nums)
    {
        sum += num;
        ans.push_back(sum);
    }

    return ans;
}
