# Unions in C
Unions are a data structure that allows multiple variables to share the same space in memory (unlike a struct, in which the variables are independent of each other). Careful,
this means that using any variable in a union will overwrite (corrupt) the others.
The size of a union is always the size of the largest data member of the union. Unions are useful for saving memory by preventing the existance of extraneous variables
that a struct would otherwise maintain. [Codeforwin](https://codeforwin.org/) has a really good example of real-world applications of unions in a blog post of his:
[_Unions in C programming language, need and use_](https://codeforwin.org/2018/06/unions-in-c-programming-language-need-and-use.html). In his post, he talks about
how an [embedded system](https://en.wikipedia.org/wiki/Embedded_system) can use unions to store various systems of color codes (rgb, rgba) _without_ having to maintain 
the variables for each color system at once, allowing for better performance.

## Declaring a Union in C

### Format
```C
union union_name 
{ 
    variable_list 
};    
// ^ Notice the semi-colon. It's a datatype definition.
```

### Example
```C
#include <stdio.h>

// union definition
union test_union
{
    int i;      // i(nt)
    float fl;  // fl(oat)
};

// Driver Code
int main(void)
{
    union test_union nums;

    // Initialize int
    nums.i = 100;
    printf("Union int: %d\n\n", nums.i);

    // Initialize float
    nums.fl = 25.67;                          // 'nums.i' is overwritten here
    printf("Union float: %f\n", nums.fl);
    printf("Union int: %d\n", nums.i);      // 'nums.i' is no longer 100

    return 0;
}
```
> Prints: <br />
> Union int: 100 <br /> 
> 
> Union float: 25.670000 <br /> 
> Union int: 1103977513 <br />

## Simplifying Union Usage with _typedef_
The [_typedef_](https://www.tutorialspoint.com/cprogramming/c_typedef.htm) keyword allows you to write aliases for datatypes. Using _typedef_ lets you alias 
'union union_name' to the name of the union. That way, you don't have to write 'union' every time you declare or use the union.
```C
#include <stdio.h>

typedef union test_union
{
    int i;
    float fl;
} test_union;

int main(void)
{
    test_union nums;
    // ^ No 'union' prefix ('test_union' = 'union test_union')

    // Initialize int
    nums.i = 100;
    printf("Union int: %d\n\n", nums.i);

    // Initialize float
    nums.fl = 25.67;
    printf("Union float: %f\n", nums.fl);
    printf("Union int: %d\n", nums.i);

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

```C
#include <stdio.h>
#include <stdbool.h>

// Touchscreen
typedef struct Touchscreen
{
    int sensitivity;
    bool gesturesEnabled;

} Touchscreen;

// Mouse
typedef struct Mouse
{
    int sensitivity;
    bool middleClickEnabled;

} Mouse;

// SurfacePro (a kind of tablet)
typedef struct SurfacePro
{
    // Union, so 'touchscreen' and 'mouse' cannot co-exist.
    union   // Members of an anonymous union can be accessed directly, as if ther was no union
    {
        Touchscreen touchscreen;
        Mouse mouse;
    };

} SurfacePro;

// Driver code
int main(void)
{
    SurfacePro tablet = { .touchscreen = {5, false} };   // Sensitivity of 5, gestures disabled

    printf("Touchscreen sensitivity: %d\n", tablet.touchscreen.sensitivity);
    printf("Gestures are %s enabled\n", (tablet.touchscreen.gesturesEnabled ? "" : "not"));

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

P.S. If you don't understand the format `variable : int` then reference [this article](https://www.geeksforgeeks.org/bit-fields-c/) on bit fields.
```C++
#include <stdio.h>

typedef union float_cast
{
    float f;

    struct
    {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } parts;
} float_cast;

// DRIVER CODE //
int main(void)
{
  float_cast d1 = { .f = 0.15625 };
  printf("sign = %x\n", d1.parts.sign);
  printf("exponent = %x\n", d1.parts.exponent);
  printf("mantissa = %x\n", d1.parts.mantissa);
  
  return 0;
}
```


## Sources
- [_GeeksforGeeks: Unions in C_](https://www.geeksforgeeks.org/union-c/)
- [_TutorialsPoint: C - Unions_](https://www.tutorialspoint.com/cprogramming/c_unions.htm)
- [_StackOverflow: Why Do We Need Unions in C?_](https://stackoverflow.com/questions/252552/why-do-we-need-c-unions)
- [_Jawaharlal Nehru Krishi Vishwavidyalaya (JNKVV) University Notes: Unions in C with Syntax and Examples_](http://www.jnkvv.org/PDF/25042020093559244201357.pdf)
