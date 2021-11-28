/*
  Write an efficient search for a sorted 2D matrix
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    //Standard left, right, and mid declarations
    int left = 0;
    int right = matrix.size()*matrix[0].size() - 1;
    int mid;   //Mid is technicallly optional with this approach, but it improves clarity.

    //Special declarations: 2-D specific
    const int indivLen = matrix[0].size();  //The size of an individual subarray
    int arr;                               //Stores the index of the array that 'mid' is a part of
    int idx;                              //Stores the index of the element in the arrar 'arr' that 'mid' is

    //Until you reach the final element
    while (left <= right)   //Must be '<=', or it skips the final element
    {
        mid = (left+right)/2;          //Calculate the midpoint
        arr = ceil(mid / indivLen);   //Use the midpoint to calculate the subarray it's stored in
        idx = mid % indivLen;        //Use the midpoint to calculate the subindex it's stored in

         //If we found the element, stop
        if (matrix[arr][idx] == target)
            return true;

        //Discards the greater half and repeat the search
        else if (target < matrix[arr][idx])
            right = mid-1;

      //Discards the smaller half and repeat the search
        else if (target > matrix[arr][idx])
            left = mid+1;
    }

    //If we have exhausted the list and not found the element, it's not there
    return false;
}
