# A Collection of Bit Hacks from Various Sources


## Check for Opposite Signs
if `((x ^ y) < 0)`, then two integers have opposite signs.

```C++
if ((x ^ y) < 0)
        std::cout << "The numbers have OPPOSITE signs\n";
```
> Parentheses are needed around _x_ and _y_ because operator< has precedence over operator^

# Sources
- seander@cs.stanford.edu: [Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html)
