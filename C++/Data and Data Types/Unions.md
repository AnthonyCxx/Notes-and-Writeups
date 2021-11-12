# Unions in C++
Unions are a user-defined type that allows multiple variables to share the same space in memory (unlike a struct, in which the variables are independent of each other). 
Careful, this means that using any variable in a union will overwrite (corrupt) the others.
The size of a union is always the size of the largest data member of the union. Unions are useful for saving memory by preventing the existance of extraneous variables
that a struct would otherwise maintain. [Codeforwin](https://codeforwin.org/) has a really good example of real-world applications of unions in a blog post of his:
[_Unions in C programming language, need and use_](https://codeforwin.org/2018/06/unions-in-c-programming-language-need-and-use.html). In his post, he talks about
how an [embedded system](https://en.wikipedia.org/wiki/Embedded_system) can use unions to store various systems of color codes (rgb, rgba) _without_ having to maintain 
the variables for each color system at once, allowing for better performance.

## Declaring a Union 

### Format
```C++
union union_name 
{ 
    variable_list 
};    
// ^ Notice the semi-colon. It's a datatype definition.
```

### Example
```C++
#include <iostream>
using namespace std;

// union definition
union test_union
{
    int i;      // i(nt)
    float fl;  // fl(oat)
};


// Driver Code //
int main(void)
{
    test_union nums;

    // Initialize int
    nums.i = 100;
    cout << "Union int: " << nums.i << "\n\n";

    // Initialize float
    nums.fl = 25.67;                                // 'nums.i' is overwritten here
    cout << "Union float: " << nums.fl << '\n';
    cout << "Union int: " << nums.i << '\n';      // 'nums.i' is no longer 100

    return 0;
}
```
> Prints: <br />
> Union int: 100 <br /> 
> 
> Union float: 25.670000 <br /> 
> Union int: 1103977513 <br />

## An Example of Unions
Here, a surface pro (a kind of tablet) has the choice to either use the touchscreen or a mouse as the source of input - the union saves memory by only reserving enough
memory for one struct (touchscreen/mouse) at a time. Although this example is not accurate (a real computer would be able to use both at the same time), it does
serve to illustrate function of unions and how to use them.

```C++
#include <iostream>
using namespace std;

// Touchscreen
struct Touchscreen
{
    int sensitivity;
    bool gesturesEnabled;

};

// Mouse
struct Mouse
{
    int sensitivity;
    bool middleClickEnabled;

};

// SurfacePro (a kind of tablet)
struct SurfacePro
{
    // Union, so 'touchscreen' and 'mouse' cannot co-exist.
    union   // Members of an anonymous union can be accessed directly, as if ther was no union
    {
        Touchscreen touchscreen;
        Mouse mouse;
    };

};

// Driver code //
int main()
{
    SurfacePro tablet = { .touchscreen = {5, false} };   // Sensitivity of 5, gestures disabled

    cout << "Touchscreen sensitivity: " << tablet.touchscreen.sensitivity << '\n';
    cout << "Gestures are " << (tablet.touchscreen.gesturesEnabled ? "" : "not") << " enabled\n";

    return 0;
}
```
> Prints: <br />
> Touchscreen sensitivity: 5 <br />
> Gestures are not enabled <br />

## Real-world Example
I found this cracked example of unions on [a StackOverflow question](https://stackoverflow.com/questions/15685181/how-to-get-the-sign-mantissa-and-exponent-of-a-floating-point-number)
that I stumbled across that allows you to individually access the sign, mantissa, and exponent of a floating-point number. This is only possible because the struct
shares the same space in memory as the float. <br />
For a better explanation, look here: [_Wikipedia: Single-precision floating-point format_](https://en.wikipedia.org/wiki/Single-precision_floating-point_format).

P.S. If you don't understand the format `variable : int` then reference [this article](https://docs.microsoft.com/en-us/cpp/cpp/cpp-bit-fields?view=msvc-160) on bit fields.
```C++
#include <iostream>

union float_cast
{
    float f;

    struct
    {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } parts;
};

// DRIVER CODE //
int main()
{
  float_cast d1 = { .f = 0.15625 };
  printf("sign = %x\n", d1.parts.sign);
  printf("exponent = %x\n", d1.parts.exponent);
  printf("mantissa = %x\n", d1.parts.mantissa);
  
  return 0;
}
```

## Named Array Indices
Using a union with variables and an array of the same type will allow you to refer to either the array by index or the individual variable. This is because of how
memory lines up in the computer.

The following example is from Miro Knejp's [CppCon 2019: Non-conforming C++](https://www.youtube.com/watch?v=IAdLwUXRUvg).
```C++
union vec4
{
    float array[4];

    struct
    {
        float a, b, c, d;
    };
};

int main()
{
    auto v = vec4{};
    v.a = 5;
    v.b = 6;

    cout << v.array[0] << '\n';   // == 5 (v.a)
    cout << v.array[1] << '\n';  //  == 6 (v.b)

    return 0;
}
```
