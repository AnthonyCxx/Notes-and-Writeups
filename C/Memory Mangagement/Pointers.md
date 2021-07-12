# Pointers in C
A pointer is a variable that points to some location in memory and are often used to keep track of [dynamically-allocated memory](https://www.programiz.com/c-programming/c-dynamic-memory-allocation). Like any variable, pointers are [strongly-typed](https://www.cs.cornell.edu/courses/cs1130/2012sp/1130selfpaced/module1/module1part4/strongtyping.html); however, they can also be [type-casted](https://ecomputernotes.com/what-is-c/function-a-pointer/type-casting-of-pointers) easily.

## Declaring a Pointer
Pointers are declared like a normal variable, but include a '\*' after the datatype. If not given a value, the pointer will point to [NULL](https://www.tutorialspoint.com/null-pointer-in-c).
```C
#include <stdio.h>

int main(void)
{
    // A pointer that can point to an integer
    int* ptr;     // 'ptr' is short for 'pointer'

    // Print what 'ptr' points to (NULL)
    printf("The memory address of 'ptr' is: %p\n", ptr);

    return 0;
}
```
> Prints: <br />
> The memory address of 'ptr' is: (nil)

## The & Operator
The [& operator](https://fresh2refresh.com/c-programming/c-interview-questions-answers/what-is-ampersand-and-star-operators-in-c/) yields the memory address of a variable.
The '&' operator can be used to assign pointers a value

```C

```

## Dereferencing (accessing) Pointers

```C

```

## Sources
JavaTPoint: [_C Pointers_](https://www.javatpoint.com/c-pointers) <br />
TutorialsPoint: [_C - Pointers_](https://www.tutorialspoint.com/cprogramming/c_pointers.htm) <br />
GeeksforGeeks: [_Void, Null, and Wild Pointers_](https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/) <br />
Programiz: [_C Pointers_](https://www.programiz.com/c-programming/c-pointers) <br />
Guru99: [_Pointers in C Programming: What is Pointer, Types & Examples_](https://www.guru99.com/c-pointers.html) <br />
BeginnersBook: [_Pointers in C Programming with examples_](https://beginnersbook.com/2014/01/c-pointers/) <br />
