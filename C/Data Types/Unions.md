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

## Sources
- [_GeeksforGeeks: Unions in C_](https://www.geeksforgeeks.org/union-c/)
- [_TutorialsPoint: C - Unions_](https://www.tutorialspoint.com/cprogramming/c_unions.htm)
- [_StackOverflow: Why Do We Need Unions in C?_](https://stackoverflow.com/questions/252552/why-do-we-need-c-unions)
- [_Jawaharlal Nehru Krishi Vishwavidyalaya (JNKVV) University Notes: Unions in C with Syntax and Examples_](http://www.jnkvv.org/PDF/25042020093559244201357.pdf)
