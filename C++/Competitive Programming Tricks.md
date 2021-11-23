# Competitive Programming Tricks
A collection of clever optimizations/hacks that will give you an edge in a competition. <br />
A lot of these work regardless of language.

## Determining Parity
The parity of a number (whether it is even or odd) can be quickly determined using the bitwise AND operator (&). <br />
Any odd number `& 1` is 1 (true) and any even number `& 1` is 0 (false). 

```C++
int num = 65535;

if (num & 1)  //True
    cout << "The number is odd\n";
```

## Fast Multiplication/Division
You can shift the bits of a number with the _<<_ and _>>_ bitshift operators to perform fast multiplication and divsion with powers of 2. <br />
A number `<< n` is the equivalent of multiplying that number by _2^n_. The same goes for division with the _>>_ operator.

```C++
//Multiplication
cout << (12 << 1) << '\n';   // 12 * (2^1) == 24
cout << (12 << 3) << '\n';  //  12 * (2^3) == 94  
    
//Division
cout << (12 >> 1) << '\n';  // 12 / (2^1) == 6
cout << (12 >> 2) << '\n'; //  12 / (2^2) == 3
```

## Translating a Single Numeric Character to a Number
0 is the first numeric character on the ASCII table, so you can turn numeric characters into their respective integer values by subtracting 0 from them and casting them
to an integer.

```C++
cout << "The characters 1 + 2 = " << static_cast<int>('1' - '0') + static_cast<int>('2' - '0') << '\n';
```
> Format: `static_cast<int>(num - '0')`

## Finding the last digit of a number 
Modding any number by 10 yields the digit it ends in.

```C++
cout << "The last digit in 102 is " << 102 % 10 << '\n';
```

## Find the Amount of Digits in a Positive Number
```C+=
unsigned int countDigits(unsigned int num)
{
    return log10(num) + 1;
}
```

## Bit Hacks
[https://www.youtube.com/watch?v=ZRNO-ewsNcQ](https://www.youtube.com/watch?v=ZRNO-ewsNcQ)
