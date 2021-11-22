# A Collection of Bit Hacks from Various Sources
Not all of these are useful. Some are just kinda cool.
- https://www.youtube.com/watch?v=ZRNO-ewsNcQ&t=179s
- https://www.youtube.com/watch?v=ReTetN51r7A&t=513s

# Check for Opposite Signs
If true, then two integers have opposite signs.

```C++
if ((x ^ y) < 0)
        std::cout << "The numbers have OPPOSITE signs\n";
```
> Parentheses are needed around _x_ and _y_ because operator< has precedence over operator^ <br />
> [Credit](https://graphics.stanford.edu/~seander/bithacks.html)

# Check if Power of 2
**WARNING**: only works for positive numbers.
```C++
int x = 64;
if (x && !(x & (x - 1)))
   std::cout << "The number " << x << " is a power of 2\n";
```
> [Credit](https://graphics.stanford.edu/~seander/bithacks.html)

# Conditionless Absolute Value
Takes the absolute value of an integer.
```C++
int num = -150;
const int mask = num >> sizeof(int)*8 - 1;
unsigned int absvalue = (num + mask) ^ mask;
std::cout << "The absolute value of " << num << " is " << absvalue << '\n';
```
> [Credit](https://graphics.stanford.edu/~seander/bithacks.html)

# Conditionless Minimum and Maximum
```C++
int x = 10, y = 20;

int min = y ^ ((x ^ y) & -(x < y));
std::cout << "The min of the two numbers is: " << min << '\n';

int max = x ^ ((x ^ y) & -(x < y));
std::cout << "The max of the two numbers is: " << max << '\n';
```
> [Credit](https://graphics.stanford.edu/~seander/bithacks.html)

# Count Set Bits

```C++

```

# Sources
- seander@cs.stanford.edu: [Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html)
