/*
  
*/

int maximumWealth(vector<vector<int>>& accounts) 
{
    int sum, max = 0;

    //For every account 
    for(std::size_t i=0; i < accounts.size(); ++i)
    {
        //Get the sum of the money in that account
        sum = std::accumulate(accounts[i].begin(), accounts[i].end(), 0);  // <== 0 needed as the initial value

        //If the sum is greater than the current max, it becomes the new max
        if (max < sum)
            max = sum; 
    }

    //Return the max
    return max;
}
