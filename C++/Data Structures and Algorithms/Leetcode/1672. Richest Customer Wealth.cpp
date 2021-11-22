/*
  Given a vector of people where each member has a vector of money in 
  various accounts, return the wealth of the richest person.
*/

int maximumWealth(vector<vector<int>>& accounts) 
{
    int temp, max = 0;

    for(const vector<int>& acc : accounts)
    {
        //Find the sum of the values in the array
        temp = std::accumulate(acc.begin(), acc.end(), 0);

        if (max < temp)
            max = temp; 
    }

    return max;
}
