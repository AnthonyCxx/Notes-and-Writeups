# Unions in C
Unions are a data structure that allows multiple variables to share the same space in memory (unlike a struct, in which the variables are independent of each other)

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

union test_union
{
    int i;
    float fl;
};

int main(void)
{
    union test_union nums;

    // Initialize int
    nums.i = 100;
    printf("Union int: %d\n", nums.i);

    // Initialize float
    nums.fl = 25.67;             // 'nums.i' is overwritten here
    printf("Union float: %f\n", nums.fl);
    printf("Union int: %d\n", nums.i);       // 'nums.i' is no longer 100

    return 0;
}
```

## Simplifying Union Usage with _typedef_
[link](https://www.tutorialspoint.com/cprogramming/c_typedef.htm)

## Sources
- [_GeeksforGeeks: Unions in C_](https://www.geeksforgeeks.org/union-c/)
- [_TutorialsPoint: C - Unions_](https://www.tutorialspoint.com/cprogramming/c_unions.htm)
- [_StackOverflow: Why Do We Need Unions in C?_](https://stackoverflow.com/questions/252552/why-do-we-need-c-unions)
- [_Jawaharlal Nehru Krishi Vishwavidyalaya (JNKVV) University Notes: Unions in C with Syntax and Examples_](http://www.jnkvv.org/PDF/25042020093559244201357.pdf)
