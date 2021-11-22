/*
  Reverse a string using O(1) memory 
*/

/*
  Solution 1: std::reverse()
  ==========================
   The easiest (but also cheapest) way to solve this problem is just to call
   std::reverse() on the vector.
*/
std::reverse(s.begin(), s.end());


/*
  Solution 2: Basic for-loop
  =========================
  The other solution is to iterate over the vector
  element by element, until you have swapped half of 
  the elements with their counterpart.
*/
for(std::size_t i=0; i < s.size()/2; ++i)
{
    std::swap(s[i], s[s.size()-i-1]);
}
