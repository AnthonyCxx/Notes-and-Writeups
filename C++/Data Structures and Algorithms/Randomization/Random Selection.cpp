//A simple random selection algorithm using MT19937 (C++'s implementation of the Mersenne Twister algorithm)

T randomElement(T arr[], std::size_t n)
{
    //Create and seed a random number generator (Mersenne Twister)
    static std::random_device rd;
    static std::mt19937 RNG(rd());            
    
    //Apply distribution (0 - n-1), inclusive
    std::uniform_int_distribution<int> dist(0, n-1);

    //Return a random element using the applied distribution
    return arr[dist(RNG)];
}



// DRIVER CODE //

int main()
{
    int arr[10] {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << randomElement(arr, 10) << '\n';

    return 0;
}
