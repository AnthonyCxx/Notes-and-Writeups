//O(n) runtime

#include <iostream>

//C libraries (for creating + seeding the RNG)
#include <cstdlib>
#include <time.h>

//Swap function
template <typename T>
void swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

//Randomizes an array using the Fisher and Yates (Knuth) shuffling algorithm
template <typename T>
void randomize(T arr[], std::size_t n)  //Array + its size
{
    //A random index to swap 'i' with
    std::size_t randomIndex;

     //For every item in the array (n)
    for(std::size_t i=0; i < n; ++i)
    {
        randomIndex = rand() % n;               //Generate a random index
        swap<T>(arr[i], arr[randomIndex]);     //Swap the the two indices
    }
}



// DRIVER CODE //
int main()
{
    srand(time(NULL));
    randomize(data, 10);

    return 0;
}
