/*
  Given a vector of people where each member has a vector of money in various accounts,
  find the richest person.
*/

int maximumWealth(vector<vector<int>>& accounts) 
{
    int temp, max = 0;

    for(const vector<int>& acc : accounts)
    {
        temp = std::accumulate(acc.begin(), acc.end(), 0);

        if (max < temp)
            max = temp; 
    }

    return max;
}
