# A Collection of Bit Hacks from Various Sources
- https://www.youtube.com/watch?v=ZRNO-ewsNcQ&t=179s
- https://www.youtube.com/watch?v=ReTetN51r7A&t=513s

## Check for Opposite Signs
if `((x ^ y) < 0)`, then two integers have opposite signs.

```C++
if ((x ^ y) < 0)
        std::cout << "The numbers have OPPOSITE signs\n";
```
> Parentheses are needed around _x_ and _y_ because operator< has precedence over operator^ <br />
> [Credit](https://graphics.stanford.edu/~seander/bithacks.html)

## Conditionless Absolute Value
Takes the absolute value of an integer.
```C++
int num = -150;
const int mask = num >> sizeof(int)*8 - 1;
unsigned int absvalue = (num + mask) ^ mask;
std::cout << "The absolute value of " << num << " is " << absvalue << '\n';
```
> [Credit](https://graphics.stanford.edu/~seander/bithacks.html)

# Sources
- seander@cs.stanford.edu: [Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html)
