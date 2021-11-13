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

    for(std::size_t i=0; i < n; ++i)
    {
        randomIndex = rand() % n;
        swap<T>(arr[i], arr[randomIndex]);
    }
}





//Unncessary function
template <typename T>
void printArray(T arr[], std::size_t n)
{
    for(std::size_t i=0; i < n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}






// DRIVER CODE //
int main()
{
    srand(time(NULL));

    int data[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printArray(data, 10);
    randomize(data, 10);

    std::cout << '\n';
    printArray(data, 10);

    return 0;
}
